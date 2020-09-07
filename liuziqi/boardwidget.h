#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QStack>
#include <QPoint>
#include <QSet>
typedef int(*board)[20];


class boardwidget : public QWidget
{
    Q_OBJECT
public:
    explicit boardwidget(QWidget *parent = nullptr);

    void setreceiveplays(const QSet <int> &value);
    //设置下棋方
    board getboard();

protected:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void initboard();
    void switchnextplays();
    //跳转下一个下棋方
    void checkwinner();
    //检查获胜方
    bool issixpiecefrom   (int x,int y);
    //检查直线是否有六子
    bool isvsixpiecefrom  (int x,int y);
    //上方是否六子
    bool ishsixpiecefrom  (int x,int y);
    //下方是否六子
    bool isfssixpiecefrom (int x,int y);
    //右上是否六子
    bool isbssixpiecefrom (int x,int y);
    //右下是否六子


signals:
    void gameover(int winner);
    void turnnextplays(int player);


public slots:
    void newgame();
    void downpiece(int x,int y);
    void undo(int steps);  //悔棋

public:
    static const QSize widget_size;
    static const QSize cell_size;
    static const QPoint start_pos;//棋盘单元格开始位置
    static const QPoint row_num_start;
    static const QPoint clu_num_start;
    static const int   board_width = 20;
    static const int   board_height = 20;
    static const int   no_piece = 0;
    static const int   white_piece = 1;
    static const int   black_piece = 2;
    static const bool  white_player = true; //白方
    static const bool  black_player = false;//黑方

    void settrackpos(const QPoint &value); //当前鼠标位置

private:
    bool endgame;
    int board[board_width][board_height];
    int nextplayer;
    QPoint trackpos;
    QVector<QPoint> winposes;
    QSet<int> receivepplayers;
    QStack<QPoint> dropedpieces;//每一步落子位置


};

#endif // BOARDWIDGET_H
