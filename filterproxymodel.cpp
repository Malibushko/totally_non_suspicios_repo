#include "filterproxymodel.h"

void FilterProxyModel::setFilterString(const QString &filter) {
    setFilterRegExp(filter);
}

bool FilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    QVariant isFavourite = sourceModel()->data(createIndex(source_row,0),
                                               static_cast<int>(ContactListModel::CONTACT_ROLES::IsFavourite));
    if (isFavourite.canConvert<bool>() && m_showOnlyFavourites) {
        if (!isFavourite.toBool()) {
            return false;
        }
    }
    return QSortFilterProxyModel::filterAcceptsRow(source_row,source_parent);
}

bool FilterProxyModel::getShowOnlyFavourites() const
{
    return m_showOnlyFavourites;
}

void FilterProxyModel::setOnlyFavourites(bool ShowOnlyFavourites)
{
    m_showOnlyFavourites = ShowOnlyFavourites;
    invalidateFilter();
}
