#include "cutiedesktopfilephraser_P.h"
#include <QSettings>
#include <QDir>
#include <QFileInfo>

CutieDesktopFilePhraser::CutieDesktopFilePhraser(QObject *parent)
	: QObject(parent), d_ptr(new CutieDesktopFilePhraserPrivate) {}

CutieDesktopFilePhraser::~CutieDesktopFilePhraser() {
	delete d_ptr;
}

QVariantList CutieDesktopFilePhraser::fetchAllEntries(const QString &directory) const {
	QVariantList entries;
	QDir dir(directory);
	QStringList filters;
	filters << "*.desktop";
	QFileInfoList files = dir.entryInfoList(filters, QDir::Files);

	for (const QFileInfo &fileInfo : files) {
		QSettings desktopFile(fileInfo.absoluteFilePath(), QSettings::IniFormat);
		QVariantMap entry;
		for (const QString &key : desktopFile.allKeys()) {
			entry.insert(key, desktopFile.value(key));
		}
		entries.append(entry);
	}
	return entries;
}

QVariantMap CutieDesktopFilePhraser::fetchEntry(const QString &filePath) const {
	QSettings desktopFile(filePath, QSettings::IniFormat);
	QVariantMap entry;
	for (const QString &key : desktopFile.allKeys()) {
		entry.insert(key, desktopFile.value(key));
	}
	return entry;
}

CutieDesktopFilePhraser *CutieDesktopFilePhraser::instance() {
	static CutieDesktopFilePhraser instance;
	return &instance;
}

QObject *CutieDesktopFilePhraser::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
	Q_UNUSED(engine)
	Q_UNUSED(scriptEngine)
	return CutieDesktopFilePhraser::instance();
}
