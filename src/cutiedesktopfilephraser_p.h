#pragma once
#include "cutiedesktopfilephraser.h"
#include <QObject>
#include <QMap>
#include <QString>

class CutieDesktopFilePhraserPrivate : public QObject {
	Q_OBJECT
	Q_DECLARE_PUBLIC(CutieDesktopFilePhraser)

    public:
	CutieDesktopFilePhraserPrivate(CutieDesktopFilePhraser *q);
	~CutieDesktopFilePhraserPrivate();

	// To store desktop file entries.
	QMap<QString, QVariantMap> m_desktopFileEntries;

    private:
	CutieDesktopFilePhraser *q_ptr;

	// Method to load all desktop files into m_desktopFileEntries.
	void loadDesktopFiles();

	// Method to load a single desktop file.
	void loadDesktopFile(const QString &filePath);
};