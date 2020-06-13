#include "../include/mainwindow.h"
#include "../include/ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::setDefaultLook(void)
{

    ui->networkDetails->setPlainText(QString("saif here - network"));
    ui->systemInfo->setPlainText(QString("saif here - systeminfo"));

    setDashboardContent();
    setDashboardStyling();

    setServicesContent();
    setServicesStyling();

    setProcessesContent();
    setProcessesStyling();

    setGraphsContent();
    setGraphsStyling();

    setPackageContent();
    setPackageStyling();

}

/*********************!< For the dashboard *************/
void MainWindow::setDashboardContent(void)
{

    setusage_MainFrameContent();
    setsystemInfo_MainFrameContent();
    setnetworking_MainFrameContent();

}

void MainWindow::setDashboardStyling(void)
{

    setusage_MainFrameStyling();
    setsystemInfo_MainFrameStyling();
    setnetworking_MainFrameStyling();

}

void MainWindow::setusage_MainFrameContent(void)
{
    QFile file("resources/views/dashboard/html/template.html");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QString htmlText = "";

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        htmlText += line;
    }

    ui->usageInfo->setHtml(htmlText);
}

void MainWindow::setusage_MainFrameStyling(void)
{

}

void MainWindow::setsystemInfo_MainFrameContent(void)
{
    QFile file("resources/views/dashboard/html/template.html");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QString htmlText = "";

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        htmlText += line;
    }

    ui->systemInfo->setHtml(htmlText);
}

void MainWindow::setsystemInfo_MainFrameStyling(void)
{

}

void MainWindow::setnetworking_MainFrameContent(void)
{
    QFile file("resources/views/dashboard/html/template.html");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QString htmlText = "";

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        htmlText += line;
    }

    ui->networkDetails->setHtml(htmlText);
}

void MainWindow::setnetworking_MainFrameStyling(void)
{

}

/*********************!< End for the dashboard *************/

/*********************!< For the services *************/

void MainWindow::setServicesContent(void)
{

}

void MainWindow::setServicesStyling(void)
{

}

/*********************!< End for the services *************/

/*********************!< For the processes *************/

void MainWindow::setProcessesContent(void)
{

}

void MainWindow::setProcessesStyling(void)
{

}

/*********************!< End for the processes *************/

/*********************!< For the graphs *************/

void MainWindow::setGraphsContent(void)
{

}

void MainWindow::setGraphsStyling(void)
{

}

/*********************!< End for the graphs *************/

/*********************!< For the packages *************/

void MainWindow::setPackageContent(void)
{

}

void MainWindow::setPackageStyling(void)
{

}

//!< Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

/*!< Misc */
void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{
    return ;
}
