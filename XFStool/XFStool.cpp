#include "XFStool.h"
#include "QtCore/qfile.h"

XFStool::XFStool(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::XFStoolClass)
{
	ui->setupUi(this);
	QString htmlPath = QCoreApplication::applicationDirPath() + "/PagesShow/index.html";
	QFile file(htmlPath);//直接加载本地html文件，外部对象由本地文件的相对路径查找，因此不需要设置
	if (!file.exists())
	{
		return;
	}

	ui->webEngineView->load(QUrl("file:///" + htmlPath));
	ui->webEngineView->showFullScreen();

}

XFStool::~XFStool()
{
	delete ui;
	ui->webEngineView->destroyed();
}
