#include "gamewidget.h"
#include "ui_gamewidget.h"

gameWidget::gameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    ui->setupUi(this);
}

gameWidget::~gameWidget()
{
    delete ui;
}
