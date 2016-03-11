/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *btAddNodes;
    QPushButton *btRemoveNodes;
    QPushButton *btGetNodes;
    QLabel *statusAdd3;
    QLabel *statusRemove3;
    QPlainTextEdit *nodesInfo3;
    QPushButton *btStopNet;
    QPushButton *btStartNet;
    QLabel *startNetwork;
    QLabel *stopNetwork;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_4;
    QLabel *temperature;
    QLabel *label_3;
    QLabel *luminosity;
    QLabel *label_2;
    QLabel *status;
    QLabel *label_6;
    QLabel *motion;
    QLabel *battery;
    QPushButton *automaticMeasure;
    QLabel *label;
    QLabel *label_7;
    QPushButton *singleMeasure;
    QGridLayout *gridLayout_5;
    QLabel *battery2;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *humidity2;
    QLabel *label_5;
    QLabel *luminosity2;
    QLabel *label_12;
    QLabel *temperature2;
    QLabel *sensor2;
    QLabel *motion2;
    QLabel *label_9;
    QLabel *controller2;
    QLabel *label_13;
    QLabel *location2;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *updateTime2;
    QPushButton *btallMeasure2;
    QLabel *status2;
    QLabel *label_19;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_16;
    QLabel *label_17;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_15;
    QLineEdit *sensorId;
    QLabel *label_18;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1189, 374);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btAddNodes = new QPushButton(centralwidget);
        btAddNodes->setObjectName(QStringLiteral("btAddNodes"));

        gridLayout_2->addWidget(btAddNodes, 2, 0, 1, 1);

        btRemoveNodes = new QPushButton(centralwidget);
        btRemoveNodes->setObjectName(QStringLiteral("btRemoveNodes"));

        gridLayout_2->addWidget(btRemoveNodes, 3, 0, 1, 1);

        btGetNodes = new QPushButton(centralwidget);
        btGetNodes->setObjectName(QStringLiteral("btGetNodes"));

        gridLayout_2->addWidget(btGetNodes, 4, 0, 1, 1);

        statusAdd3 = new QLabel(centralwidget);
        statusAdd3->setObjectName(QStringLiteral("statusAdd3"));

        gridLayout_2->addWidget(statusAdd3, 2, 1, 1, 1);

        statusRemove3 = new QLabel(centralwidget);
        statusRemove3->setObjectName(QStringLiteral("statusRemove3"));

        gridLayout_2->addWidget(statusRemove3, 3, 1, 1, 1);

        nodesInfo3 = new QPlainTextEdit(centralwidget);
        nodesInfo3->setObjectName(QStringLiteral("nodesInfo3"));
        nodesInfo3->setEnabled(true);
        nodesInfo3->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(nodesInfo3, 4, 1, 1, 1);

        btStopNet = new QPushButton(centralwidget);
        btStopNet->setObjectName(QStringLiteral("btStopNet"));

        gridLayout_2->addWidget(btStopNet, 1, 0, 1, 1);

        btStartNet = new QPushButton(centralwidget);
        btStartNet->setObjectName(QStringLiteral("btStartNet"));

        gridLayout_2->addWidget(btStartNet, 0, 0, 1, 1);

        startNetwork = new QLabel(centralwidget);
        startNetwork->setObjectName(QStringLiteral("startNetwork"));

        gridLayout_2->addWidget(startNetwork, 0, 1, 1, 1);

        stopNetwork = new QLabel(centralwidget);
        stopNetwork->setObjectName(QStringLiteral("stopNetwork"));

        gridLayout_2->addWidget(stopNetwork, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        temperature = new QLabel(centralwidget);
        temperature->setObjectName(QStringLiteral("temperature"));

        gridLayout_4->addWidget(temperature, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 4, 0, 1, 1);

        luminosity = new QLabel(centralwidget);
        luminosity->setObjectName(QStringLiteral("luminosity"));

        gridLayout_4->addWidget(luminosity, 4, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        status = new QLabel(centralwidget);
        status->setObjectName(QStringLiteral("status"));

        gridLayout_4->addWidget(status, 1, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 3, 0, 1, 1);

        motion = new QLabel(centralwidget);
        motion->setObjectName(QStringLiteral("motion"));

        gridLayout_4->addWidget(motion, 3, 1, 1, 1);

        battery = new QLabel(centralwidget);
        battery->setObjectName(QStringLiteral("battery"));

        gridLayout_4->addWidget(battery, 5, 1, 1, 1);

        automaticMeasure = new QPushButton(centralwidget);
        automaticMeasure->setObjectName(QStringLiteral("automaticMeasure"));

        gridLayout_4->addWidget(automaticMeasure, 6, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 5, 0, 1, 1);

        singleMeasure = new QPushButton(centralwidget);
        singleMeasure->setObjectName(QStringLiteral("singleMeasure"));
        singleMeasure->setMinimumSize(QSize(0, 27));

        gridLayout_4->addWidget(singleMeasure, 6, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(9, -1, -1, -1);
        battery2 = new QLabel(centralwidget);
        battery2->setObjectName(QStringLiteral("battery2"));

        gridLayout_5->addWidget(battery2, 1, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 5, 0, 1, 1);

        humidity2 = new QLabel(centralwidget);
        humidity2->setObjectName(QStringLiteral("humidity2"));

        gridLayout_5->addWidget(humidity2, 3, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        luminosity2 = new QLabel(centralwidget);
        luminosity2->setObjectName(QStringLiteral("luminosity2"));

        gridLayout_5->addWidget(luminosity2, 5, 1, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 6, 0, 1, 1);

        temperature2 = new QLabel(centralwidget);
        temperature2->setObjectName(QStringLiteral("temperature2"));

        gridLayout_5->addWidget(temperature2, 8, 1, 1, 1);

        sensor2 = new QLabel(centralwidget);
        sensor2->setObjectName(QStringLiteral("sensor2"));

        gridLayout_5->addWidget(sensor2, 7, 1, 1, 1);

        motion2 = new QLabel(centralwidget);
        motion2->setObjectName(QStringLiteral("motion2"));

        gridLayout_5->addWidget(motion2, 6, 1, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 4, 0, 1, 1);

        controller2 = new QLabel(centralwidget);
        controller2->setObjectName(QStringLiteral("controller2"));

        gridLayout_5->addWidget(controller2, 2, 1, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_5->addWidget(label_13, 8, 0, 1, 1);

        location2 = new QLabel(centralwidget);
        location2->setObjectName(QStringLiteral("location2"));

        gridLayout_5->addWidget(location2, 4, 1, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 3, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 7, 0, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_5->addWidget(label_14, 9, 0, 1, 1);

        updateTime2 = new QLabel(centralwidget);
        updateTime2->setObjectName(QStringLiteral("updateTime2"));

        gridLayout_5->addWidget(updateTime2, 9, 1, 1, 1);

        btallMeasure2 = new QPushButton(centralwidget);
        btallMeasure2->setObjectName(QStringLiteral("btallMeasure2"));

        gridLayout_5->addWidget(btallMeasure2, 10, 0, 1, 2);

        status2 = new QLabel(centralwidget);
        status2->setObjectName(QStringLiteral("status2"));

        gridLayout_5->addWidget(status2, 0, 1, 1, 1);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_5->addWidget(label_19, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_5, 2, 2, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 1, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        line_2->setFont(font);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 3, 1, 1);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 1, 2, 1, 1);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_17, 1, 4, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 1, 1, 1, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 1, 3, 1, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 1, 0, 1, 1);

        sensorId = new QLineEdit(centralwidget);
        sensorId->setObjectName(QStringLiteral("sensorId"));

        gridLayout->addWidget(sensorId, 0, 2, 1, 1);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_18, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btAddNodes->setText(QApplication::translate("MainWindow", "Add Nodes", 0));
        btRemoveNodes->setText(QApplication::translate("MainWindow", "Remove Nodes", 0));
        btGetNodes->setText(QApplication::translate("MainWindow", "Get Nodes", 0));
        statusAdd3->setText(QString());
        statusRemove3->setText(QString());
        btStopNet->setText(QApplication::translate("MainWindow", "Stop Network", 0));
        btStartNet->setText(QApplication::translate("MainWindow", "Start Network", 0));
        startNetwork->setText(QString());
        stopNetwork->setText(QString());
        temperature->setText(QApplication::translate("MainWindow", "- [\302\260C]", 0));
        label_3->setText(QApplication::translate("MainWindow", "Luminance:", 0));
        luminosity->setText(QApplication::translate("MainWindow", "- [lux]", 0));
        label_2->setText(QApplication::translate("MainWindow", "Temperature:", 0));
        status->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Motion:", 0));
        motion->setText(QApplication::translate("MainWindow", "-", 0));
        battery->setText(QApplication::translate("MainWindow", "- [%]", 0));
        automaticMeasure->setText(QApplication::translate("MainWindow", "Automatic measure", 0));
        label->setText(QApplication::translate("MainWindow", "Connection status:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Battery level:", 0));
        singleMeasure->setText(QApplication::translate("MainWindow", "Make measure", 0));
        battery2->setText(QApplication::translate("MainWindow", "- [%]", 0));
        label_4->setText(QApplication::translate("MainWindow", "Battery level:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Luminance:", 0));
        humidity2->setText(QApplication::translate("MainWindow", "- [%]", 0));
        label_5->setText(QApplication::translate("MainWindow", "Controller:", 0));
        luminosity2->setText(QApplication::translate("MainWindow", "- [lux]", 0));
        label_12->setText(QApplication::translate("MainWindow", "Motion:", 0));
        temperature2->setText(QApplication::translate("MainWindow", "- [\302\260C]", 0));
        sensor2->setText(QApplication::translate("MainWindow", "-", 0));
        motion2->setText(QApplication::translate("MainWindow", "-", 0));
        label_9->setText(QApplication::translate("MainWindow", "Location:", 0));
        controller2->setText(QApplication::translate("MainWindow", "-", 0));
        label_13->setText(QApplication::translate("MainWindow", "Temperature:", 0));
        location2->setText(QApplication::translate("MainWindow", "-", 0));
        label_8->setText(QApplication::translate("MainWindow", "Humidity:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Sensor ID:", 0));
        label_14->setText(QApplication::translate("MainWindow", "UpdateTime:", 0));
        updateTime2->setText(QApplication::translate("MainWindow", "-", 0));
        btallMeasure2->setText(QApplication::translate("MainWindow", "Get all measure sensors", 0));
        status2->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "Connection status:", 0));
        label_16->setText(QApplication::translate("MainWindow", "All measures", 0));
        label_17->setText(QApplication::translate("MainWindow", "Node management", 0));
        label_15->setText(QApplication::translate("MainWindow", "Individual Measures", 0));
        label_18->setText(QApplication::translate("MainWindow", "Set Node ID:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
