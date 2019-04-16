#ifndef __DATAEXCHANGE_H__
#define __DATAEXCHANGE_H__

#include <QObject>
#include "WSXFSLoader.h"

class DataExchange : public QObject
{
	Q_OBJECT

public:
	DataExchange(QObject *parent = nullptr);
	virtual ~DataExchange();

	Q_INVOKABLE HRESULT jsToCpp(const QString &sMethod, const QString &sJsonIn);


	WSXFSLoader *m_XFSLoader;

signals:
	int cppToJs(const QString &sJsonOut);
};



#endif // !__DATAEXCHANGE_H__

