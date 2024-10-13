#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->hSlider, SIGNAL(valueChanged(int)), this, SLOT(slot_valueChanged(int)));
    //hSlider와 SLOT의 valueChanged와 연결

    //connect(this,SIGNAL(sig_textChanged(QString)),this,SLOT(slot_textChanged(QString)));
    connect(this, &Widget::sig_textChanged,this,&Widget::slot_textChanged);
}
void Widget::slot_valueChanged(int val)
{
    QString str = QString("%1").arg(val);
    ui->leText->setText(str);

    emit sig_textChanged(str);
    //시그널을 발생할 때 쓰는 키워드 emit
}

void Widget::slot_textChanged(QString str)
{
    ui->leText2->setText(str);
}
Widget::~Widget()
{
    delete ui;
}
