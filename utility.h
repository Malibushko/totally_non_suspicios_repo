#pragma once
#include <QString>
#include <QUrl>
#include <QtGlobal>

namespace utility {
struct ContactInfo {
        int id;
        QString name;
        QString phone;
        QUrl photo;
        bool isFavourite;
};
}
Q_DECLARE_METATYPE(utility::ContactInfo);
