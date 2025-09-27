#include "plugin.h"

void CutieDesktopFileParserPlugin::registerTypes(const char *uri)
{
    qmlRegisterSingletonType<CutieDesktopFileParser>(
        uri, 1, 0, "CutieDesktopFileParser",
        &CutieDesktopFileParser::provider);
}
