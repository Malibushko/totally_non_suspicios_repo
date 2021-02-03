#pragma once
#include <QAbstractListModel>

#include "utility.h"

class ContactListModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QList<utility::ContactInfo> m_contacts;
public:
    enum class CONTACT_ROLES {
        ID = Qt::UserRole,
        Name,
        Phone,
        Photo,
        IsFavourite,
    };
    Q_ENUMS(CONTACT_ROLES)

    explicit ContactListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int,QByteArray> roleNames() const override;

    Q_INVOKABLE bool setModel(const QVariantList& items);
    Q_INVOKABLE void maskAsFavourite(int id, bool isFavourite);
};
