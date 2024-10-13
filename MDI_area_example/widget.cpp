#include "widget.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(600,400);
    QMdiArea *area = new QMdiArea();
    area -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  //가로 세로 크기 같이 늘어나라는 코드
    //MdiArea는 가장 상위 영역


    //Sub에다가 위젯을 넣었음.
    QMdiSubWindow *subWindow1 = new QMdiSubWindow();
    subWindow1 -> resize(300,200);

    QPushButton *btn = new QPushButton("버튼");
    subWindow1->setWidget(btn); //버튼을 subWindow에 등록

    QMdiSubWindow *subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300,200);    //두번째 subWindow는 아무것도 등록안함.

    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);
    //subWindow1,2를 area에 등록.
    QHBoxLayout *hLay  = new QHBoxLayout(); // horizontal Layout 생성.

    hLay -> addWidget(area);    //MdiArea 등록.

    setLayout(hLay);
}

Widget::~Widget() {

}
