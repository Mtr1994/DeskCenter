#ifndef WIDGETSTATISTICS_H
#define WIDGETSTATISTICS_H

#include <QWidget>

namespace Ui {
class WidgetStatistics;
}

class WidgetStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetStatistics(QWidget *parent = nullptr);
    ~WidgetStatistics();

private:
    Ui::WidgetStatistics *ui;
};

#endif // WIDGETSTATISTICS_H
