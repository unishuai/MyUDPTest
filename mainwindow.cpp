#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <entity/simsysteminfo.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //变量初始化
    udpThread=nullptr;

    ui->pushButton_start->setCheckable(true);

}

MainWindow::~MainWindow()
{
    if(udpThread!=nullptr){
        udpThread->quit();
        udpThread->wait();

        udpThread->deleteLater();
    }
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
    //初始化线程的工具
    //    udpTool.InitSocket();
    if(ui->pushButton_start->isChecked()){
        //初始化线程
        if(udpThread==nullptr){
            udpThread=new QThread;
            //将任务绑定到线程
            udpTool.moveToThread(udpThread);
            //线程开始的时候初始化
            connect(udpThread,&QThread::started,&udpTool,&UdpTool::InitSocket);
            //线程结束的时候，把这个工具类也删除
            //    connect(udpThread,&QThread::finished,&udpTool,&UdpTool::deleteLater);
            //这里就是将收到的数据发送到主线程去处理，我这里就简单测试一下，能不能把这个读取进来
            connect(&udpTool,&UdpTool::ReceivedData,this,&MainWindow::dealReceivedData);
            //将任务绑定到线程
            udpTool.moveToThread(udpThread);
            //捏麻麻的,我这线程没开,应该调用下面
            udpThread->start();

        }else {
            disconnect(&udpTool,&UdpTool::ReceivedData,this,&MainWindow::dealReceivedData);
            connect(&udpTool,&UdpTool::ReceivedData,this,&MainWindow::dealReceivedData);
        }
    }else{
        disconnect(&udpTool,&UdpTool::ReceivedData,this,&MainWindow::dealReceivedData);
    }





}

void MainWindow::on_pushButton_send_clicked()
{
    QString data=ui->lineEdit->text();
    QByteArray datagram=data.toUtf8();
    udpTool.sendData(datagram);
}

void MainWindow::dealReceivedData(QByteArray array)
{

    QString data=QString::fromUtf8(array);
    SimSystemInfo* readData=SimSystemInfo::str2SimSystemInfo(data);
    if(readData==NULL){
        std::cout<<"----"<<std::endl;;
    }else{
        //        std::cout<<"1111";
        std::cout<<*readData<<std::endl;
    }
    //    std::cout<<readData->getSlider01()<<"--"<<readData->getSlider02()<<std::endl;
}
