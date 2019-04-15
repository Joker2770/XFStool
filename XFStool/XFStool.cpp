#include "XFStool.h"
#include "QtCore/qfile.h"

XFStool::XFStool(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::XFStoolClass)
{
	ui->setupUi(this);
	QString htmlPath = QCoreApplication::applicationDirPath() + "/PagesShow/index.html";
	QFile file(htmlPath);//ֱ�Ӽ��ر���html�ļ����ⲿ�����ɱ����ļ������·�����ң���˲���Ҫ����
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
