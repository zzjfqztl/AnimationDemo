
#include <QDir>
#include <QProcess>
#include <QApplication>
#include <QStandardPaths>
#include <QSplashScreen>
#include <QJsonDocument>
#include <QJsonObject>

#include <QLibraryInfo>
#include <String.h>
#include <windows.h>
#include <iostream>
#include <winuser.h>
#include "MainWindow.h"

#include <QTranslator>
#include "QGuiApplication"
#include "Common/AnimationHoverFrame.h"

#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")
#endif

/// <summary>
/// ��ȡ��ʽ����Ϣ����������ʽ������
/// </summary>
/// <param name="sheetName">��ʽ����������</param>
/// <returns></returns>
QString loadStyleSheet(const QStringList& sheetName)
{
	QString styleSheet;
	for (auto& itr : sheetName)
	{
		//QFile file("D:/workspace/ASTM/Demo/Resources/ry_systle.css");
        QFile file(":/css/ry_systle.css");
		bool b = file.open(QFile::ReadOnly);
		if (file.isOpen())
		{
			styleSheet += QString(file.readAll()) + "";

		}
	}
	return styleSheet;
}


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QStringList cssFiles;
	cssFiles << "ry_systle";
	a.setStyleSheet(loadStyleSheet(cssFiles));
	QTranslator tsor; //ȫ����ʾ����
	//����������
	bool bret = tsor.load(":/Translator/RY3D_ASTN_CN.qm");    //�������԰�
	
	qApp->installTranslator(&tsor); //��װ������


	MainWindow w;
	w.show();
	return a.exec();
   
}