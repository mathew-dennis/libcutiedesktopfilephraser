#pragma once

#include "cutiedesktopfilephraser.h"
#include <QObject>

class CutieDesktopFilePhraserPrivate {
    Q_DECLARE_PUBLIC(CutieDesktopFilePhraser)

public:
    explicit CutieDesktopFilePhraserPrivate(CutieDesktopFilePhraser *q);
    ~CutieDesktopFilePhraserPrivate();

private:
    CutieDesktopFilePhraser *q_ptr;
};