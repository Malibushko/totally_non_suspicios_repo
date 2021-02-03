#include "contactlistprovider.h"

#include <QRandomGenerator>
#include <utility>
#include <atomic>

namespace details {
QString randomName() {
    static constexpr const char* names[] = {"John","Mike","Michael","Igor","Konstantin","Jaime","Marina",
                                           "Andrew","William","Harper","Mason","Evelyn","Ella","Avery"};
    static constexpr const char* secondNames[] = {"Adams","Allen","Anderson","Armstrong","Atkinson","Bailey",
                                                 "Baker","Ball","Barker","Barnes","Bell","Bennet","Booth","Bradley","Cole"};
    quint16 nameIndex,snameIndex;
    nameIndex = QRandomGenerator::global()->bounded(static_cast<quint32>(std::size(names)));
    snameIndex = QRandomGenerator::global()->bounded(static_cast<quint32>(std::size(names)));

    return QString(names[nameIndex]) + ' ' + secondNames[snameIndex];
}
QString randomPhone() {
    constexpr int phoneLength = 8;
    QString phone = "380"; // just to make realism I'll use Ukraine's phone prefix
    for (int i = 0; i < phoneLength;++i) {
        phone.push_back(QString::number(QRandomGenerator().global()->bounded(9)));
    }
    return phone;
}
QString randomPhoto() {
    constexpr const char* photoPath = "resource/img_%1.jpg";
    int randomNum = QRandomGenerator::global()->bounded(9);
    return QString(photoPath).arg(randomNum);
}
int randomId() {
    static std::atomic<int> id;
    return ++id;
}
}

QVariant ContactListProvider::generateContact() const
{
   utility::ContactInfo contact;
   contact.phone = details::randomPhone();
   contact.name = details::randomName();
   contact.photo = details::randomPhoto();
   contact.id = details::randomId();
   contact.isFavourite = false;
   return QVariant::fromValue(contact);
}

QVariantList ContactListProvider::generateContacts(int size) const
{
    QVariantList contacts;
    contacts.reserve(size); // no resize method...
    for (int i = 0; i < size;++i)
        contacts.push_back(generateContact());
    return contacts;
}
