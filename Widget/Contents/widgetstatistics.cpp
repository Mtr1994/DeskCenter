#include "widgetstatistics.h"
#include "ui_widgetstatistics.h"

#include <QPropertyAnimation>
#include <QStandardItemModel>

WidgetStatistics::WidgetStatistics(QWidget *parent) :
    AnimationWidgetBase(parent),
    ui(new Ui::WidgetStatistics)
{
    ui->setupUi(this);

    init();
}

WidgetStatistics::~WidgetStatistics()
{
    delete ui;
}

void WidgetStatistics::init()
{
    mModelRecruit = new QStandardItemModel;

    ui->tvRecruitInfo->setContentsMargins(0, 9, 0, 9);

    mModelRecruit->setHorizontalHeaderItem(FIELD_DATE, new QStandardItem(tr("日期")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_PRIMARY_SCREENING, new QStandardItem(tr("初筛")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_PRIMARY_SCREENING_PASS, new QStandardItem(tr("初筛通过")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_INTERVIEW, new QStandardItem(tr("面试")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_INTERVIEW_PASS, new QStandardItem(tr("面试通过")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_EMPLOYMENT, new QStandardItem(tr("录用")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_SEND_OFFER, new QStandardItem(tr("发offer")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_TO_BE_EMPLOYED, new QStandardItem(tr("待入职")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_EMPLOYED, new QStandardItem(tr("已入职")));
    mModelRecruit->setHorizontalHeaderItem(FIELD_OBSOLETE, new QStandardItem(tr("已淘汰")));

    ui->tvRecruitInfo->verticalHeader()->setVisible(false);
    ui->tvRecruitInfo->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tvRecruitInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    QFont font("Microsoft YaHei", 10);
    QFontMetrics metrics(font);
    ui->tvRecruitInfo->verticalHeader()->setDefaultSectionSize(metrics.height() * 2.4);

    // 测试数据
    for (int i = 0; i < 7; i++)
    {
        QList<QStandardItem*> lstItem;
        lstItem.insert(FIELD_DATE, new QStandardItem("2022-10-03"));
        lstItem.insert(FIELD_PRIMARY_SCREENING, new QStandardItem("48600"));
        lstItem.insert(FIELD_PRIMARY_SCREENING_PASS, new QStandardItem("38600"));
        lstItem.insert(FIELD_INTERVIEW, new QStandardItem("38600"));
        lstItem.insert(FIELD_INTERVIEW_PASS, new QStandardItem("38600"));
        lstItem.insert(FIELD_EMPLOYMENT, new QStandardItem("28600"));
        lstItem.insert(FIELD_SEND_OFFER, new QStandardItem("28600"));
        lstItem.insert(FIELD_TO_BE_EMPLOYED, new QStandardItem("28600"));
        lstItem.insert(FIELD_EMPLOYED, new QStandardItem("28600"));
        lstItem.insert(FIELD_OBSOLETE, new QStandardItem("28600"));

        mModelRecruit->appendRow(lstItem);
    }

    ui->tvRecruitInfo->setModel(mModelRecruit);
}
