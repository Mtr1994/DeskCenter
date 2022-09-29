#ifndef WIDGETSTATISTICS_H
#define WIDGETSTATISTICS_H

#include <QWidget>

#include "../Base/animationwidgetbase.h"

namespace Ui {
class WidgetStatistics;
}

class JsContext;
class QStandardItemModel;
class WidgetStatistics : public AnimationWidgetBase
{
    Q_OBJECT

public:
    enum {FIELD_DATE = 0, FIELD_PRIMARY_SCREENING, FIELD_PRIMARY_SCREENING_PASS, FIELD_INTERVIEW,
          FIELD_INTERVIEW_PASS, FIELD_EMPLOYMENT, FIELD_SEND_OFFER, FIELD_TO_BE_EMPLOYED, FIELD_EMPLOYED, FIELD_OBSOLETE};
    explicit WidgetStatistics(QWidget *parent = nullptr);
    ~WidgetStatistics();

    void init();

private:
    void loadSubContent() override;

    void loadResumeChart();

    void loadPostChart();

private slots:
    void slot_btn_need_people_clicked();

private:
    Ui::WidgetStatistics *ui;

    QStandardItemModel *mModelRecruit = nullptr;

    // web 通信
    JsContext *mJsContextResume = nullptr;
    JsContext *mJsContextPost = nullptr;
};

#endif // WIDGETSTATISTICS_H
