#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class AnimationFrame;
class GraphicWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

private:
    void initUI();

private:
    AnimationFrame* popupButtonFrame_ = nullptr;
};

#endif // MAINWINDOW_H
