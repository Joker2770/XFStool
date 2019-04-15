#ifndef __XFSTOOL_H__
#define __XFSTOOL_H__

#include <QtWidgets/QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QStackedLayout>
#include "ui_XFStool.h"

namespace Ui {
	class XFStoolClass;
}

class XFStool : public QMainWindow
{
	Q_OBJECT

public:
	XFStool(QWidget *parent = Q_NULLPTR);
	~XFStool();


private:
	Ui::XFStoolClass *ui;
};

#endif
