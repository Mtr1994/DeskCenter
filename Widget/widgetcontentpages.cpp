#include "widgetcontentpages.h"
#include "ui_widgetcontentpages.h"
#include "Public/appsignal.h"
#include "Widget/widgetstatistics.h"

#include <QGridLayout>

// test
#include <QDebug>

WidgetContentPages::WidgetContentPages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetContentPages)
{
    ui->setupUi(this);

    init();
}

WidgetContentPages::~WidgetContentPages()
{
    delete ui;
}

void WidgetContentPages::init()
{
    QGridLayout *layout = new QGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    connect(AppSignal::getInstance(), &AppSignal::sgl_change_app_menu, this, &WidgetContentPages::slot_change_app_menu);
}

void WidgetContentPages::slot_change_app_menu(const QString &menu)
{

    auto list = this->children();
    for (auto &child : list)
    {
        if (!child->objectName().contains("mtr1994")) continue;
        child->deleteLater();
    }

    if (menu == "统计分析")
    {
        WidgetStatistics *widget = new WidgetStatistics(this);
        widget->setObjectName("mtr1994_WidgetStatistics");
        widget->setGeometry(0, this->height(), this->width(), this->height());
        widget->showContent();
        connect(widget, &WidgetStatistics::sgl_widget_animation_finished, this, [this, widget]{ this->layout()->addWidget(widget); });
    }
    else if (menu == "概览")
    {
        WidgetStatistics *widget = new WidgetStatistics(this);
        widget->setObjectName("mtr1994_WidgetStatistics");
        widget->setGeometry(0, this->height(), this->width(), this->height());
        widget->showContent();
        connect(widget, &WidgetStatistics::sgl_widget_animation_finished, this, [this, widget]{ this->layout()->addWidget(widget); });
    }
}
