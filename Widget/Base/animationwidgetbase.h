#ifndef ANIMATIONWIDGETBASE_H
#define ANIMATIONWIDGETBASE_H

#include <QWidget>

class QPropertyAnimation;
class AnimationWidgetBase : public QWidget
{
    Q_OBJECT
public:
    explicit AnimationWidgetBase(QWidget *parent = nullptr);

    void init();

    virtual void showContent();

signals:
    void sgl_widget_animation_finished();

private:
    // 位置动画
    QPropertyAnimation *mAnimationPosition = nullptr;
};

#endif // ANIMATIONWIDGETBASE_H
