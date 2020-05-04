#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setDefaultLook(void);
    ~MainWindow();

private:

    /*!< For the dashboard */
    void setDashboardContent(void);
    void setDashboardStyling(void);

    void setusage_MainFrameContent(void);
    void setusage_MainFrameStyling(void);

    void setsystemInfo_MainFrameContent(void);
    void setsystemInfo_MainFrameStyling(void);

    void setnetworking_MainFrameContent(void);
    void setnetworking_MainFrameStyling(void);

    /*!< For the services */
    void setServicesContent(void);
    void setServicesStyling(void);

    /*!< For the processes */
    void setProcessesContent(void);
    void setProcessesStyling(void);

    /*!< For the graphs */
    void setGraphsContent(void);
    void setGraphsStyling(void);

    /*!< For the packages */
    void setPackageContent(void);
    void setPackageStyling(void);

private slots:
    void on_centralwidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
