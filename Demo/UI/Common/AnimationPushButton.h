#ifndef ANIMATIONPUSHBUTTON_H
#define ANIMATIONPUSHBUTTON_H

#include <QWidget>
#include "QToolButton"
#include "QPushButton"

class QFrame;
class AnimationPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit AnimationPushButton(QWidget *parent = nullptr);
    ~AnimationPushButton();
};

#endif // ANIMATIONPUSHBUTTON_H
