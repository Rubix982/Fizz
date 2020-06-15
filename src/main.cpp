// local header files
#include "mainwindow.h"

// Integrating Qt Widgets with QML, see ref below
#include <QGuiApplication>
#include <QQmlApplicationEngine>

// QT header files
#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <QDebug>

int main(int argc, char *argv[])
{
    // Application attributes
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // The application class
    QGuiApplication app(argc, argv);

    // Use the QML engine
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("./resources/qrcFiles/main.qml"));

    // Connceting a signal and slot - making sure the object and url match
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject * QObject, const QUrl &QObjectUrl) {
        if ( !QObject && url == QObjectUrl )
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // the engine loading the qml file
    engine.load(url);

    return app.exec();
}

/*
    * References
    * Integrating QML with QT Widgets, https://www.youtube.com/watch?v=rK6BBW-xdUw
*/