#pragma once
#include <QSortFilterProxyModel>
#include <QDebug>
#include "contactlistmodel.h"

class FilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(bool showOnlyFavourites READ getShowOnlyFavourites WRITE setOnlyFavourites NOTIFY onShowOnlyFavourites)
    bool m_showOnlyFavourites = false;

public:
    Q_INVOKABLE void setFilterString(const QString& filter);
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override;

    bool getShowOnlyFavourites() const;
public slots:
    void setOnlyFavourites(bool ShowOnlyFavourites);
signals:
    void onShowOnlyFavourites(bool showOnlyFavourites);
};

