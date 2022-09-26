#include "widgetstatistics.h"
#include "ui_widgetstatistics.h"

WidgetStatistics::WidgetStatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetStatistics)
{
    ui->setupUi(this);
}

WidgetStatistics::~WidgetStatistics()
{
    delete ui;
}
