#include "widgetstatistics.h"
#include "ui_widgetstatistics.h"
#include "Channel/jscontext.h"

#include <QPropertyAnimation>
#include <QStandardItemModel>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QWebChannel>
#include <QWebEngineScript>
#include <QGridLayout>

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

    // 单选按钮组
    connect(ui->btnNeedPeople, &QPushButton::clicked, this, &WidgetStatistics::slot_btn_need_people_clicked);
}

void WidgetStatistics::loadSubContent()
{
    // 加载简历图表
    loadResumeChart();

    // 加载岗位图表
    loadPostChart();
}

void WidgetStatistics::loadResumeChart()
{
    QWebEngineView *widgetview = new QWebEngineView(ui->widgetResumeContainer);
    widgetview->setContextMenuPolicy(Qt::NoContextMenu);

    widgetview->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);
    widgetview->settings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);
    widgetview->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);

    widgetview->page()->load(QUrl(QString("%1/../Resource/html/index.html").arg(QApplication::applicationDirPath())).toString());
    widgetview->page()->setBackgroundColor(QColor(255, 255, 255));

    mJsContextResume = new JsContext(this);
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject("context", mJsContextResume);
    widgetview->page()->setWebChannel(channel);

    connect(mJsContextResume, &JsContext::sgl_init_channel_finished, this, [this]{ emit mJsContextResume->sgl_load_new_chart("resume"); });

//    ////// 网页调试部分，发布时请注释此段代码 S
//    QWebEngineView *debuPage = new QWebEngineView;
//    widgetview->page()->setDevToolsPage(debuPage->page());
//    widgetview->page()->triggerAction(QWebEnginePage::WebAction::InspectElement);
//    debuPage->show();
//    ////// 网页调试部分，发布时请注释此段代码 E

    QGridLayout *layout = new QGridLayout(ui->widgetResumeContainer);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(widgetview);
    ui->widgetResumeContainer->setLayout(layout);
}

void WidgetStatistics::loadPostChart()
{
    QWebEngineView *widgetview = new QWebEngineView(ui->widgetPostContainer);
    widgetview->setContextMenuPolicy(Qt::NoContextMenu);

    widgetview->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);
    widgetview->settings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);
    widgetview->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);

    widgetview->page()->load(QUrl(QString("%1/../Resource/html/index.html").arg(QApplication::applicationDirPath())).toString());
    widgetview->page()->setBackgroundColor(QColor(255, 255, 255));

    mJsContextPost = new JsContext(this);
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject("context", mJsContextPost);
    widgetview->page()->setWebChannel(channel);

    connect(mJsContextPost, &JsContext::sgl_init_channel_finished, this, [this]{ emit mJsContextPost->sgl_load_new_chart("post"); });

//    ////// 网页调试部分，发布时请注释此段代码 S
//    QWebEngineView *debuPage = new QWebEngineView;
//    widgetview->page()->setDevToolsPage(debuPage->page());
//    widgetview->page()->triggerAction(QWebEnginePage::WebAction::InspectElement);
//    debuPage->show();
//    ////// 网页调试部分，发布时请注释此段代码 E

    QGridLayout *layout = new QGridLayout(ui->widgetPostContainer);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(widgetview);
    ui->widgetPostContainer->setLayout(layout);
}

void WidgetStatistics::slot_btn_need_people_clicked()
{
    //
}
