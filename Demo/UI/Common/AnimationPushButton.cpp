#include "AnimationPushButton.h"
#include "QFrame"
#include "qcoreevent.h"
#include "qevent.h"
#include <QPropertyAnimation>
#include "QBoxLayout"
#include "QToolTip"
#include "QTimer"
#include "AnimationHoverFrame.h"


AnimationPushButton::AnimationPushButton(QWidget* parent /*= nullptr*/):QPushButton(parent)
{
	setFixedSize(27, 27);
}

AnimationPushButton::~AnimationPushButton()
{

}


