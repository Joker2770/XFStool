#include "DataExchange.h"
#include "json/json.h"
#include <QDebug>
#include <string>

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

HRESULT DataExchange::jsToCpp(const QString &sMethod, const QString &sJsonIn)
{
	if (sMethod == "WFSStartUp")
	{
		LPWFSVERSION lpVersion = nullptr;
		auto result = WFMAllocateBuffer(sizeof(WFSVERSION), WFS_MEM_ZEROINIT | WFS_MEM_SHARE, (void**)&lpVersion);

		Json::Reader reader;
		Json::Value in_root;
		if (reader.parse(sJsonIn.toStdString(), in_root))
		{
			string s = sJsonIn.toStdString();
			qDebug() << s.c_str();

			DWORD dwVersion = in_root["dwVersionsRequired"].asInt64();
			auto startupResult = this->m_XFSLoader->WFSStartUp(dwVersion, lpVersion);

			Json::Value out_root;
			out_root["wVersion"] = Json::Value(lpVersion->wVersion);
			out_root["wLowVersion"] = Json::Value(lpVersion->wLowVersion);
			out_root["wHighVersion"] = Json::Value(lpVersion->wHighVersion);
			out_root["szDescription"] = Json::Value(lpVersion->szDescription);
			out_root["szSystemStatus"] = Json::Value(lpVersion->szSystemStatus);

			Json::StreamWriterBuilder jsrocd;
			jsrocd.settings_["indentation"] = "";
			unique_ptr<Json::StreamWriter> write(jsrocd.newStreamWriter());

			string sJson = Json::writeString(jsrocd, out_root);

			emit cppToJs(QString::fromStdString(sJson));
		}

	}
	if (sMethod == "WFSOpen")
	{
	}
	if (sMethod == "WFSCleanUp")
	{
		auto result = WFSCleanUp();

		return result;
// 		char szBuff[100] = "";
// 		emit cppToJs(ltoa(result, szBuff, 10));
	}

	return 0;
}