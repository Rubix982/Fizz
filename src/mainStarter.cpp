#include "../include/mainwindow.h"

#include <stdio.h>

#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTableView tableView;

    tableView.update(1, 1, 5, 5);

    fprintf(stdout, "Heigh: %d , Row: %d ", tableView.columnWidth(0), tableView.rowHeight(0) );

    w.show();
    return a.exec();
}
