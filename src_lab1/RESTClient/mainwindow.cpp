#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timerNotif()));
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onResult(QNetworkReply *)));
    connect(ui->singleMeasure, SIGNAL (released()), this, SLOT(handleSingleMeasButton()));
    connect(ui->automaticMeasure, SIGNAL (released()), this, SLOT(handleAutomaticMeasButton()));
    connect(this, SIGNAL (startMeasure()), this, SLOT(handleMakeMeasure()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onResult(QNetworkReply* reply)
{
     QPalette palette;
    if (reply->error() > 0) {
        qDebug() << reply->error();
        palette = ui->status->palette();
        palette.setColor(ui->status->foregroundRole(), Qt::red);
        ui->status->setPalette(palette);
        ui->status->setText("connection error");
    }
    else {
        QString strReply = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        qDebug() << strReply;

        switch (measureNumber) {
        case 0:
            palette = ui->status->palette();
            palette.setColor(ui->status->foregroundRole(), Qt::darkGreen);
            ui->status->setPalette(palette);
            ui->status->setText("Sensor 3 connected");
            ui->temperature->setText(QString::number(jsonObject["value"].toDouble())+" [°C]");
            break;
        case 1:
            ui->singleMeasure->setEnabled(true);
            break;
        default:
            break;
        }
        measureNumber++;
        if(measureNumber<=1)
            emit startMeasure();
    }
}

void MainWindow::handleSingleMeasButton()
{
    ui->singleMeasure->setEnabled(false);
    measureNumber = 0;
    emit startMeasure();
}

void MainWindow::handleAutomaticMeasButton()
{
    if(ui->automaticMeasure->text().contains("Stop"))
    {
        ui->automaticMeasure->setText("Automatic measures");
        timer->stop();
    }
    else
    {
        ui->automaticMeasure->setText("Stop auto measures");
        measureNumber = 0;
        emit startMeasure();
        timer->start(10000);
    }
}

void MainWindow::handleMakeMeasure()
{
    QNetworkRequest request;

    switch(measureNumber){
    case 0:
        request.setUrl(QUrl("http://192.168.1.2:5000/sensors/3/temperature"));
        break;
    case 1:
        request.setUrl(QUrl("http://192.168.1.2:5000/sensors/3/luminance"));
        break;
    default:
        break;
    }
    manager->get(request);  // GET
}

void MainWindow::timerNotif()
{
    measureNumber = 0;
    emit startMeasure();
}
