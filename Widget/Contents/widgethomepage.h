#ifndef WIDGETHOMEPAGE_H
#define WIDGETHOMEPAGE_H

#include <QWidget>

#include "../Base/animationwidgetbase.h"

namespace Ui {
class WidgetHomePage;
}

class QStandardItemModel;
class WidgetHomePage : public AnimationWidgetBase
{
    Q_OBJECT

public:
    enum {FIELD_DATE = 0, FIELD_PRIMARY_SCREENING, FIELD_PRIMARY_SCREENING_PASS, FIELD_INTERVIEW,
          FIELD_INTERVIEW_PASS, FIELD_EMPLOYMENT, FIELD_SEND_OFFER, FIELD_TO_BE_EMPLOYED, FIELD_EMPLOYED, FIELD_OBSOLETE};
    explicit WidgetHomePage(QWidget *parent = nullptr);
    ~WidgetHomePage();

    void init();

private:
    Ui::WidgetHomePage *ui;

    QStandardItemModel *mModelRecv = nullptr;
};

#endif // WIDGETHOMEPAGE_H
