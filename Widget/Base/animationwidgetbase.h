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

    void showContent();

private:
    // 用于加载哪些需要额外动态库的组件（使用代码控制）
    virtual void loadSubContent();

signals:
    void sgl_widget_animation_finished();

private:
    // 位置动画
    QPropertyAnimation *mAnimationPosition = nullptr;
};

#endif // ANIMATIONWIDGETBASE_H
