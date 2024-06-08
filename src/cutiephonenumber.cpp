#include "cutiephonenumber_p.h"

CutiePhonenumberHelper *CutiePhonenumberHelperPrivate::m_instance = nullptr;
i18n::phonenumbers::PhoneNumberUtil
	*CutiePhonenumberHelperPrivate::m_phoneNumberUtil =
		i18n::phonenumbers::PhoneNumberUtil::GetInstance();
QMap<int, QString> CutiePhonenumberHelperPrivate::m_countryCodes = {
	{ 202, "GR" }, { 204, "NL" }, { 206, "BE" }, { 208, "FR" },
	{ 212, "MC" }, { 213, "AD" }, { 214, "ES" }, { 216, "HU" },
	{ 218, "BA" }, { 219, "HR" }, { 220, "RS" }, { 221, "XK" },
	{ 222, "IT" }, { 225, "VA" }, { 226, "RO" }, { 228, "CH" },
	{ 230, "CZ" }, { 231, "SK" }, { 232, "AT" }, { 234, "GB" },
	{ 235, "GB" }, { 238, "DK" }, { 240, "SE" }, { 242, "NO" },
	{ 244, "FI" }, { 246, "LT" }, { 247, "LV" }, { 248, "EE" },
	{ 250, "RU" }, { 255, "UA" }, { 257, "BY" }, { 259, "MD" },
	{ 260, "PL" }, { 262, "DE" }, { 266, "GI" }, { 268, "PT" },
	{ 270, "LU" }, { 272, "IE" }, { 274, "IS" }, { 276, "AL" },
	{ 278, "MT" }, { 280, "CY" }, { 282, "GE" }, { 283, "AM" },
	{ 284, "BG" }, { 286, "TR" }, { 288, "FO" }, { 290, "GL" },
	{ 292, "SM" }, { 293, "SI" }, { 294, "MK" }, { 295, "LI" },
	{ 297, "ME" }, { 302, "CA" }, { 308, "PM" }, { 310, "US" },
	{ 311, "US" }, { 312, "US" }, { 313, "US" }, { 314, "US" },
	{ 315, "US" }, { 316, "US" }, { 330, "PR" }, { 332, "VI" },
	{ 334, "MX" }, { 338, "JM" }, { 340, "GP" }, { 340, "MQ" },
	{ 342, "BB" }, { 344, "AG" }, { 346, "KY" }, { 348, "VG" },
	{ 350, "BM" }, { 352, "GD" }, { 354, "MS" }, { 356, "KN" },
	{ 358, "LC" }, { 360, "VC" }, { 362, "CW" }, { 363, "AW" },
	{ 364, "BS" }, { 365, "AI" }, { 366, "DM" }, { 368, "CU" },
	{ 370, "DO" }, { 372, "HT" }, { 374, "TT" }, { 376, "TC" },
	{ 400, "AZ" }, { 401, "KZ" }, { 402, "BT" }, { 404, "IN" },
	{ 405, "IN" }, { 406, "IN" }, { 410, "PK" }, { 412, "AF" },
	{ 413, "LK" }, { 414, "MM" }, { 415, "LB" }, { 416, "JO" },
	{ 417, "SY" }, { 418, "IQ" }, { 419, "KW" }, { 420, "SA" },
	{ 421, "YE" }, { 422, "OM" }, { 424, "AE" }, { 425, "IL" },
	{ 426, "BH" }, { 427, "QA" }, { 428, "MN" }, { 429, "NP" },
	{ 430, "AE" }, { 431, "AE" }, { 432, "IR" }, { 434, "UZ" },
	{ 436, "TJ" }, { 437, "KG" }, { 438, "TM" }, { 440, "JP" },
	{ 441, "JP" }, { 450, "KP" }, { 452, "VN" }, { 454, "HK" },
	{ 455, "MO" }, { 456, "KH" }, { 457, "LA" }, { 460, "CN" },
	{ 461, "CN" }, { 466, "TW" }, { 467, "KR" }, { 470, "BD" },
	{ 472, "MV" }, { 502, "MY" }, { 505, "AU" }, { 510, "ID" },
	{ 514, "TL" }, { 515, "PH" }, { 520, "TH" }, { 525, "SG" },
	{ 528, "BN" }, { 530, "NZ" }, { 536, "NR" }, { 537, "PG" },
	{ 539, "TO" }, { 540, "SB" }, { 541, "VU" }, { 542, "FJ" },
	{ 543, "WF" }, { 544, "AS" }, { 545, "KI" }, { 546, "NC" },
	{ 547, "PF" }, { 548, "CK" }, { 549, "AS" }, { 550, "FM" },
	{ 551, "MH" }, { 552, "PW" }, { 553, "TV" }, { 554, "TK" },
	{ 555, "NU" }, { 602, "EG" }, { 603, "DZ" }, { 604, "MA" },
	{ 605, "TN" }, { 606, "LY" }, { 607, "GM" }, { 608, "SN" },
	{ 609, "MR" }, { 610, "ML" }, { 611, "GN" }, { 612, "CI" },
	{ 613, "BF" }, { 614, "NE" }, { 615, "TG" }, { 616, "BJ" },
	{ 617, "MU" }, { 618, "LR" }, { 619, "SL" }, { 620, "GH" },
	{ 621, "NG" }, { 622, "TD" }, { 623, "CF" }, { 624, "CM" },
	{ 625, "CV" }, { 626, "ST" }, { 627, "GQ" }, { 628, "GA" },
	{ 629, "CG" }, { 630, "CD" }, { 631, "AO" }, { 632, "GW" },
	{ 633, "SC" }, { 634, "SD" }, { 635, "RW" }, { 636, "ET" },
	{ 637, "SO" }, { 638, "DJ" }, { 639, "KE" }, { 640, "TZ" },
	{ 641, "UG" }, { 642, "BI" }, { 643, "MZ" }, { 645, "ZM" },
	{ 646, "MG" }, { 647, "RE" }, { 648, "ZW" }, { 649, "NA" },
	{ 650, "MW" }, { 651, "LS" }, { 652, "BW" }, { 653, "SZ" },
	{ 654, "KM" }, { 655, "ZA" }, { 657, "ER" }, { 658, "SH" },
	{ 659, "SS" }, { 702, "BZ" }, { 704, "GT" }, { 706, "SV" },
	{ 708, "HN" }, { 710, "NI" }, { 712, "CR" }, { 714, "PA" },
	{ 716, "PE" }, { 722, "AR" }, { 724, "BR" }, { 730, "CL" },
	{ 732, "CO" }, { 734, "VE" }, { 736, "BO" }, { 738, "GY" },
	{ 740, "EC" }, { 742, "GF" }, { 744, "PY" }, { 746, "SR" },
	{ 748, "UY" }, { 750, "FK" },
};

CutiePhonenumberHelper::CutiePhonenumberHelper(QObject *parent)
	: QObject(parent)
	, d_ptr(new CutiePhonenumberHelperPrivate(this))
{
}

CutiePhonenumberHelper::~CutiePhonenumberHelper()
{
}

int CutiePhonenumberHelper::MCCtoCountryCode(const QString &mcc) const
{
	QString ISO =
		CutiePhonenumberHelperPrivate::m_countryCodes[mcc.toInt()];
	return CutiePhonenumberHelperPrivate::m_phoneNumberUtil
		->GetCountryCodeForRegion(ISO.toStdString());
}

int CutiePhonenumberHelper::ISOToCountryCode(const QString &ISO) const
{
	return CutiePhonenumberHelperPrivate::m_phoneNumberUtil
		->GetCountryCodeForRegion(ISO.toStdString());
}

QString CutiePhonenumberHelper::MCCtoISO(const QString &mcc) const
{
	return CutiePhonenumberHelperPrivate::m_countryCodes[mcc.toInt()];
}

QString CutiePhonenumberHelper::CountryCodeToISO(const int countryCode) const
{
	std::string ISO;
	CutiePhonenumberHelperPrivate::m_phoneNumberUtil
		->GetRegionCodeForCountryCode(countryCode, &ISO);
	return QString::fromStdString(ISO);
}

CutiePhonenumber *
CutiePhonenumberHelper::createPhonenumber(const QString &number,
					  const QString &ISO) const
{
	return new CutiePhonenumber(number, ISO);
}

CutiePhonenumberHelper *CutiePhonenumberHelper::instance()
{
	if (!CutiePhonenumberHelperPrivate::m_instance)
		CutiePhonenumberHelperPrivate::m_instance =
			new CutiePhonenumberHelper();
	return CutiePhonenumberHelperPrivate::m_instance;
}

QObject *CutiePhonenumberHelper::provider(QQmlEngine *engine,
					  QJSEngine *scriptEngine)
{
	Q_UNUSED(engine)
	Q_UNUSED(scriptEngine)
	return CutiePhonenumberHelper::instance();
}

CutiePhonenumberHelperPrivate::CutiePhonenumberHelperPrivate(
	CutiePhonenumberHelper *q)
	: q_ptr(q)
{
}

CutiePhonenumberHelperPrivate::~CutiePhonenumberHelperPrivate()
{
}

CutiePhonenumber::CutiePhonenumber(QObject *parent)
	: QObject(parent)
	, d_ptr(new CutiePhonenumberPrivate(this))
{
}

CutiePhonenumber::CutiePhonenumber(const QString &number, const QString &ISO,
				   QObject *parent)
	: QObject(parent)
	, d_ptr(new CutiePhonenumberPrivate(this))
{
	parse(number, ISO);
}

CutiePhonenumber::~CutiePhonenumber()
{
}

int CutiePhonenumber::countryCode() const
{
	Q_D(const CutiePhonenumber);
	return d->m_phoneNumber.country_code();
}

void CutiePhonenumber::setCountryCode(const int _countryCode)
{
	Q_D(CutiePhonenumber);
	if (countryCode() == _countryCode)
		return;

	d->m_phoneNumber.set_country_code(_countryCode);
	emit countryCodeChanged();
}

long long CutiePhonenumber::nationalNumber() const
{
	Q_D(const CutiePhonenumber);
	return d->m_phoneNumber.national_number();
}

void CutiePhonenumber::setNationalNumber(const long long _nationalNumber)
{
	Q_D(CutiePhonenumber);
	if (nationalNumber() == _nationalNumber)
		return;

	d->m_phoneNumber.set_national_number(_nationalNumber);
	emit nationalNumberChanged();
}

bool CutiePhonenumber::canBeInternationallyDialled() const
{
	Q_D(const CutiePhonenumber);
	return CutiePhonenumberHelperPrivate::m_phoneNumberUtil
		->CanBeInternationallyDialled(d->m_phoneNumber);
}

QString CutiePhonenumber::getISOCountryCode() const
{
	Q_D(const CutiePhonenumber);
	std::string ISO;
	CutiePhonenumberHelperPrivate::m_phoneNumberUtil->GetRegionCodeForNumber(
		d->m_phoneNumber, &ISO);
	return QString::fromStdString(ISO);
}

bool CutiePhonenumber::isGeographical() const
{
	Q_D(const CutiePhonenumber);
	return CutiePhonenumberHelperPrivate::m_phoneNumberUtil
		->IsNumberGeographical(d->m_phoneNumber);
}

bool CutiePhonenumber::isPossibleNumber() const
{
	Q_D(const CutiePhonenumber);
	return CutiePhonenumberHelperPrivate::m_phoneNumberUtil
		->IsPossibleNumber(d->m_phoneNumber);
}

bool CutiePhonenumber::isValidNumber() const
{
	Q_D(const CutiePhonenumber);
	return CutiePhonenumberHelperPrivate::m_phoneNumberUtil->IsValidNumber(
		d->m_phoneNumber);
}

QString CutiePhonenumber::format(const PhoneNumberFormat format) const
{
	Q_D(const CutiePhonenumber);
	std::string formattedNumber;
	CutiePhonenumberHelperPrivate::m_phoneNumberUtil->Format(
		d->m_phoneNumber, CutiePhonenumberPrivate::toLibFormat(format),
		&formattedNumber);
	return QString::fromStdString(formattedNumber);
}

QString CutiePhonenumber::formatOriginal(const QString &ISO) const
{
	Q_D(const CutiePhonenumber);
	std::string formattedNumber;
	CutiePhonenumberHelperPrivate::m_phoneNumberUtil->FormatInOriginalFormat(
		d->m_phoneNumber, ISO.toStdString(), &formattedNumber);
	return QString::fromStdString(formattedNumber);
}

void CutiePhonenumber::parse(const QString &number, const QString &ISO)
{
	Q_D(CutiePhonenumber);
	CutiePhonenumberHelperPrivate::m_phoneNumberUtil->Parse(
		number.toStdString(), ISO.toStdString(), &d->m_phoneNumber);
}

bool CutiePhonenumber::locallyEqualTo(const CutiePhonenumber *other,
				      const QString &ISO) const
{
	Q_D(const CutiePhonenumber);
	i18n::phonenumbers::PhoneNumberUtil::MatchType matchType =
		CutiePhonenumberHelperPrivate::m_phoneNumberUtil->IsNumberMatch(
			d->m_phoneNumber, other->d_func()->m_phoneNumber);
	if (matchType ==
	    i18n::phonenumbers::PhoneNumberUtil::MatchType::EXACT_MATCH)
		return true;
	else if (matchType ==
		 i18n::phonenumbers::PhoneNumberUtil::MatchType::NSN_MATCH) {
		if (countryCode() == 0) {
			if (other->countryCode() == 0)
				return true;
			else
				return other->countryCode() ==
				       CutiePhonenumberHelper::instance()
					       ->ISOToCountryCode(ISO);
		} else if (other->countryCode() == 0)
			return countryCode() ==
			       CutiePhonenumberHelper::instance()
				       ->ISOToCountryCode(ISO);
		else
			return countryCode() == countryCode();
	}

	return false;
}

CutiePhonenumberPrivate::CutiePhonenumberPrivate(CutiePhonenumber *q)
	: q_ptr(q)
{
}

CutiePhonenumberPrivate::~CutiePhonenumberPrivate()
{
}

i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat
CutiePhonenumberPrivate::toLibFormat(CutiePhonenumber::PhoneNumberFormat format)
{
	switch (format) {
	case CutiePhonenumber::PhoneNumberFormat::E164:
		return i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::
			E164;
	case CutiePhonenumber::PhoneNumberFormat::International:
		return i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::
			INTERNATIONAL;
	case CutiePhonenumber::PhoneNumberFormat::National:
		return i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::
			NATIONAL;
	case CutiePhonenumber::PhoneNumberFormat::RFC3966:
		return i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::
			RFC3966;
	}

	return i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::E164;
}

CutiePhonenumber::PhoneNumberFormat CutiePhonenumberPrivate::toOurFormat(
	i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat format)
{
	switch (format) {
	case i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::E164:
		return CutiePhonenumber::PhoneNumberFormat::E164;
	case i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::INTERNATIONAL:
		return CutiePhonenumber::PhoneNumberFormat::International;
	case i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::NATIONAL:
		return CutiePhonenumber::PhoneNumberFormat::National;
	case i18n::phonenumbers::PhoneNumberUtil::PhoneNumberFormat::RFC3966:
		return CutiePhonenumber::PhoneNumberFormat::RFC3966;
	}

	return CutiePhonenumber::PhoneNumberFormat::E164;
}
