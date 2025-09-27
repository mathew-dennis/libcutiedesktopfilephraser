#pragma once
#include <QDebug>
#include <QtQuick>
#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>

#include "cutiedesktopfileparser.h"

class CutieDesktopFileparserPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid FILE
                      "cutiedesktopfileparser.json")

public:
    explicit CutieDesktopFileparserPlugin() {}

    void registerTypes(const char *uri) override;
};