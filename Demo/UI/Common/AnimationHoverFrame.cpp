#include "AnimationHoverFrame.h"
#include "QBoxLayout"
#include "QPushButton"
#include "QPropertyAnimation"
#include "AnimationPushButton.h"
#include "qcoreevent.h"
#include "qevent.h"
#include <QDebug>

AnimationHoverFrame::AnimationHoverFrame(int nIndex, const AnimationButtonInfo infos, QWidget *parent) : QFrame(parent),associatedIndex_(nIndex)
{
	setAttribute(Qt::WA_TranslucentBackground, true);
	installEventFilter(this);
	int nWidth = 0;
	
	animationPushButtonList_.clear();
	InitData(infos);
	nWidth = GetButtonList().count() * 27 + 6 * (GetButtonList().count() - 1);
	resize(29, 29);
}

void AnimationHoverFrame::InsertAnimationButton(int index, AnimationPushButton* button)
{
	if (index > animationPushButtonList_.count())
	{
		index = animationPushButtonList_.count();
	}
	if (button)
	{
		if (index > 0)
		{
			connect(button, &QPushButton::clicked, this, &AnimationHoverFrame::onAnimationClicked);
		}
		
	}
	animationPushButtonList_.insert(index, button);
}

AnimationPushButton* AnimationHoverFrame::takeAt(int index)
{
	if (index >= 0 && index < animationPushButtonList_.count())
	{
		AnimationPushButton* btn = animationPushButtonList_[index];
		if (btn)
		{
			disconnect(btn, &QPushButton::clicked, this, &AnimationHoverFrame::onAnimationClicked);
		}
		animationPushButtonList_.removeAt(index);
		return btn;
	}
	
	return nullptr;
}

void AnimationHoverFrame::InitData(const QList<AnimationButtonInfo>& infos)
{
	int nCount = 0;
	for (auto& itr : infos)
	{
		AnimationPushButton* btn = new AnimationPushButton();
		btn->setObjectName(itr.objectName_);
		btn->setToolTip(itr.toolTipInfo_);
		
		btn->setText(itr.toolTipInfo_);
		animationPushButtonList_.append(btn);
		if (nCount > 0)
		{
			btn->setVisible(true);
	
			connect(btn, &QPushButton::clicked, this, &AnimationHoverFrame::onAnimationClicked);
		}
		
		nCount++;
		
	}

	setFixedSize(QSize(27, 27));
}

void AnimationHoverFrame::InitData(const AnimationButtonInfo infos)
{
	
	AnimationPushButton* btn = new AnimationPushButton(this);
	btn->setObjectName(infos.objectName_);
	btn->setToolTip(infos.toolTipInfo_);

	btn->setText(infos.toolTipInfo_);
	animationPushButtonList_.append(btn);
	btn->installEventFilter(this);
	btn->setMouseTracking(true);  //设置鼠标追踪
	btn->setAttribute(Qt::WA_Hover, true);
	btn->setGeometry(1, 1, 27, 27);
	int nCount = 1;
	for (auto& info : infos.GetAssociatedButtons())
	{
		AnimationPushButton* btn1 = new AnimationPushButton(this);
		btn1->setObjectName(info.objectName_);
		btn1->setToolTip(info.toolTipInfo_);
		btn1->setText(info.toolTipInfo_);
		animationPushButtonList_.append(btn1);
		btn1->setGeometry(1 + nCount * 27 + nCount * 6, 1, 27, 27);
		btn1->setVisible(false);
		connect(btn1, &QPushButton::clicked, this, &AnimationHoverFrame::onAnimationClicked);
		nCount++;
	}
	
	
}

AnimationPushButton* AnimationHoverFrame::GetAnimationButton(int nIndex)
{
	if (nIndex >= 0 && nIndex < animationPushButtonList_.count())
	{
		return animationPushButtonList_[nIndex];
	}
	return nullptr;
}

QList<AnimationPushButton*> AnimationHoverFrame::GetButtonList() const
{
	return animationPushButtonList_;
}

void AnimationHoverFrame::onAnimationClicked()
{
	AnimationPushButton* btn = qobject_cast<AnimationPushButton*>(sender());
	if (btn)
	{
		int nIndex = 0;
		for (; nIndex < animationPushButtonList_.count(); nIndex++)
		{
			if (animationPushButtonList_[nIndex] == btn)
			{
				break;
			}
		}
		if (nIndex > 0)
		{
			auto btn1 = animationPushButtonList_[0];

			QPoint startPos = btn->pos();
			QPoint endPos = btn1->pos();
			QRect startRect = QRect(startPos.x(), startPos.y(), btn->width(), btn->height());
			QRect endRect = QRect(endPos.x(), startPos.y(), btn1->width(), btn1->height());;

			QPropertyAnimation* animation1 = new QPropertyAnimation(btn, "pos");
			animation1->setTargetObject(btn);
			animation1->setDuration(300);//设置动画持续时间
			animation1->setStartValue(startPos);

			animation1->setEndValue(endPos);
			animation1->setEasingCurve(QEasingCurve::InOutQuad);

	
			QPropertyAnimation* animation2 = new QPropertyAnimation(btn1, "pos");
			animation2->setTargetObject(btn1);
			animation2->setDuration(300);//设置动画持续时间
			animation2->setStartValue(endPos);
			animation2->setEndValue(startPos);
			animation2->setEasingCurve(QEasingCurve::InOutQuad);
			animation2->start(QAbstractAnimation::DeleteWhenStopped);
			animation1->start(QAbstractAnimation::DeleteWhenStopped);
			connect(animation1, &QAbstractAnimation::finished, [this, nIndex]() {
				if (nIndex >= 0 && nIndex < animationPushButtonList_.count())
				{
					auto btn = animationPushButtonList_[nIndex];
					auto btn1 = animationPushButtonList_[0];
					btn1->removeEventFilter(this);
					btn1->setMouseTracking(false);  //设置鼠标追踪
					btn1->setAttribute(Qt::WA_Hover, false);
					connect(btn1, &QPushButton::clicked, this, &AnimationHoverFrame::onAnimationClicked);
					btn->installEventFilter(this);
					btn->setMouseTracking(true);  //设置鼠标追踪
					btn->setAttribute(Qt::WA_Hover, true);
					disconnect(btn, &QPushButton::clicked, this, &AnimationHoverFrame::onAnimationClicked);
					animationPushButtonList_[0] = btn;
					animationPushButtonList_[nIndex] = btn1;
					

				}
				});

		}
	}
}

bool AnimationHoverFrame::eventFilter(QObject* object, QEvent* event)
{
	if (animationPushButtonList_.count()> 0)
	{
		if (event->type() == QEvent::HoverMove && object == animationPushButtonList_[0])
		{
			QHoverEvent* hoverEvent = static_cast<QHoverEvent*>(event);
	
			QRect rect = this->frameGeometry();
			
			int nWidth = 0;
			nWidth = 1+animationPushButtonList_.count() * 27 + 6 * (animationPushButtonList_.count() - 1);
			
			QRect rect1 = this->frameGeometry();
			QRect endrect = QRect(rect.topLeft().x(), rect.topLeft().y(), nWidth, rect.height());
			QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");//this代表是自己这个窗口使用这个效果
			animation->setDuration(300);//设置动画持续时间
			animation->setStartValue(rect);
			animation->setEndValue(endrect);
				
			animation->setEasingCurve(QEasingCurve::InOutQuad);
			animation->start(QAbstractAnimation::DeleteWhenStopped);//开始动画        参数：停止时删除动画
			

			connect(animation, &QPropertyAnimation::valueChanged, [&](const QVariant& value) {
				QRect r = value.toRect();
					
				if (r.isEmpty() )
				{
					return;
				}
				
					 
				for (int iLoop = 1; iLoop < animationPushButtonList_.count(); iLoop++)
				{
					if (r.width()<= (iLoop + 1) * 27 + 6 * (iLoop - 1) + 1+26 && r.width() >= (iLoop + 1) *27 + 6 * (iLoop - 1) + 1 - 26)
					{
						if (!animationPushButtonList_[iLoop]->isVisible())
						{
							animationPushButtonList_[iLoop]->setVisible(true);
						}
				
					}
				}
					});


		}
		else if (event->type() == QEvent::Leave && (object == this))
		{

			QRect rect = this->frameGeometry();

			QRect endrect = QRect(rect.topLeft().x(), rect.topLeft().y(), 29, rect.height());
			QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");//this代表是自己这个窗口使用这个效果
			animation->setDuration(300);//设置动画持续时间
			animation->setStartValue(rect);
			animation->setEndValue(endrect);

			animation->setEasingCurve(QEasingCurve::InOutQuad);
			animation->start(QAbstractAnimation::DeleteWhenStopped);//开始动画        参数：停止时删除动画
		

			connect(animation, &QPropertyAnimation::valueChanged, [&](const QVariant& value) {
				QRect r = value.toRect();
					
				if (r.isEmpty())
				{
					return;
				}
				

				for (int iLoop = 1; iLoop < animationPushButtonList_.count(); iLoop++)
				{
					if (r.width() <= (iLoop + 1) * 27 + 6 * (iLoop - 1) + 1 + 26 && r.width() >= (iLoop + 1) * 27 + 6 * (iLoop - 1) + 1 - 26)
					{
						if (animationPushButtonList_[iLoop]->isVisible())
						{
							animationPushButtonList_[iLoop]->setVisible(false);
						}

					}
				}
				});
			connect(animation, &QPropertyAnimation::finished, [&]() {
				if (animationPushButtonList_.count() > 0)
				{
					animationPushButtonList_[0]->setVisible(true);
				}
				});

	
		}

	}
	
	
	return __super::eventFilter(object, event);
}
