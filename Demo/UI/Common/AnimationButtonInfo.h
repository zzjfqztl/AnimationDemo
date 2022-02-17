#ifndef ANIMATIONBUTTONINFO_H
#define ANIMATIONBUTTONINFO_H

#include <QString>
#include "AnimationButtonType.h"
class AnimationButtonInfo
{
public:
    AnimationButtonInfo();
    AnimationButtonInfo(AnimationButtonId id,const QString& objectName, const QString &toolTip,bool bCheckable,const QList<AnimationButtonInfo> &buttonList = QList<AnimationButtonInfo>());
    void SetAssociatedButtons(const QList<AnimationButtonInfo>& buttonList);
    QList<AnimationButtonInfo> GetAssociatedButtons() const;
    bool operator==(const AnimationButtonInfo& info);
public:
    AnimationButtonId id_;
    QString objectName_;//按钮别名
    QString toolTipInfo_;//按钮提示信息
    bool bCheckable_;//按钮是否选中状态
private:
    QList<AnimationButtonInfo> associatedButtonList_;
};


#endif // ANIMATIONBUTTONINFO_H
