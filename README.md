# libcutiedesktopfilephraser

[![CircleCI](https://dl.circleci.com/status-badge/img/gh/cutie-shell/libcutiedesktopfilephraser/tree/cutie.svg?style=svg)](https://dl.circleci.com/status-badge/redirect/gh/cutie-shell/libcutiedesktopfilephraser/tree/cutie)

This library provides desktop file phrasing capability for Cutie.

## Building and installing

```
mkdir build
cd build
cmake ..
make
sudo make install
```
There are two ways to call fetchAllEntriesModel():

1. Default application locations

Fetches all installed applications from the standard application directories:

```
ListView {
    model: CutieDesktopFilePhraser.fetchAllEntriesModel()
    delegate: Text { text: name }
}
```

```
2. Custom paths (e.g., autostart)

Fetches desktop entries from specific directories, such as autostart folders:

ListView {
    model: CutieDesktopFilePhraser.fetchAllEntriesModel(["/etc/xdg/autostart", "~/.config/autostart"])
    delegate: Text { text: name }
}

```

Each call returns a separate, independent model, so you can use multiple lists simultaneously (Settings apps, App menu, Autostart apps).

## Troubleshooting
This library includes qDebug() statements to help track its execution.

When fetching entries, the debug output will show:

Which directories are being scanned.

Which desktop files are read.

The total number of entries found.

If your app list appears empty, check the debug output to verify:

The correct directories are being scanned.

.desktop files are present and not hidden or set to NoDisplay=true.
