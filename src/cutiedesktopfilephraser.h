#pragma once

#include <QObject>
#include <QVariant>
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QQmlEngine>
#include <QJSEngine>

class CutieDesktopFilePhraser : public QObject {
    Q_OBJECT

public:
    explicit CutieDesktopFilePhraser(QObject *parent = nullptr);
    ~CutieDesktopFilePhraser();

    // Fetches all entries in a given directory
    Q_INVOKABLE QVariantList fetchAllEntries() const;

    static CutieDesktopFilePhraser *instance();
    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    Q_DISABLE_COPY(CutieDesktopFilePhraser)
};