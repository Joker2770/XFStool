#include "DataExchange.h"
#include <QDebug>
#include <string>
#include <cxJsonModel.h>

using namespace std;


DataExchange::DataExchange(QObject *parent)
	: QObject(parent)
{
	this->m_XFSLoader = new WSXFSLoader();
}

DataExchange::~DataExchange()
{
	if (this->m_XFSLoader)
	{
		delete this->m_XFSLoader;
	}
}

int DataExchange::jsToCpp(const QString &sMethod, const QString &sJsonIn)
{
	if (sMethod == "WFSStartUp")
	{
		LPWFSVERSION lpVersion = nullptr;
		auto result = WFMAllocateBuffer(sizeof(WFSVERSION), WFS_MEM_ZEROINIT | WFS_MEM_SHARE, (void**)&lpVersion);
		DWORD dwVersion = 0x00031403;
		auto startupResult = this->m_XFSLoader->WFSStartUp(dwVersion, lpVersion);

		string sOut = lpVersion->szDescription;

		string s = sJsonIn.toStdString();
		qDebug() << s.c_str();
		emit cppToJs(QString::fromStdString(sOut));
	}
	if (sMethod == "WFSOpen")
	{
	}
	if (sMethod == "WFSCleanUp")
	{
		auto result = WFSCleanUp();

		string s = sJsonIn.toStdString();
		qDebug() << s.c_str();
		emit cppToJs("WFSCleanUp");
	}

	return 0;
}