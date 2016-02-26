#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QPushButton>
#include <QLabel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onResult(QNetworkReply* reply);
    void handleSingleMeasButton();
    void handleAutomaticMeasButton();
    void handleMakeMeasure();
    void timerNotif();
signals:
    void startMeasure();
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QTimer *timer;
    int measureNumber;
};

#endif // MAINWINDOW_H
