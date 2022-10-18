#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "windows.h"
// test
#include <QDebug>
#include <QStyle>

// 程序设计来源于 https://www.ui.cn/detail/634573

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();

    setWindowTitle("客户端管理程序模板");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    // 无边框 和 透明底色 在 Qt 1.15.2 中，跟 QTableView 的刷新有冲突，会导致界面闪烁 （已处理）
    // 在 Qt 6.2.4 LTS 中不存在这个问题

    // Qt::MSWindowsFixedSizeDialogHint 用于处理拉伸闪烁
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::MSWindowsFixedSizeDialogHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // 浮动按钮
    ui->btnMin->setID(FlatToolButton::Button_Min);
    connect(ui->btnMin, &QPushButton::clicked, this, [this] { this->showMinimized(); });
    ui->btnClose->setID(FlatToolButton::Button_Close);
    connect(ui->btnClose, &QPushButton::clicked, this, [this] { this->close(); });
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->pos().x() > ui->widgetTitleBase->width() + ui->widgetTitleBase->x() || event->pos().y() > ui->widgetTitleBase->height() + ui->widgetTitleBase->y()) return;
    if (event->button() == Qt::LeftButton)
    {
        mLastMousePosition = event->globalPos();
        mMousePressed = true;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mMousePressed = false;
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!mMousePressed) return;
    if (!event->buttons().testFlag(Qt::LeftButton)) return;
    const QPointF position = pos() + event->globalPos() - mLastMousePosition;
    move(position.x(), position.y());
    mLastMousePosition = event->globalPos();
}
