#include "AnimationButtonInfo.h"


AnimationButtonInfo::AnimationButtonInfo(AnimationButtonId id, const QString& objectName, const QString& toolTip, bool bCheckable, const QList<AnimationButtonInfo>& buttonList):
	id_(id),objectName_(objectName),toolTipInfo_(toolTip),associatedButtonList_(buttonList)
{

}

AnimationButtonInfo::AnimationButtonInfo()
{
	id_ = AnimationButtonId::ButtonNone;
	objectName_.clear();
	toolTipInfo_.clear();
	associatedButtonList_.clear();
	bCheckable_ = false;
}

void AnimationButtonInfo::SetAssociatedButtons(const QList<AnimationButtonInfo>& buttonList)
{
	associatedButtonList_ = buttonList;
}

QList<AnimationButtonInfo> AnimationButtonInfo::GetAssociatedButtons() const
{
	return associatedButtonList_;
}

bool AnimationButtonInfo::operator==(const AnimationButtonInfo& info)
{
	return id_ == info.id_;
}

