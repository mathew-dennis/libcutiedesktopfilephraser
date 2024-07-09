#pragma once
#include <QDebug>
#include <QtQuick>
#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>

#include "cutiephonenumber.h"

class CutiePhonenumberPlugin : public QQmlExtensionPlugin {
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid FILE
			  "cutiephonenumber.json")
    public:
	explicit CutiePhonenumberPlugin()
	{
	}

	void registerTypes(const char *uri) override;
};