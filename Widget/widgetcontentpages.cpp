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
    connect(AppSignal::getInstance(), &AppSignal::sgl_change_app_menu, this, &WidgetContentPages::slot_change_app_menu);

    QGridLayout *layout = new QGridLayout(ui->scrollAreaWidgetContents);
    layout->setContentsMargins(0, 0, 0, 0);

    ui->scrollAreaWidgetContents->setLayout(layout);

}

void WidgetContentPages::slot_change_app_menu(const QString &menu)
{
    auto list = ui->scrollAreaWidgetContents->children();
    for (auto &child : list)
    {
        if (!child->objectName().contains("mtr1994")) continue;
        child->deleteLater();
    }

    if (menu == "统计分析")
    {
        WidgetStatistics *widget = new WidgetStatistics(ui->scrollArea);
        widget->setObjectName("mtr1994_WidgetStatistics");

        ui->scrollAreaWidgetContents->layout()->addWidget(widget);
    }
}
