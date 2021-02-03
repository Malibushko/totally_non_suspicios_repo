#include "contactlistmodel.h"

#include <QtGlobal>

ContactListModel::ContactListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ContactListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_contacts.size();
}

QVariant ContactListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_contacts.size())
        return QVariant{};

    const utility::ContactInfo& contact = m_contacts[index.row()];
    switch (static_cast<CONTACT_ROLES>(role)) {
        case CONTACT_ROLES::ID:
            return contact.id;
        case CONTACT_ROLES::Name:
            return contact.name;
        case CONTACT_ROLES::Phone:
            return contact.phone;
        case CONTACT_ROLES::Photo:
            return contact.photo;
        case CONTACT_ROLES::IsFavourite:
            return contact.isFavourite;
        default:
        return QVariant{};
    }
}

QHash<int, QByteArray> ContactListModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[static_cast<int>(CONTACT_ROLES::ID)] = "Id";
    roles[static_cast<int>(CONTACT_ROLES::Name)] = "Name";
    roles[static_cast<int>(CONTACT_ROLES::Phone)] = "Phone";
    roles[static_cast<int>(CONTACT_ROLES::Photo)] = "Photo";
    roles[static_cast<int>(CONTACT_ROLES::IsFavourite)] = "Favourite";
    return roles;
}

bool ContactListModel::setModel(const QVariantList &items)
{
    if (items.size()) {
        beginResetModel();

        m_contacts.clear();
        m_contacts.reserve(items.size());
        for (const QVariant& item : items) {
            if (item.canConvert<utility::ContactInfo>()) {
                m_contacts.push_back(qvariant_cast<utility::ContactInfo>(item));
            } else {
                return false;
            }
        }
        // using list+sort instead of set because model does not change after initialization
        std::sort(m_contacts.begin(),m_contacts.end(),[](const auto& lhs,const auto& rhs){
            return lhs.id < rhs.id;
        });
        endResetModel();
    }
    return true;
}

void ContactListModel::maskAsFavourite(int id, bool isFavourite) {
    utility::ContactInfo info;
    info.id = id;
    auto iter = std::lower_bound(m_contacts.begin(),m_contacts.end(),info,[](auto& lhs,auto& rhs){
        return lhs.id < rhs.id;
    });
    if (iter != m_contacts.end()) {
        iter->isFavourite = isFavourite;
        int index = std::distance(m_contacts.begin(),iter);
        emit dataChanged(createIndex(index,1),createIndex(index+1,1),{static_cast<int>(CONTACT_ROLES::IsFavourite)});
    }
}
