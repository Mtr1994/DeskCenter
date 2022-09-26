#include "widgetappmenu.h"
#include "ui_widgetappmenu.h"
#include "Public/treeitemdelegate.h"
#include "Public/appsignal.h"

WidgetAppMenu::WidgetAppMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetAppMenu)
{
    ui->setupUi(this);

    init();
}

WidgetAppMenu::~WidgetAppMenu()
{
    delete ui;
}

void WidgetAppMenu::init()
{
    // 左侧菜单按钮
    ui->lvMenuItem->setItemAlignment(Qt::AlignVCenter);
    ui->lvMenuItem->setItemDelegate(new TreeItemDelegate());

    ui->lvMenuItem->setContentsMargins(0, 9, 0, 9);

    QFont font("Microsoft YaHei", 10);
    QFontMetrics metrics(font);
    ui->lvMenuItem->setGridSize(QSize(0, metrics.height() * 3.2));

    QStringList listIcon = {"homepage", "businesscard", "label", "workbench", "share", "clock", "people", "praise", "dynamic", "setup"};

    QList<QStandardItem*> list =
    {
        new QStandardItem("概览"), new QStandardItem("简历管理"), new QStandardItem("测评管理"), new QStandardItem("职位管理"), new QStandardItem("面试管理"),
        new QStandardItem("内推管理"), new QStandardItem("人才管理"), new QStandardItem("运营管理"), new QStandardItem("统计分析"), new QStandardItem("系统设置")
    };

    for (int i = 0; i < list.size(); i++)
    {
        list.at(i)->setData(QString(":/Resource/image/menu/%1.svg").arg(listIcon.at(i)), Qt::UserRole + 1);
        list.at(i)->setData(QString(":/Resource/image/menu/%1_fill.svg").arg(listIcon.at(i)), Qt::UserRole + 2);
    }

    mMenuItemModel.appendColumn(list);

    // 只读
    ui->lvMenuItem->setEditTriggers(QListView::NoEditTriggers);

    ui->lvMenuItem->setModel(&mMenuItemModel);
    ui->lvMenuItem->setCurrentIndex(mMenuItemModel.index(0, 0));

    // 左侧菜单点击信号
    connect(ui->lvMenuItem->selectionModel(), &QItemSelectionModel::currentChanged, this, &WidgetAppMenu::slot_current_item_changed);
}

void WidgetAppMenu::slot_current_item_changed(const QModelIndex &current, const QModelIndex &previous)
{
    if (!previous.isValid()) return;

    qDebug() << "current item " << current.data(Qt::DisplayRole).toString();

    emit AppSignal::getInstance()->sgl_change_app_menu(current.data(Qt::DisplayRole).toString());
}
