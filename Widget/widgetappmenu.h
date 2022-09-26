#ifndef WIDGETAPPMENU_H
#define WIDGETAPPMENU_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class WidgetAppMenu;
}

class WidgetAppMenu : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetAppMenu(QWidget *parent = nullptr);
    ~WidgetAppMenu();

    void init();

private slots:
     void slot_current_item_changed(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::WidgetAppMenu *ui;

    QStandardItemModel mMenuItemModel;
};

#endif // WIDGETAPPMENU_H
