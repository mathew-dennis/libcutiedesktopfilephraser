#include "plugin.h"

void CutieDesktopFilePhraserPlugin::registerTypes(const char *uri)
{
    qmlRegisterSingletonType<CutieDesktopFilePhraser>(
        uri, 1, 0, "CutieDesktopFilePhraser",
        &CutieDesktopFilePhraser::provider);
}
