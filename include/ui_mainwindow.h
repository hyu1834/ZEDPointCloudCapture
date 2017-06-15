/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionPreview;
    QAction *actionPause;
    QAction *actionSave;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *menuTitle;
    QFrame *line;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QLabel *label_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *colorResolutionBox;
    QFrame *line_5;
    QPushButton *showLeftStreamButton;
    QPushButton *showRightStreamButton;
    QPushButton *showSBSStreamButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QComboBox *depthSenseModeBox;
    QFrame *line_4;
    QPushButton *showDepthStreamButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QComboBox *unitBox;
    QLabel *label_7;
    QComboBox *coordinateBox;
    QPushButton *previewButton;
    QFrame *line_2;
    QPushButton *pauseButton;
    QFrame *line_3;
    QPushButton *savePointCloudButton;
    QPushButton *saveImagesButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *pcImage;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1357, 920);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QStringLiteral("actionPreview"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        menuTitle = new QLabel(centralWidget);
        menuTitle->setObjectName(QStringLiteral("menuTitle"));
        menuTitle->setAutoFillBackground(false);
        menuTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(menuTitle);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setMaximum(999999999);
        spinBox->setValue(500);

        horizontalLayout_2->addWidget(spinBox);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        colorResolutionBox = new QComboBox(groupBox);
        colorResolutionBox->setObjectName(QStringLiteral("colorResolutionBox"));
        colorResolutionBox->setEnabled(true);

        verticalLayout->addWidget(colorResolutionBox);

        line_5 = new QFrame(groupBox);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        showLeftStreamButton = new QPushButton(groupBox);
        showLeftStreamButton->setObjectName(QStringLiteral("showLeftStreamButton"));
        showLeftStreamButton->setEnabled(false);

        verticalLayout->addWidget(showLeftStreamButton);

        showRightStreamButton = new QPushButton(groupBox);
        showRightStreamButton->setObjectName(QStringLiteral("showRightStreamButton"));
        showRightStreamButton->setEnabled(false);

        verticalLayout->addWidget(showRightStreamButton);

        showSBSStreamButton = new QPushButton(groupBox);
        showSBSStreamButton->setObjectName(QStringLiteral("showSBSStreamButton"));
        showSBSStreamButton->setEnabled(false);

        verticalLayout->addWidget(showSBSStreamButton);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        depthSenseModeBox = new QComboBox(groupBox_2);
        depthSenseModeBox->setObjectName(QStringLiteral("depthSenseModeBox"));

        verticalLayout_4->addWidget(depthSenseModeBox);

        line_4 = new QFrame(groupBox_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        showDepthStreamButton = new QPushButton(groupBox_2);
        showDepthStreamButton->setObjectName(QStringLiteral("showDepthStreamButton"));
        showDepthStreamButton->setEnabled(false);

        verticalLayout_4->addWidget(showDepthStreamButton);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);

        unitBox = new QComboBox(groupBox_4);
        unitBox->setObjectName(QStringLiteral("unitBox"));

        verticalLayout_6->addWidget(unitBox);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_6->addWidget(label_7);

        coordinateBox = new QComboBox(groupBox_4);
        coordinateBox->setObjectName(QStringLiteral("coordinateBox"));

        verticalLayout_6->addWidget(coordinateBox);


        verticalLayout_2->addWidget(groupBox_4);

        previewButton = new QPushButton(centralWidget);
        previewButton->setObjectName(QStringLiteral("previewButton"));

        verticalLayout_2->addWidget(previewButton);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);

        verticalLayout_2->addWidget(pauseButton);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        savePointCloudButton = new QPushButton(centralWidget);
        savePointCloudButton->setObjectName(QStringLiteral("savePointCloudButton"));
        savePointCloudButton->setEnabled(false);

        verticalLayout_2->addWidget(savePointCloudButton);

        saveImagesButton = new QPushButton(centralWidget);
        saveImagesButton->setObjectName(QStringLiteral("saveImagesButton"));
        saveImagesButton->setEnabled(false);

        verticalLayout_2->addWidget(saveImagesButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pcImage = new QLabel(centralWidget);
        pcImage->setObjectName(QStringLiteral("pcImage"));

        verticalLayout_3->addWidget(pcImage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1357, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionPreview);
        menuFile->addAction(actionPause);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuAbout->addAction(actionHelp);
        menuAbout->addAction(actionAbout);
        mainToolBar->addAction(actionHelp);
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        colorResolutionBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ZED Point Cloud Capture", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionPreview->setText(QApplication::translate("MainWindow", "Preview", 0));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        menuTitle->setText(QApplication::translate("MainWindow", "Menu", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Screen", 0));
        label_4->setText(QApplication::translate("MainWindow", "Refresh Rate", 0));
        label_5->setText(QApplication::translate("MainWindow", "ms", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Color Stream", 0));
        label->setText(QApplication::translate("MainWindow", "Reaolution", 0));
        colorResolutionBox->clear();
        colorResolutionBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2K", 0)
         << QApplication::translate("MainWindow", "1080p", 0)
         << QApplication::translate("MainWindow", "720p", 0)
         << QApplication::translate("MainWindow", "480p", 0)
        );
        showLeftStreamButton->setText(QApplication::translate("MainWindow", "Show Left Stream", 0));
        showRightStreamButton->setText(QApplication::translate("MainWindow", "Show Right Stream", 0));
        showSBSStreamButton->setText(QApplication::translate("MainWindow", "Show Side by Side", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Depth Stream", 0));
        label_2->setText(QApplication::translate("MainWindow", "Depth Sensing Mode", 0));
        depthSenseModeBox->clear();
        depthSenseModeBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Performance", 0)
         << QApplication::translate("MainWindow", "Quality", 0)
        );
        showDepthStreamButton->setText(QApplication::translate("MainWindow", "Show Depth Stream", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Other", 0));
        label_3->setText(QApplication::translate("MainWindow", "Unit", 0));
        unitBox->clear();
        unitBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Meter", 0)
        );
        label_7->setText(QApplication::translate("MainWindow", "Coordinate", 0));
        coordinateBox->clear();
        coordinateBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Right Hand - Y Up", 0)
         << QApplication::translate("MainWindow", "Left Hand", 0)
        );
        previewButton->setText(QApplication::translate("MainWindow", "Preview", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0));
        savePointCloudButton->setText(QApplication::translate("MainWindow", "Save Point Cloud", 0));
        saveImagesButton->setText(QApplication::translate("MainWindow", "Save Images", 0));
        pcImage->setText(QApplication::translate("MainWindow", "PointCloud", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
