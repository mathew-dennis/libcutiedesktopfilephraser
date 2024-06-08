#pragma once
#include "cutiephonenumber.h"
#include <phonenumbers/phonenumberutil.h>

class CutiePhonenumberHelperPrivate : public QObject {
	Q_OBJECT
	Q_DECLARE_PUBLIC(CutiePhonenumberHelper)
	friend class CutiePhonenumber;

    public:
	CutiePhonenumberHelperPrivate(CutiePhonenumberHelper *q);
	~CutiePhonenumberHelperPrivate();

    protected:
	static i18n::phonenumbers::PhoneNumberUtil *m_phoneNumberUtil;
	static QMap<int, QString> m_countryCodes;

    private:
	CutiePhonenumberHelper *q_ptr;

	static CutiePhonenumberHelper *m_instance;
};

class CutiePhonenumberPrivate : public QObject {
	Q_OBJECT
	Q_DECLARE_PUBLIC(CutiePhonenumber)

    public:
	CutiePhonenumberPrivate(CutiePhonenumber *q);
	~CutiePhonenumberPrivate();

	static i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat
	toLibFormat(CutiePhonenumber::PhoneNumberFormat format);
	static CutiePhonenumber::PhoneNumberFormat toOurFormat(
		i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat format);

    protected:
	i18n::phonenumbers::PhoneNumber m_phoneNumber;

    private:
	CutiePhonenumber *q_ptr;
};
