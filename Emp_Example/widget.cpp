#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Connect로 연결
    connect(ui->pbySave,SIGNAL(pressed()),this,SLOT(slot_pbtSave()));
    connect(ui->pbtPrint,SIGNAL(pressed()),this,SLOT(slot_pbtPrint()));
}

void Widget::slot_pbtSave(){
    //UI로부터 값 읽어오기.
    int num = ui->leName->text().toInt();
    QString name = ui->leName->text();
    QString part = ui->lePart->text();

    //구조체 초기화.
    tEmployee  employee;
    employee.num = num;
    employee.name = name;
    employee.part = part;
    //List에 추가.
    m_emplployeeList.append(employee);
    //ui에 넣은 값 clear
    ui->leName->clear();
    ui->leNum->clear();
    ui->lePart->clear();


}

void Widget::slot_pbtPrint(){
    ui->textEdit->clear();

    for(qsizetype i = 0; i< m_emplployeeList.size(); i++ ) {
        int num = m_emplployeeList.at(i).num;
        QString name = m_emplployeeList.at(i).name;
        QString part = m_emplployeeList.at(i).part;

        QString str;
        str = QString("[사원번호 : %1] [성명 : %2] [부서 : %3]").arg(num).arg(name,part);
        ui->textEdit->append(str);
    }

}
Widget::~Widget()
{
    delete ui;
}
