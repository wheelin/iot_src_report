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
    ui->sensorId->setValidator( new QIntValidator(1, 232, this) );
    ui->sensorId->setText("4");

    manager = new QNetworkAccessManager(this);
    managerAdd = new QNetworkAccessManager(this);
    managerAll = new QNetworkAccessManager(this);
    managerRemove = new QNetworkAccessManager(this);
    managerGet = new QNetworkAccessManager(this);
    manageStartNetw = new QNetworkAccessManager(this);
    manageStopNetw = new QNetworkAccessManager(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timerNotif()));
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onResult(QNetworkReply *)));
    connect(managerAdd, SIGNAL(finished(QNetworkReply *)), this, SLOT(onAddNodesResult(QNetworkReply *)));
    connect(managerRemove, SIGNAL(finished(QNetworkReply *)), this, SLOT(onRemoveNodesResult(QNetworkReply *)));
    connect(managerGet, SIGNAL(finished(QNetworkReply *)), this, SLOT(onGetNodesResult(QNetworkReply *)));
    connect(managerAll, SIGNAL(finished(QNetworkReply *)), this, SLOT(onGetAllResult(QNetworkReply *)));
    connect(manageStartNetw, SIGNAL(finished(QNetworkReply*)), this, SLOT(onStartNetResult(QNetworkReply*)));
    connect(manageStopNetw, SIGNAL(finished(QNetworkReply*)), this, SLOT(onStopNetResult(QNetworkReply*)));
    connect(ui->singleMeasure, SIGNAL (released()), this, SLOT(handleSingleMeasButton()));
    connect(ui->automaticMeasure, SIGNAL (released()), this, SLOT(handleAutomaticMeasButton()));
    connect(ui->btallMeasure2, SIGNAL (released()), this, SLOT(handleGetAll()));
    connect(ui->btAddNodes, SIGNAL (released()), this, SLOT(handleAddNode()));
    connect(ui->btGetNodes, SIGNAL (released()), this, SLOT(handleGetNodes()));
    connect(ui->btRemoveNodes, SIGNAL (released()), this, SLOT(handleRemoveNode()));
    connect(ui->btStartNet, SIGNAL(released()), this, SLOT(handleStartNet()));
    connect(ui->btStopNet, SIGNAL(released()), this, SLOT(handleStopNet()));
    connect(this, SIGNAL (startMeasure()), this, SLOT(handleMakeMeasure()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
    delete managerAdd;
    delete managerAll;
    delete managerGet;
    delete managerRemove;
}

void MainWindow::onResult(QNetworkReply* reply)
{
    QPalette palette = ui->status->palette();
    QString strReply;
    if (reply->error() > 0) {
        strReply = reply->errorString();
        palette.setColor(ui->status->foregroundRole(), Qt::red);
        qDebug() << strReply;
        ui->status->setPalette(palette);
        ui->status->setText(strReply);
    }
    else {
        strReply = (QString)reply->readAll();
        qDebug() << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        if(jsonObject.empty())
        {
            palette.setColor(ui->status->foregroundRole(), Qt::red);
            ui->status->setPalette(palette);
            ui->status->setText("Network stopped");
        }
        else
        {
            palette.setColor(ui->status->foregroundRole(), Qt::darkGreen);
            ui->status->setPalette(palette);
            ui->status->setText("Sensor "+ui->sensorId->text()+" connected");

            switch (measureNumber) {
            case 0:
                ui->temperature->setText(QString::number(jsonObject["value"].toDouble())+" [°C]");
                break;
            case 1:
                ui->luminosity->setText(QString::number(jsonObject["value"].toInt())+" [lux]");
                break;
            case 2:
                if(jsonObject["value"].toBool())
                    ui->motion->setText("True");
                else
                    ui->motion->setText("False");
                break;
            case 3:
                ui->battery->setText(QString::number(jsonObject["value"].toInt())+" [%]");
                break;
            default:
                break;
            }
            measureNumber++;
            if(measureNumber<=3)
                emit startMeasure();
        }
    }
}

void MainWindow::onAddNodesResult(QNetworkReply *reply)
{
    QPalette palette = ui->statusAdd3->palette();
    QString strReply;
    if (reply->error() > 0) {
        strReply = reply->errorString();
        palette.setColor(ui->statusAdd3->foregroundRole(), Qt::red);
    }
    else {
        strReply = (QString)reply->readAll();
        palette.setColor(ui->statusAdd3->foregroundRole(), Qt::black);
    }
    qDebug() << strReply;
    ui->statusAdd3->setPalette(palette);
    ui->statusAdd3->setText(strReply);
}

void MainWindow::onRemoveNodesResult(QNetworkReply *reply)
{
    QPalette palette = ui->statusRemove3->palette();
    QString strReply;
    if (reply->error() > 0) {
        strReply = reply->errorString();
        palette.setColor(ui->statusRemove3->foregroundRole(), Qt::red);
    }
    else {
        strReply = (QString)reply->readAll();
        palette.setColor(ui->statusRemove3->foregroundRole(), Qt::black);
    }
    qDebug() << strReply;
    ui->statusRemove3->setPalette(palette);
    ui->statusRemove3->setText(strReply);
}

void MainWindow::onGetNodesResult(QNetworkReply *reply)
{
    QString strReply;
    if (reply->error() > 0) {
        strReply = reply->errorString();
    }
    else {
        strReply = (QString)reply->readAll();
    }
    qDebug() << strReply;
    ui->nodesInfo3->clear(); // unless you know the editor is empty
    if(strReply=="")
        ui->nodesInfo3->appendPlainText("Network stopped");
    else
        ui->nodesInfo3->appendPlainText(strReply);
}

void MainWindow::onGetAllResult(QNetworkReply *reply)
{
    QPalette palette = ui->status2->palette();
    QString strReply;
    if (reply->error() > 0) {
        strReply = reply->errorString();
        qDebug() << strReply;
        palette.setColor(ui->status2->foregroundRole(), Qt::red);
        ui->status2->setPalette(palette);
        ui->status2->setText(strReply);
    }
    else {
        strReply = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        qDebug() << strReply;
        if(jsonObject.empty())
        {
            palette.setColor(ui->status2->foregroundRole(), Qt::red);
            ui->status2->setPalette(palette);
            ui->status2->setText("Network stopped");
        }
        else
        {
            palette.setColor(ui->status2->foregroundRole(), Qt::darkGreen);
            ui->status2->setPalette(palette);
            ui->status2->setText("Sensor "+ui->sensorId->text()+" connected");

            ui->temperature2->setText(QString::number(jsonObject["temperature"].toDouble())+" [°C]");
            ui->battery2->setText(QString::number(jsonObject["battery"].toInt())+" [%]");
            ui->controller2->setText(jsonObject["controller"].toString());
            ui->humidity2->setText(QString::number(jsonObject["humidity"].toInt())+" [%]");
            QString location = jsonObject["location"].toString();
            if(location=="")
                ui->location2->setText("None");
            else
                ui->location2->setText(location);
            ui->luminosity2->setText(QString::number(jsonObject["luminance"].toInt())+" [lux]");
            if(jsonObject["motion"].toBool())
                ui->motion2->setText("True");
            else
                ui->motion2->setText("False");
            ui->sensor2->setText(QString::number(jsonObject["sensor"].toInt()));
            ui->updateTime2->setText(QString::number(jsonObject["updateTime"].toInt()));
        }
    }
}

void MainWindow::onStartNetResult(QNetworkReply *reply)
{
    QPalette palette;
    QString strReply;
    if (reply->error() > 0) {
        strReply = reply->errorString();
        qDebug() << strReply;
        palette = ui->startNetwork->palette();
        palette.setColor(ui->startNetwork->foregroundRole(), Qt::red);
        ui->startNetwork->setPalette(palette);
        ui->startNetwork->setText(strReply);
    }
    else {
        strReply = (QString)reply->readAll();
        qDebug() << strReply;
        ui->startNetwork->setText(strReply);
    }
}

void MainWindow::onStopNetResult(QNetworkReply *reply)
{
    QPalette palette;
    QString strReply;
    if (reply->error() > 0) {
        strReply = reply->errorString();
        qDebug() << strReply;
        palette = ui->stopNetwork->palette();
        palette.setColor(ui->stopNetwork->foregroundRole(), Qt::red);
        ui->stopNetwork->setPalette(palette);
        ui->stopNetwork->setText(strReply);
    }
    else {
        strReply = (QString)reply->readAll();
        qDebug() << strReply;
        ui->stopNetwork->setText(strReply);
    }
}

void MainWindow::handleSingleMeasButton()
{
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

void MainWindow::handleGetAll()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://192.168.1.2:5000/sensors/"+ui->sensorId->text()+"/all_measures"));
    managerAll->get(request);  // GET
}

void MainWindow::handleAddNode()
{
    QNetworkRequest request;
    ui->statusAdd3->setText("Inclusion mode in progress...(20sec)");
    request.setUrl(QUrl("http://192.168.1.2:5000/nodes/add"));
    managerAdd->get(request);  // GET
}

void MainWindow::handleRemoveNode()
{
    QNetworkRequest request;
    ui->statusRemove3->setText("Exclusion mode in progress...(20sec)");
    request.setUrl(QUrl("http://192.168.1.2:5000/nodes/remove"));
    managerRemove->get(request);  // GET
}

void MainWindow::handleStartNet()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://192.168.1.2:5000/network/start"));
    manageStartNetw->get(request);  // GET
}

void MainWindow::handleStopNet()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://192.168.1.2:5000/network/stop"));
    manageStopNetw->get(request);  // GET
}

void MainWindow::handleGetNodes()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://192.168.1.2:5000/nodes"));
    managerGet->get(request);  // GET
}

void MainWindow::handleMakeMeasure()
{
    QNetworkRequest request;

    switch(measureNumber){
    case 0:
        request.setUrl(QUrl("http://192.168.1.2:5000/sensors/"+ui->sensorId->text()+"/temperature"));
        break;
    case 1:
        request.setUrl(QUrl("http://192.168.1.2:5000/sensors/"+ui->sensorId->text()+"/luminance"));
        break;
    case 2:
        request.setUrl(QUrl("http://192.168.1.2:5000/sensors/"+ui->sensorId->text()+"/motion"));
        break;
    case 3:
        request.setUrl(QUrl("http://192.168.1.2:5000/nodes/"+ui->sensorId->text()+"/battery"));
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
