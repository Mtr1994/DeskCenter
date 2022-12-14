#include "animationwidgetbase.h"

#include <QPropertyAnimation>
#include <QTimer>

// test
#include <QDebug>

AnimationWidgetBase::AnimationWidgetBase(QWidget *parent)
    : QWidget{parent}
{
    init();
}

void AnimationWidgetBase::init()
{
    qDebug() << "AnimationWidgetBase::init() ";
    // 位置动画
    mAnimationPosition = new QPropertyAnimation(this, "pos", this);
    mAnimationPosition->setDuration(200);

    QFont font("Microsoft YaHei", 10);
    QFontMetrics metrics(font);

    mAnimationPosition->setStartValue(QPoint(0, metrics.height() * 4));
    mAnimationPosition->setEndValue(QPoint(0, 0));
    mAnimationPosition->setEasingCurve(QEasingCurve::OutBounce);

    connect(mAnimationPosition, &QPropertyAnimation::finished, this, [this]
    {
        // 加载额外的模块
        QTimer::singleShot(200, this, [this]{ loadSubContent(); });

        emit sgl_widget_animation_finished();
    });
}

void AnimationWidgetBase::showContent()
{
    if (nullptr != mAnimationPosition)
    {
        mAnimationPosition->start(QPropertyAnimation::DeleteWhenStopped);
    }
    show();

    qDebug() << "AnimationWidgetBase::showContent";
}

void AnimationWidgetBase::loadSubContent()
{
    //
}
