#include "../include/mainwindow.h"

#include <stdio.h>

#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // qDebug() << "Hello, World!";
    
    // // QApplication a( argc, argv );
    // QPushButton hello( "Hello world!", 0 );
    // hello.resize( 100, 30 );
    // hello.show();

    // printf("Hello, World!");
    return a.exec();
}
