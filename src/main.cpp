// local header files
#include "../include/mainwindow.h"

// CXX standard header files
#include <stdio.h>

// QT header files
#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
