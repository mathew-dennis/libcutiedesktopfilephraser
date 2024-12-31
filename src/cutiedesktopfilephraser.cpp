#include "cutiedesktopfilephraser_p.h"
#include <QSettings>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>
#include <QTextStream>
#include <QDebug>

CutieDesktopFilePhraser::CutieDesktopFilePhraser(QObject *parent)
    : QObject(parent) 
{
    qDebug() << "CutieDesktopFilePhraser module loaded."; 
    d_ptr = new CutieDesktopFilePhraserPrivate(this); 
}

CutieDesktopFilePhraser::~CutieDesktopFilePhraser() {
    delete d_ptr;
}

CutieDesktopFilePhraserPrivate::CutieDesktopFilePhraserPrivate(CutieDesktopFilePhraser *q) : q_ptr(q) {
    // Constructor implementation
}

QVariantList CutieDesktopFilePhraser::fetchAllEntries() const {
    qDebug() << "App Details loading stage 3: fetchAllEntries() called, fetching entries from standard locations...";
    QVariantList entries;

    // Get standard application locations
    QStringList dataDirList = QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation);
    qDebug() << "Application directories:" << dataDirList;

    for (const QString &directory : dataDirList) {
        QDir dir(directory);
        if (dir.exists()) {
            QStringList filters;
            filters << "*.desktop";
            QFileInfoList files = dir.entryInfoList(filters, QDir::Files);

            for (const QFileInfo &fileInfo : files) {
                QSettings desktopFile(fileInfo.absoluteFilePath(), QSettings::IniFormat);
                QString desktopType = desktopFile.value("Desktop Entry/Type").toString();

                if (desktopType == "Application") {
                    QVariantMap appData;
                    QStringList keys = desktopFile.allKeys();
                    for (const QString &key : keys) {
                        appData.insert(key, desktopFile.value(key));
                    }

                    QString appHidden = desktopFile.value("Desktop Entry/Hidden").toString();
                    QString appNoDisplay = desktopFile.value("Desktop Entry/NoDisplay").toString();

                    if (appHidden != "true" && appNoDisplay != "true") {
                        entries.append(appData);
                    }
                }
            }
        }
    }
    return entries;
}

QVariantMap CutieDesktopFilePhraser::fetchEntry(const QString &filePath) const {
    QSettings desktopFile(filePath, QSettings::IniFormat);
    QVariantMap entry;
    for (const QString &key : desktopFile.allKeys()) {
        entry.insert(key, desktopFile.value(key));
    }
    return entry;
}

CutieDesktopFilePhraser *CutieDesktopFilePhraser::instance() {
    static CutieDesktopFilePhraser instance;
    return &instance;
}

QObject *CutieDesktopFilePhraser::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return CutieDesktopFilePhraser::instance();
}