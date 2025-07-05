#pragma once

#include <QObject>
#include <QVariant>
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QQmlEngine>
#include <QJSEngine>

class CutieDesktopFilePhraserPrivate;

class CutieDesktopFilePhraser : public QObject {
	Q_OBJECT
	Q_DECLARE_PRIVATE(CutieDesktopFilePhraser)

public:
	explicit CutieDesktopFilePhraser(QObject *parent = nullptr);
	~CutieDesktopFilePhraser();

	// Fetches all entries in a given directory
	Q_INVOKABLE QVariantList fetchAllEntries() const;

	static CutieDesktopFilePhraser *instance();
	static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
	CutieDesktopFilePhraserPrivate *d_ptr;

	Q_DISABLE_COPY(CutieDesktopFilePhraser)
};