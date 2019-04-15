/********************************************************************************
** Form generated from reading UI file 'XFStool.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XFSTOOL_H
#define UI_XFSTOOL_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XFStoolClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWebEngineView *webEngineView;

    void setupUi(QMainWindow *XFStoolClass)
    {
        if (XFStoolClass->objectName().isEmpty())
            XFStoolClass->setObjectName(QString::fromUtf8("XFStoolClass"));
        XFStoolClass->resize(630, 427);
        centralWidget = new QWidget(XFStoolClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webEngineView = new QWebEngineView(centralWidget);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webEngineView, 0, 0, 1, 1);

        XFStoolClass->setCentralWidget(centralWidget);

        retranslateUi(XFStoolClass);

        QMetaObject::connectSlotsByName(XFStoolClass);
    } // setupUi

    void retranslateUi(QMainWindow *XFStoolClass)
    {
        XFStoolClass->setWindowTitle(QApplication::translate("XFStoolClass", "XFStool", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XFStoolClass: public Ui_XFStoolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XFSTOOL_H
