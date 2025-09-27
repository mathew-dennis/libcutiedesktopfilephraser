#include "plugin.h"

void CutieDesktopFileparserPlugin::registerTypes(const char *uri)
{
    qmlRegisterSingletonType<CutieDesktopFileparser>(
        uri, 1, 0, "CutieDesktopFileparser",
        &CutieDesktopFileparser::provider);
}
