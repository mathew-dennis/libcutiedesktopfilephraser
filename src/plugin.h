#pragma once
#include <QDebug>
#include <QtQuick>
#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>

#include "cutiedesktopfilephraser.h"

class CutiedesktopfilephraserPlugin : public QQmlExtensionPlugin {
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid FILE
			  "cutiedesktopfilephraser.json")
    public:
	explicit CutiedesktopfilephraserPlugin()
	{
	}

	void registerTypes(const char *uri) override;
};