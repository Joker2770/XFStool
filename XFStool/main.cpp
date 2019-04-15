#include "XFStool.h"
#include "DataExchange.h"
#include <QtWidgets/QApplication>
#include <QtWebChannel/QWebChannel>
#include <QtWebSockets/QWebSocketServer>
#include <QtNetwork/QTcpServer>
//#include <QHostAddress>
#include "websocketclientwrapper.h"
#include "websockettransport.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	XFStool w;
	w.setMinimumSize(1000, 800);
	w.show();

	QWebSocketServer server(QStringLiteral("QWebChannel Standalone Example Server")
									, QWebSocketServer::NonSecureMode);
	if (!server.listen(QHostAddress::LocalHost, 12345)) {
		qFatal("Failed to open web socket server.");
		return 1;
	}

	// wrap WebSocket clients in QWebChannelAbstractTransport objects
	WebSocketClientWrapper clientWrapper(&server);

	// setup the channel
	QWebChannel channel;
	QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
						&channel, &QWebChannel::connectTo);

	DataExchange DataExchange(&a);
	channel.registerObject(QStringLiteral("DataExchange"), &DataExchange);


	return a.exec();
}
