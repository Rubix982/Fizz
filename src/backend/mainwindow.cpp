#include "../../include/mainwindow.h"
#include "../../include/ui_mainwindow.h"

#include <iostream>
#include <QQmlContext>
#include <QQuickView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ui->CPU->setSource(QUrl(QStringLiteral("./resources/qrcFiles/main.qml")));

    // m_engine->addImportPath("./resources/qrcFiles/");

    // m_engine->load(QUrl(QStringLiteral("./resources/qrcFiles/main.qml")));

    // qDebug() << "[MAIN_WINDOW.CPP] QQmlApplicationEngine created ... ";

    // QWindow *qmlWindow = qobject_cast<QWindow*>(m_engine->rootContext());

    // QWidget *container = QWidget::createWindowContainer(qmlWindow);

    // container->setMinimumSize(200, 200);
    // container->setMaximumSize(1200, 900);

    // ui->horizontalLayout->addWidget(container);

    // QQuickWidget * view = new QQuickWidget();
    // view->setSource(QUrl::fromLocalFile("./resources/qrcFiles/main.qml"));

    // // view->show();

    // ui->horizontalLayout->addWidget(view);

    ui->CPU->rootContext()->setContextProperty("widget", this);
    ui->CPU->setSource(QUrl(QStringLiteral("./resources/qrcFiles/main.qml")));
}

void MainWindow::setDefaultLook(void)
{

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

    QFile file("resources/views/dashboard/css/dashboard.min.css");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QString cssContent = "";

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        cssContent += line;
    }

    ui->dashboard->setStyleSheet(cssContent);

    setusage_MainFrameStyling();
    setsystemInfo_MainFrameStyling();
    setnetworking_MainFrameStyling();

}

void MainWindow::setusage_MainFrameContent(void)
{

    /* <! ---------------- Not rendering any HTML right now -------> */
    // QFile file("resources/views/dashboard/html/usageInfo.html");
    // if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    //     return ;

    // QString htmlText = "";

    // while (!file.atEnd()) {
    //     QByteArray line = file.readLine();
    //     htmlText += line;
    // }

    // ui->usageInfo->setHtml(htmlText);
    /* <! ---------------- Not rendering any HTML right now -------> */
}

void MainWindow::setusage_MainFrameStyling(void)
{

}

void MainWindow::setsystemInfo_MainFrameContent(void)
{
    QFile file("resources/views/dashboard/html/systemInfo.html");
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

    // For the download
    QFile fileDownload("resources/views/dashboard/html/networkDownload.html");
    if (!fileDownload.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QString htmlText = "";

    while (!fileDownload.atEnd()) {
        QByteArray line = fileDownload.readLine();
        htmlText += line;
    }

    ui->downloadDetails->setHtml(htmlText);
    ui->downloadDetails->setStyleSheet("background-color: #212F3C;");

    // For the upload section
    QFile fileUpload("resources/views/dashboard/html/networkUpload.html");
    if (!fileUpload.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    htmlText = "";

    while (!fileUpload.atEnd()) {
        QByteArray line = fileUpload.readLine();
        htmlText += line;
    }

    ui->uploadDetails->setHtml(htmlText);
    ui->uploadDetails->setStyleSheet("background-color: #212F3C;");

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
    std::cout << pos.x() << " " << pos.y();
    return ;
}
