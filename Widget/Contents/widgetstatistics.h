#ifndef WIDGETSTATISTICS_H
#define WIDGETSTATISTICS_H

#include <QWidget>

#include "../Base/animationwidgetbase.h"

namespace Ui {
class WidgetStatistics;
}

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
    Ui::WidgetStatistics *ui;

    QStandardItemModel *mModelRecruit = nullptr;
};

#endif // WIDGETSTATISTICS_H
