#include "cutiedesktopfileparser.h"
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QStandardPaths>
#include <QDebug>

// ------------------- CutieDesktopFileParser -------------------
CutieDesktopFileParser::CutieDesktopFileParser(QObject *parent)
    : QObject(parent)
{
    qDebug() << "module - CutieDesktopFileParser : loaded.";
}

CutieDesktopFileParser::~CutieDesktopFileParser() {}

// Returns a new DesktopEntryModel populated with entries from the given paths
DesktopEntryModel* CutieDesktopFileParser::fetchAllEntriesModel(const QStringList &paths) const {
    auto *model = new DesktopEntryModel(const_cast<CutieDesktopFileParser*>(this));
    QList<QVariantMap> entries;

    qDebug() << "module - CutieDesktopFileParser - fetchAllEntriesModel() : called";

    QStringList dataDirList = paths.isEmpty()
        ? QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation)
        : paths;
    qDebug() << "module - CutieDesktopFileParser - fetchAllEntriesModel() : Application directories =" << dataDirList;

    for (const QString &directory : dataDirList) {
        QDir dir(directory);
        if (!dir.exists()) continue;

        QFileInfoList files = dir.entryInfoList(QStringList{"*.desktop"}, QDir::Files);
        for (const QFileInfo &fileInfo : files) {
            QSettings desktopFile(fileInfo.absoluteFilePath(), QSettings::IniFormat);
            QString type = desktopFile.value("Desktop Entry/Type").toString();
            if (type != "Application") continue;

            QString hidden = desktopFile.value("Desktop Entry/Hidden").toString();
            QString noDisplay = desktopFile.value("Desktop Entry/NoDisplay").toString();
            if (hidden == "true" || noDisplay == "true") continue;

            QVariantMap appData;
            for (const QString &key : desktopFile.allKeys())
                appData.insert(key, desktopFile.value(key));

            entries.append(appData);
        }
    }

    qDebug() << "module - CutieDesktopFileParser - fetchAllEntriesModel() : number of entries found =" << entries.size();
    model->setEntries(entries);
    return model;
}

// Singleton instance
CutieDesktopFileParser* CutieDesktopFileParser::instance() {
    static CutieDesktopFileParser instance;
    return &instance;
}

// QQmlEngine provider
QObject* CutieDesktopFileParser::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return CutieDesktopFileParser::instance();
}