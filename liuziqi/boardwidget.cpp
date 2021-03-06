#include "boardwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QFile>
#include <QDataStream>

const QSize  boardwidget::widget_size(650,650);
const QSize  boardwidget::cell_size(25,25);
const QPoint boardwidget::start_pos(40,40);
const QPoint boardwidget::row_num_start(15,45);
const QPoint boardwidget::clu_num_start(39,25);
const int    boardwidget::board_width;
const int    boardwidget::board_height;
const int    boardwidget::no_piece;
const int    boardwidget::white_piece;
const int    boardwidget::black_piece;
const bool   boardwidget::white_player;
const bool   boardwidget::black_player;

boardwidget::boardwidget(QWidget *parent):

    QWidget(parent),
    trackpos(28,28)
    {
        setFixedSize(widget_size);
        setMouseTracking(true);

        initboard();
    }

void boardwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),Qt::lightGray);//背景颜色

    for (int i = 0;i < board_width; i++)
    {
        painter.drawText(clu_num_start+QPoint(i * cell_size.width(),0),
                         QString::number(i + 1));
    }
    for (int i = 0;i < board_height;i++)
    {
        painter.drawText(row_num_start + QPoint(0,i * cell_size.height()),
                         QString::number(i + 1));
    }

    for (int i = 0;i < board_width - 1; i++)  //绘制棋盘格子
    {
        for(int j = 0; j < board_height - 1; j++)
        {
            painter.drawRect(QRect(start_pos + QPoint(i *cell_size.width(),j *cell_size.height()),
                                   cell_size));
        }
    }
};




