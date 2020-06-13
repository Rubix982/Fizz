// local header files
#include "../include/mainwindow.h"
#include "../include/dashboard/systemInfo.h"

// CXX standard header files
#include <stdio.h>
#include <memory>

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

    systemInfo data;

    w.show();
    return a.exec();
}
