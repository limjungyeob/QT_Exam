#include "mainwindow.h"
#include<QDebug>
#include <QAction>
#include <QMenuBar>
#include<QToolBar>
#include<QDockWidget>
#include <QListWidget>
#include<QMdiArea>
#include<QMdiSubWindow>
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu *fileMenu;

    QAction *newAct;
    QAction *OpenAct;
    //첫 번째 인자 = 아이콘
    //두 번째 인자 = 단축키 tr은 "New"와 다국어로 맵핑해줌.
    newAct = new QAction(QIcon(":/root/resources/new.png"),tr("New"),this);
    //setShortcut하면 어떤 단축키를 쓸수있는지 등록할수 있다.
    newAct->setShortcut(QKeySequence::New);
    //설명을 등록할 수 있다.
    newAct->setStatusTip("Create a new file");
    //newAct와 슬롯함수 연결
    connect(newAct,SIGNAL(triggered(bool)),this,SLOT(slot_newFile()));

    OpenAct = new QAction(QIcon(":/root/resources/open.png"),tr("Open"),this);
    OpenAct->setShortcut(QKeySequence::Open);
    OpenAct->setStatusTip("Open an existing file");
    connect(OpenAct,SIGNAL(triggered(bool)),this,SLOT(slot_open()));

    //addMenu 첫번째 인자 메뉴 이름
    fileMenu = menuBar()->addMenu("&File");
    //만들었던 Action을 QMenu와 연결
    fileMenu->addAction(newAct);
    fileMenu->addAction(OpenAct);

    //QToolBar
    QToolBar *fileToolbar;
    fileToolbar = addToolBar("File");
    fileToolbar->addAction(newAct);
    fileToolbar->addAction(OpenAct);

    //도크 위젯
    QDockWidget *dock = new QDockWidget("Target",this);
    //도크 위젯을 왼쪽 or 오른쪽으로 붙일 수 있음.
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    //도크 위젯을 QListWidget에 붙임.
    QListWidget *customerList = new QListWidget();
    QStringList list;
    list <<  "One" << "Two" << "Three" <<"Four" << "Five";
    customerList -> addItems(list);
    dock->setWidget(customerList);

    //도크위젯을 QMainWindow에 디폴트로 어디를 붙일지 등록
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //Centeral Widget 구성
    QMdiArea *area = new QMdiArea();
    //MdiArea를 확장할 수있는 함수.
    area->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    //MdiArea에 서브 윈도우 구성.
    QMdiSubWindow *subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300,200);

    //간단 Push Button 구성
    QPushButton *btn = new QPushButton();
    subWindow1->setWidget(btn);

    //MdiArea에 두번째 서브 윈도우 구성
    QMdiSubWindow *subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300,200);

    //MdiArea에 서브 윈도우 등록.
    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);

    //Centeral Widget에 MdiArea를 등록
    setCentralWidget(area);
}

void MainWindow::slot_newFile(){
    qDebug() << Q_FUNC_INFO;
}
void MainWindow::slot_open() {
    qDebug() << Q_FUNC_INFO;
}
MainWindow::~MainWindow() {}
