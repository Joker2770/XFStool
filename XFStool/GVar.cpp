#include "GVar.h"
#include <QtCore/QLibrary>
#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>

GVar::GVar()
{
// 	int result = 0;
// 	QLibrary mylib("msxfs.dll");   //�������õ���dll�ļ�
// 	if (mylib.load())              //�ж��Ƿ���ȷ����
// 	{
// 		QMessageBox::information(NULL, "OK", "DLL load is OK!");
// 		WFSStartUp_ = (pWFSStartUp)mylib.resolve("WFSStartUp");    //Ԯ������
// 		WFSCleanUp_ = (pWFSCleanUp)mylib.resolve("WFSCleanUp");
// 		if (WFSStartUp_)                  //�Ƿ�ɹ������Ϻ���
// 		{
// 			QMessageBox::information(NULL, "OK", "Link to Function is OK!");
// 		}
// 		else
// 		{
// 			QMessageBox::information(NULL, "NO", "Linke to Function is not OK!!!!");
// 		}
// 	}
// 	else
// 	{
// 		QMessageBox::information(NULL, "NO", "DLL is not loaded!");
// 	}
}

GVar::~GVar()
{
}