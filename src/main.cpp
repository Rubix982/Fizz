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
    QApplication a(argc, argv);
    MainWindow w;

    w.setDefaultLook();

    w.show();
    return a.exec();
}

/*
    * References
    * Integrating QML with QT Widgets, https://www.youtube.com/watch?v=rK6BBW-xdUw
*/