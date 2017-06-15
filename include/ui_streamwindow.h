/********************************************************************************
** Form generated from reading UI file 'streamwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAMWINDOW_H
#define UI_STREAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_streamWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *streamImage;

    void setupUi(QWidget *streamWindow)
    {
        if (streamWindow->objectName().isEmpty())
            streamWindow->setObjectName(QStringLiteral("streamWindow"));
        streamWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(streamWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        streamImage = new QLabel(streamWindow);
        streamImage->setObjectName(QStringLiteral("streamImage"));

        verticalLayout->addWidget(streamImage);


        retranslateUi(streamWindow);

        QMetaObject::connectSlotsByName(streamWindow);
    } // setupUi

    void retranslateUi(QWidget *streamWindow)
    {
        streamWindow->setWindowTitle(QApplication::translate("streamWindow", "Form", 0));
        streamImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class streamWindow: public Ui_streamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMWINDOW_H
