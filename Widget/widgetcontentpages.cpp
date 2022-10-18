#include "widgetcontentpages.h"
#include "ui_widgetcontentpages.h"
#include "Public/appsignal.h"
#include "Widget/Contents/widgetstatistics.h"
#include "Widget/Contents/widgethomepage.h"

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

    AnimationWidgetBase *widget = new WidgetHomePage(this);
    widget->setObjectName("mtr1994_WidgetHomepage");
    this->layout()->addWidget(widget);
}

void WidgetContentPages::slot_change_app_menu(const QString &menu)
{
    auto list = this->children();
    for (auto &child : list)
    {
        if (!child->objectName().contains("mtr1994")) continue;
        child->deleteLater();
    }

    AnimationWidgetBase *widget = nullptr;
    if (menu == "统计分析")
    {
        widget = new WidgetStatistics(this);
        widget->setObjectName("mtr1994_WidgetStatistics");
    }
    else if (menu == "概览")
    {
        widget = new WidgetHomePage(this);
        widget->setObjectName("mtr1994_WidgetHomepage");
    }

    if (nullptr == widget) return;

    widget->resize(this->width(), this->height());
    widget->showContent();

    connect(widget, &WidgetStatistics::sgl_widget_animation_finished, this, [this, widget]{ this->layout()->addWidget(widget); });
}
