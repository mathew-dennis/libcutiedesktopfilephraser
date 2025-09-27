#pragma once

#include <QObject>
#include <QStringList>
#include <QAbstractListModel>
#include <QVariantMap>
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QStandardPaths>
#include <QQmlEngine>
#include <QJSEngine>
#include <QDebug>

class CutieDesktopFilePhraser : public QObject {
    Q_OBJECT

public:
    explicit CutieDesktopFilePhraser(QObject *parent = nullptr);
    ~CutieDesktopFilePhraser();

    // Returns a new model populated with entries from given paths
    Q_INVOKABLE QAbstractListModel* fetchAllEntriesModel(const QStringList &paths = {}) const;

    static CutieDesktopFilePhraser* instance();
    static QObject* provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    Q_DISABLE_COPY(CutieDesktopFilePhraser)

    // Inner model class
    class DesktopEntryModel : public QAbstractListModel {
        Q_OBJECT
    public:
        enum Roles {
            NameRole = Qt::UserRole + 1,
            ExecRole,
            IconRole,
            GenericRole
        };

        DesktopEntryModel(QObject *parent = nullptr)
            : QAbstractListModel(parent) {}

        int rowCount(const QModelIndex &parent = QModelIndex()) const override {
            if (parent.isValid()) return 0;
            return m_entries.size();
        }

        QVariant data(const QModelIndex &index, int role) const override {
            if (!index.isValid() || index.row() >= m_entries.size())
                return QVariant();

            const QVariantMap &entry = m_entries.at(index.row());
            switch (role) {
            case NameRole: return entry.value("Desktop Entry/Name");
            case ExecRole: return entry.value("Desktop Entry/Exec");
            case IconRole: return entry.value("Desktop Entry/Icon");
            case GenericRole: return entry;
            default: return QVariant();
            }
        }

        QHash<int, QByteArray> roleNames() const override {
            return {
                {NameRole, "name"},
                {ExecRole, "exec"},
                {IconRole, "icon"},
                {GenericRole, "entry"}
            };
        }

        void setEntries(const QList<QVariantMap> &entries) {
            beginResetModel();
            m_entries = entries;
            endResetModel();
        }

    private:
        QList<QVariantMap> m_entries;
    };
};
