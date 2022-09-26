#ifndef WIDGETCONTENTPAGES_H
#define WIDGETCONTENTPAGES_H

#include <QWidget>

namespace Ui {
class WidgetContentPages;
}

class WidgetContentPages : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetContentPages(QWidget *parent = nullptr);
    ~WidgetContentPages();

    void init();

private slots:
    void slot_change_app_menu(const QString &menu);

private:
    Ui::WidgetContentPages *ui;
};

#endif // WIDGETCONTENTPAGES_H
