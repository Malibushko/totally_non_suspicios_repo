#pragma once
#include <QString>
#include <QVariant>

#include "utility.h"

// Dummy class with some helper methods to imitate real API
class ContactListProvider : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;
    // Generate a random contact
    Q_INVOKABLE QVariant generateContact() const;
    // Generate a multiple random contacts
    Q_INVOKABLE QVariantList generateContacts(int size) const;

    Q_INVOKABLE QVariant call(int id) {
        Q_UNUSED(id)
        return tr("Cannot call this user. Check network accessibility");
    }
};

