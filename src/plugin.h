#pragma once
#include <QDebug>
#include <QtQuick>
#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>

#include "cutiedesktopfilephraser.h"

class CutieDesktopFilePhraserPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid FILE
                      "cutiedesktopfilephraser.json")

public:
    explicit CutieDesktopFilePhraserPlugin() {}

    void registerTypes(const char *uri) override;
};