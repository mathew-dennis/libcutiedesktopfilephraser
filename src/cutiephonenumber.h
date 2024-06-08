#pragma once
#include <QtQuick>

class CutiePhonenumber;
class CutiePhonenumberHelperPrivate;
class CutiePhonenumberPrivate;

class CutiePhonenumberHelper : public QObject {
	Q_OBJECT
	Q_DECLARE_PRIVATE(CutiePhonenumberHelper)

    public:
	CutiePhonenumberHelper(QObject *parent = nullptr);
	~CutiePhonenumberHelper();

	Q_INVOKABLE int MCCtoCountryCode(const QString &mcc) const;
	Q_INVOKABLE int ISOToCountryCode(const QString &ISO) const;
	Q_INVOKABLE QString MCCtoISO(const QString &mcc) const;
	Q_INVOKABLE QString CountryCodeToISO(const int countryCode) const;

	Q_INVOKABLE CutiePhonenumber *
	createPhonenumber(const QString &number, const QString &ISO) const;

	static CutiePhonenumberHelper *instance();
	static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

    private:
	CutiePhonenumberHelperPrivate *d_ptr;

	Q_DISABLE_COPY(CutiePhonenumberHelper)
};

class CutiePhonenumber : public QObject {
	Q_OBJECT
	Q_DECLARE_PRIVATE(CutiePhonenumber)
	Q_PROPERTY(int countryCode READ countryCode WRITE setCountryCode NOTIFY
			   countryCodeChanged)
	Q_PROPERTY(long long nationalNumber READ nationalNumber WRITE
			   setNationalNumber NOTIFY nationalNumberChanged)

    public:
	enum class PhoneNumberFormat { E164, International, National, RFC3966 };
	Q_ENUM(PhoneNumberFormat)

	CutiePhonenumber(const QString &number, const QString &ISO,
			 QObject *parent = nullptr);
	CutiePhonenumber(QObject *parent = nullptr);
	~CutiePhonenumber();

	int countryCode() const;
	void setCountryCode(const int countryCode);

	long long nationalNumber() const;
	void setNationalNumber(const long long nationalNumber);

	Q_INVOKABLE bool canBeInternationallyDialled() const;
	Q_INVOKABLE QString getISOCountryCode() const;
	Q_INVOKABLE bool isGeographical() const;
	Q_INVOKABLE bool isPossibleNumber() const;
	Q_INVOKABLE bool isValidNumber() const;
	Q_INVOKABLE QString format(const PhoneNumberFormat format) const;
	Q_INVOKABLE QString formatOriginal(const QString &ISO) const;
	Q_INVOKABLE void parse(const QString &number, const QString &ISO);

	Q_INVOKABLE bool locallyEqualTo(const CutiePhonenumber *other,
					const QString &ISO) const;

    signals:
	void countryCodeChanged();
	void nationalNumberChanged();

    private:
	CutiePhonenumberPrivate *d_ptr;
};
