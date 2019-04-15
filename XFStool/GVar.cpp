#include "GVar.h"
#include <QtCore/QLibrary>
#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>

GVar::GVar()
{
// 	int result = 0;
// 	QLibrary mylib("msxfs.dll");   //声明所用到的dll文件
// 	if (mylib.load())              //判断是否正确加载
// 	{
// 		QMessageBox::information(NULL, "OK", "DLL load is OK!");
// 		WFSStartUp_ = (pWFSStartUp)mylib.resolve("WFSStartUp");    //援引函数
// 		WFSCleanUp_ = (pWFSCleanUp)mylib.resolve("WFSCleanUp");
// 		if (WFSStartUp_)                  //是否成功连接上函数
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