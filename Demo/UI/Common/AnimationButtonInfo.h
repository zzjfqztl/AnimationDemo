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
    QString objectName_;//��ť����
    QString toolTipInfo_;//��ť��ʾ��Ϣ
    bool bCheckable_;//��ť�Ƿ�ѡ��״̬
private:
    QList<AnimationButtonInfo> associatedButtonList_;
};


#endif // ANIMATIONBUTTONINFO_H
