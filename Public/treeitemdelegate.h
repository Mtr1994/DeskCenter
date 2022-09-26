#ifndef TREEITEMDELEGATE_H
#define TREEITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QPainter>
#include <QRect>
#include <QImage>
#include <QUrl>

// test
#include <QDebug>

class TreeItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TreeItemDelegate(){}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QRect rect(option.rect);
        rect.setLeft(rect.height() * 2);

        QBrush brush;
        QColor color;
        QString url;

        if (option.state & QStyle::State_Selected )
        {
            color = QColor(76, 166, 168);
            brush = QBrush(QColor(255, 255, 255));
            url = index.data(Qt::UserRole + 2).toString();
        }
        else if (option.state & QStyle::State_MouseOver)
        {
            color = QColor(130, 138, 151);
            brush = QBrush(QColor(247, 247, 249));
            url = index.data(Qt::UserRole + 1).toString();
        }
        else
        {
            color = QColor(130, 138, 151);
            brush = QBrush(QColor(255, 255, 255));
            url = index.data(Qt::UserRole + 1).toString();
        }

        painter->setPen(Qt::NoPen);
        painter->setBrush(brush);
        painter->drawRoundedRect(option.rect, 3, 3);

        // 绘制图标
        QRect rectImage(option.rect);
        rectImage.setLeft(rect.height() * 0.5);
        rectImage.setWidth(rect.height());
        rectImage.adjust(0, rect.height() * 0.2, -rect.height() * 0.4, -rect.height() * 0.2);

        painter->setRenderHint(QPainter::SmoothPixmapTransform);
        painter->drawImage(rectImage, QImage(url));

        // 绘制文本
        painter->setPen(color);
        painter->drawText(rect, Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());
    }
};

#endif // TREEITEMDELEGATE_H
