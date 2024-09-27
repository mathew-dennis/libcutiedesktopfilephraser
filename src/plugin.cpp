#include "plugin.h"

void CutieDesktopfilephraserPlugin::registerTypes(const char *uri)
{
	qmlRegisterSingletonType<CutieDesktopfilephraser>(
		uri, 1, 0, "Cutiedesktopfilephraser",
		&CutieDesktopfilephraser::provider);
	qmlRegisterType<CutieDesktopfilephraser>(uri, 1, 0, "CutieDesktopfilephraser");
}
