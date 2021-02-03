#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSortFilterProxyModel>

#include "contactlistmodel.h"
#include "contactlistprovider.h"
#include "filterproxymodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<ContactListModel>("contacts",1,0,"ContactListModel");
    qmlRegisterType<ContactListProvider>("contacts",1,0,"ContactListProvider");
    qmlRegisterType<FilterProxyModel>("contacts",1,0,"FilterProxyModel");

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
