#include <QApplication>
#include <QQmlApplicationEngine>
#include "registermetatype.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RegisterMetaType::instance();

    QQmlApplicationEngine engine;

    QQmlContext *ctx=engine.rootContext();
    RegisterMetaType::instance()->setQmlContextProperty(ctx);

    engine.addImportPath(":/qml");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
