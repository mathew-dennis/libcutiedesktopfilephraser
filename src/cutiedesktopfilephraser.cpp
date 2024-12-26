#include "cutiedesktopfilephraser_p.h"
#include <QSettings>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>

CutieDesktopFilePhraser::CutieDesktopFilePhraser(QObject *parent)
    : QObject(parent), d_ptr(new CutieDesktopFilePhraserPrivate(this)) {}

CutieDesktopFilePhraser::~CutieDesktopFilePhraser() {
    delete d_ptr;
}

QVariantList CutieDesktopFilePhraser::fetchAllEntries() const {
    qDebug() << "fetchAllEntries() called, returning fake data...";

    QVariantList entries;

    // Add some fake application entries
    QVariantMap app1;
    app1["Name"] = "Fake App 1";
    app1["Exec"] = "/usr/bin/fakeapp1";
    app1["Icon"] = "fakeapp1-icon";
    app1["Type"] = "Application";

    QVariantMap app2;
    app2["Name"] = "Fake App 2";
    app2["Exec"] = "/usr/bin/fakeapp2";
    app2["Icon"] = "fakeapp2-icon";
    app2["Type"] = "Application";

    QVariantMap app3;
    app3["Name"] = "Fake App 3";
    app3["Exec"] = "/usr/bin/fakeapp3";
    app3["Icon"] = "fakeapp3-icon";
    app3["Type"] = "Application";

    // Add the fake entries to the list
    entries.append(app1);
    entries.append(app2);
    entries.append(app3);

    qDebug() << "Fake data prepared, returning:" << entries;

    return entries;
}

QVariantMap CutieDesktopFilePhraser::fetchEntry(const QString &filePath) const {
    qDebug() << "fetchEntry() called with filePath:" << filePath;

    // Return a fake single entry to simulate the function
    QVariantMap entry;
    entry["Name"] = "Single Fake App";
    entry["Exec"] = "/usr/bin/singlefakeapp";
    entry["Icon"] = "singlefakeapp-icon";
    entry["Type"] = "Application";

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
