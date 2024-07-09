#include "plugin.h"

void CutiePhonenumberPlugin::registerTypes(const char *uri)
{
	qmlRegisterSingletonType<CutiePhonenumberHelper>(
		uri, 1, 0, "CutiePhonenumberHelper",
		&CutiePhonenumberHelper::provider);
	qmlRegisterType<CutiePhonenumber>(uri, 1, 0, "CutiePhonenumber");
}
