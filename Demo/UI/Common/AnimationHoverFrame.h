#ifndef ANIMATIONHOVERFRAME_H
#define ANIMATIONHOVERFRAME_H

#include <QWidget>
#include "QFrame"
#include <QMap>
#include "AnimationButtonInfo.h"
class QHBoxLayout;
class QAction;
class AnimationPushButton;

class AnimationHoverFrame : public QFrame
{
    Q_OBJECT
public:
    explicit AnimationHoverFrame(int nIndex, const AnimationButtonInfo infos, QWidget *parent = nullptr);

    void InsertAnimationButton(int index, AnimationPushButton* button);
    AnimationPushButton* takeAt(int index);
    void InitData(const QList<AnimationButtonInfo>& infos);
    void InitData(const AnimationButtonInfo infos);
    AnimationPushButton* GetAnimationButton(int nIndex);
    QList<AnimationPushButton*> GetButtonList() const;
signals:
    void switchButtonSgn(int,int);
public slots :
    void onAnimationClicked();
protected:
	bool eventFilter(QObject* object, QEvent* event);
private:
	QHBoxLayout* animationLayout_ = nullptr;
    int associatedIndex_ = -1;
    QList<AnimationPushButton*> animationPushButtonList_;
};

#endif // ANIMATIONHOVERFRAME_H
