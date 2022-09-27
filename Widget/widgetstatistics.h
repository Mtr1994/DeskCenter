#ifndef WIDGETSTATISTICS_H
#define WIDGETSTATISTICS_H

#include <QWidget>
#include <QStandardItemModel>

#include <QPropertyAnimation>

namespace Ui {
class WidgetStatistics;
}

class WidgetStatistics : public QWidget
{
    Q_OBJECT

public:
    enum {FIELD_DATE = 0, FIELD_PRIMARY_SCREENING, FIELD_PRIMARY_SCREENING_PASS, FIELD_INTERVIEW,
          FIELD_INTERVIEW_PASS, FIELD_EMPLOYMENT, FIELD_SEND_OFFER, FIELD_TO_BE_EMPLOYED, FIELD_EMPLOYED, FIELD_OBSOLETE};
    explicit WidgetStatistics(QWidget *parent = nullptr);
    ~WidgetStatistics();

    void init();

    void showContent();

signals:
    void sgl_widget_animation_finished();

private:
    Ui::WidgetStatistics *ui;

    QStandardItemModel mModelRecruit;

    // 动画组
    QPropertyAnimation *mAnimationPosition = nullptr;
};

#endif // WIDGETSTATISTICS_H
