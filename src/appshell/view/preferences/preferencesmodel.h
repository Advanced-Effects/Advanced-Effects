#pragma once

#include <QAbstractItemModel>

#include "modularity/ioc.h"
#include "actions/iactionsdispatcher.h"
#include "ui/iuiactionsregister.h"
#include "ui/view/iconcodes.h"

#include "iappshellconfiguration.h"
#include "preferencepageitem.h"
#include "iinteractive.h"

namespace mu::appshell {
class PreferencesModel : public QAbstractItemModel, public muse::Injectable
{
    Q_OBJECT

    Q_PROPERTY(QString currentPageId READ currentPageId WRITE setCurrentPageId NOTIFY currentPageIdChanged)

    muse::Inject<muse::actions::IActionsDispatcher> dispatcher = { this };
    muse::Inject<IAppShellConfiguration> configuration = { this };
    muse::Inject<muse::ui::IUiActionsRegister> actionsRegister = { this };
    muse::Inject<muse::IInteractive> interactive = { this };

public:
    explicit PreferencesModel(QObject* parent = nullptr);
    ~PreferencesModel();

    QModelIndex index(int row, int column, const QModelIndex& parent) const override;
    QModelIndex parent(const QModelIndex& child) const override;
    int rowCount(const QModelIndex& parent) const override;
    int columnCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    QString currentPageId() const;

    Q_INVOKABLE void load(const QString& currentPageId);
    Q_INVOKABLE bool askForConfirmationOfPreferencesReset();
    Q_INVOKABLE void resetFactorySettings();
    Q_INVOKABLE void apply();
    Q_INVOKABLE void cancel();
    Q_INVOKABLE void selectRow(const QModelIndex& rowIndex);

    Q_INVOKABLE QVariantList availablePages() const;

public slots:
    void setCurrentPageId(QString currentPageId);

signals:
    void currentPageIdChanged(QString currentPageId);

private:

    enum RoleNames {
        ItemRole = Qt::UserRole + 1
    };

    PreferencePageItem* makeItem(const QString& id, const QString& title, muse::ui::IconCode::Code icon = muse::ui::IconCode::Code::NONE,
                                 const QString& path = "", const QList<PreferencePageItem*>& children = {}) const;

    PreferencePageItem* modelIndexToItem(const QModelIndex& index) const;

    PreferencePageItem* m_rootItem = nullptr;
    QString m_currentPageId;
};
}
