// local header files
#include "mainwindow.h"

// Integrating Qt Widgets with QML, see ref below
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickWindow>
#include <QQuickView>
#include <QQuickTransform>

// QT header files
#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <QQuickWidget>

int main(int argc, char *argv[])
{

    /*  FOR DEBUGGING WITH QML */
    // // Application attributes
    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // // The application class
    // QGuiApplication app(argc, argv);

    // // Use the QML engine
    // QQmlApplicationEngine engine;

    // const QUrl url(QStringLiteral("./resources/qrcFiles/main.qml"));

    // // Connceting a signal and slot - making sure the object and url match
    // QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject * QObject, const QUrl &QObjectUrl) {
    //     if ( !QObject && url == QObjectUrl )
    //         QCoreApplication::exit(-1);
    // }, Qt::QueuedConnection);

    // // the engine loading the qml file
    // engine.load(url);
    /*  FOR DEBUGGING WITH QML */


    QApplication app(argc, argv);
    MainWindow MainWindow;

    // QQmlEngine engine;

    // // Using QQuickView
    // QQuickView view;
    // view.setSource(QUrl::fromLocalFile("./resources/qrcFiles/main.qml"));
    // view.show();
    // QObject *object = view.rootObject();

    MainWindow.setDefaultLook();

    MainWindow.show();
    return app.exec();
}

/*
    * References
    * Integrating QML with QT Widgets, https://www.youtube.com/watch?v=rK6BBW-xdUw
    * Same as above, https://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html
*/