#include "widgethomepage.h"
#include "ui_widgethomepage.h"

#include <QStandardItemModel>

WidgetHomePage::WidgetHomePage(QWidget *parent) :
    AnimationWidgetBase(parent),
    ui(new Ui::WidgetHomePage)
{
    ui->setupUi(this);

    init();
}

WidgetHomePage::~WidgetHomePage()
{
    delete ui;
}

void WidgetHomePage::init()
{
    mModelRecv = new QStandardItemModel;

    ui->tvRecruitInfo->setContentsMargins(0, 9, 0, 9);

    mModelRecv->setHorizontalHeaderItem(FIELD_DATE, new QStandardItem(tr("日期")));
    mModelRecv->setHorizontalHeaderItem(FIELD_PRIMARY_SCREENING, new QStandardItem(tr("初筛")));
    mModelRecv->setHorizontalHeaderItem(FIELD_PRIMARY_SCREENING_PASS, new QStandardItem(tr("初筛通过")));
    mModelRecv->setHorizontalHeaderItem(FIELD_INTERVIEW, new QStandardItem(tr("面试")));
    mModelRecv->setHorizontalHeaderItem(FIELD_INTERVIEW_PASS, new QStandardItem(tr("面试通过")));
    mModelRecv->setHorizontalHeaderItem(FIELD_EMPLOYMENT, new QStandardItem(tr("录用")));
    mModelRecv->setHorizontalHeaderItem(FIELD_SEND_OFFER, new QStandardItem(tr("发offer")));
    mModelRecv->setHorizontalHeaderItem(FIELD_TO_BE_EMPLOYED, new QStandardItem(tr("待入职")));
    mModelRecv->setHorizontalHeaderItem(FIELD_EMPLOYED, new QStandardItem(tr("已入职")));
    mModelRecv->setHorizontalHeaderItem(FIELD_OBSOLETE, new QStandardItem(tr("已淘汰")));

    ui->tvRecruitInfo->verticalHeader()->setVisible(false);
    ui->tvRecruitInfo->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tvRecruitInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tvRecruitInfo->setModel(mModelRecv);

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

        mModelRecv->appendRow(lstItem);
    }
}
