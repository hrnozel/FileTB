#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "filelistmodel.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    FileListModel fileModel;

    engine.rootContext()->setContextProperty("myFileModel", &fileModel);


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("filetb", "Main");

    return app.exec();
}
