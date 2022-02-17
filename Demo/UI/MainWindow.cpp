#include "MainWindow.h"
#include "QBoxLayout"
#include "QPushButton"
#include "QTranslator"
#include "QGuiApplication"
#include <QFileDialog>
#include <QMessageBox>
#include "Common/AnimationButtonInfo.h"
#include "Common/AnimationHoverFrame.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	initUI();
}



void MainWindow::initUI()
{
	setFixedSize(QSize(1200, 800));
	QWidget* centerWidget_ = new QWidget(this);
	centerWidget_->setObjectName("centerWidget");
	setCentralWidget(centerWidget_);

	QVBoxLayout* vLayout = new QVBoxLayout();
	vLayout->setSpacing(20);
	vLayout->setMargin(0);
	vLayout->setContentsMargins(20, 20, 20, 20);
	vLayout->setAlignment(Qt::AlignTop);

	centerWidget_->setLayout(vLayout);

	QList<AnimationButtonInfo> infoList;
	AnimationButtonInfo info1;
	info1.bCheckable_ = true;
	info1.id_ = AnimationButtonId::ButtonA;
	info1.objectName_ = QString("btn1");
	info1.toolTipInfo_ = QObject::tr("A");
	QList<AnimationButtonInfo> infoList1 = { AnimationButtonInfo(AnimationButtonId::ButtonAbc,QString("btn1_1"),QObject::tr("Abc"),true),
		AnimationButtonInfo(AnimationButtonId::Buttonsdafa,QString("btn1_2"),QObject::tr("dafa"),true),
	AnimationButtonInfo(AnimationButtonId::Buttonwww,QString("btn1_3"),QObject::tr("www"),true)};
	info1.SetAssociatedButtons(infoList1);
	infoList.append(info1);

	AnimationButtonInfo info2;
	info2.bCheckable_ = true;
	info2.id_ = AnimationButtonId::ButtonB;
	info2.objectName_ = QString("btn2");
	info2.toolTipInfo_ = QObject::tr("B");
	QList<AnimationButtonInfo> infoList2 = { AnimationButtonInfo(AnimationButtonId::ButtonBbc,QString("btn2_1"),QObject::tr("Bbc"),true),
		AnimationButtonInfo(AnimationButtonId::ButtonBsdafa,QString("btn2_2"),QObject::tr("Bafa"),true),
	AnimationButtonInfo(AnimationButtonId::ButtonBwww,QString("btn2_3"),QObject::tr("Bww"),true) };
	info2.SetAssociatedButtons(infoList2);
	infoList.append(info2);

	/*popupButtonFrame_ = new AnimationFrame(centerWidget_);
	popupButtonFrame_->InitData(infoList);*/
	int nIndex = 0;
	for (auto &info : infoList)
	{
		AnimationHoverFrame* hoverFrame = new AnimationHoverFrame(nIndex++,info,centerWidget_);
		/*qDebug() << "h" << hoverFrame->size();
		vLayout->addWidget(hoverFrame);*/
		hoverFrame->show();
		hoverFrame->move(30, 27 * nIndex + 6 * (nIndex - 1));
		/*int nWidth = hoverFrame->GetButtonList().count() * 27 + 6 * (hoverFrame->GetButtonList().count() - 1);
		hoverFrame->setFixedSize(nWidth,27);
		hoverFrame->show();
	    hoverFrame->move(30, 27 * nIndex + 6 * (nIndex - 1));*/


	}

}

