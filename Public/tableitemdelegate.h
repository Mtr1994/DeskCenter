#ifndef TABLEITEMDELEGATE_H
#define TABLEITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QItemDelegate>

// test
#include <QDebug>

class TableItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit TableItemDelegate(){}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QStyleOptionViewItem viewOption(option);
        //高亮显示与普通显示时的前景色一致（即选中行和为选中时候的文字颜色一样）
        viewOption.palette.setColor(QPalette::HighlightedText, index.data(Qt::ForegroundRole).value<QColor>());
        // 高亮背景色
        viewOption.palette.setBrush(QPalette::Highlight, QBrush(QColor("#e5e5e9")));
        if (option.state.testFlag(QStyle::State_HasFocus))
        {
            viewOption.state = viewOption.state ^ QStyle::State_HasFocus;
        }

        QItemDelegate::paint(painter, viewOption, index);
    }
};

#endif // TABLEITEMDELEGATE_H
