/******************************************************************************
  @Project Name  : MyUDPTest
  @File Name     : UdpTool.cpp
  @Version       : 1.0
  @Function      : to be determined
  @Author        : unishuai
  @Date          : 2024-06-12
******************************************************************************/

#include "UdpTool.h"
#include <QtNetwork>
#include <iostream>
#ifndef MY_DEBUG_INFO
#define MY_DEBUG_INFO true
#endif
UdpTool::UdpTool(QObject* parent) : QObject(parent) {


    //初始化网络参数
    initParam();
    senderhost.setAddress("127.0.0.1");  // Initialize with a specific IP address.
    senderport = 8101;
    if(MY_DEBUG_INFO){
        qDebug() << "UdpTool constructor: " << QThread::currentThreadId();
    }

}

UdpTool::~UdpTool() {
//    socket->close();
//    delete socket;
    socket = nullptr;
}

void UdpTool::SetLocalNetParameter(NetParameter parameter) {
    netParameter.localhost = parameter.localhost;
    netParameter.localport = parameter.localport;
    netParameter.remotehost = parameter.remotehost;
    netParameter.remoteport = parameter.remoteport;
}

NetParameter UdpTool::GetLocalNetParameter() {
    return netParameter;
}
//初始化socket，绑定本机ip和端口号，连接信号和槽
void UdpTool::InitSocket() {
    if(MY_DEBUG_INFO){
        qDebug() << "UdpReceiver InitSocket: " << QThread::currentThreadId();
    }

    socket = new QUdpSocket;
    socket->bind(QHostAddress(netParameter.localhost),
                  netParameter.localport,
                  QUdpSocket::ShareAddress);
    connect(socket, &QUdpSocket::readyRead, this, &UdpTool::ReceiveData);
}
//取出管道中的数据，并发送信号
void UdpTool::ReceiveData() {
    if(MY_DEBUG_INFO){
        qDebug() << "UdpReceiver ReceiveData: " << QThread::currentThreadId();
    }
    while (socket->hasPendingDatagrams()) {
        QByteArray array;
        array.resize(socket->pendingDatagramSize());
        socket->readDatagram(array.data(), array.size());
//        std::cout<<"array "<<QString::fromUtf8(array).toStdString()<<std::endl;
        emit ReceivedData(array);

    }
}

//取出管道中的数据，并获取发送者的信息，发送信号
void UdpTool::ReceiveDataAndSender() {
    if(MY_DEBUG_INFO){
        qDebug() << "UdpReceiver ReceiveData: " << QThread::currentThreadId();
    }
    while (socket->hasPendingDatagrams()) {
        QByteArray array;
        array.resize(socket->pendingDatagramSize());
        socket->readDatagram(array.data(), array.size(),&senderhost,&senderport);
        emit ReceivedDataAndSenderSignal(array,senderhost,senderport);

    }
}

void UdpTool::sendData(QByteArray array)
{
    socket->writeDatagram(array, QHostAddress(netParameter.remotehost),netParameter.remoteport);
}

void UdpTool::sendData(QByteArray array, QHostAddress senderhost, quint16 senderport)
{
    socket->writeDatagram(array, senderhost,senderport);
}

void UdpTool::initParam()
{
    QSettings settings("./configFile/configDB.ini",QSettings::IniFormat);
    //读取UDP配置
    settings.beginGroup("udp");
    QString localhost = settings.value("localhost").toString();
    int localport = settings.value("localport").toInt();
    QString remotehost = settings.value("remotehost").toString();
    int remoteport = settings.value("remoteport").toInt();
    settings.endGroup();

    netParameter.localhost = localhost.trimmed() ;
    netParameter.localport = localport;
    netParameter.remotehost = remotehost.trimmed();
    netParameter.remoteport = remoteport;

    if(MY_DEBUG_INFO){
        // 输出读取的配置，以验证
        qDebug() << "Local Host:" << localhost;
        qDebug() << "Local Port:" << localport;
        qDebug() << "Remote Host:" << remotehost;
        qDebug() << "Remote Port:" << remoteport;
    }

}
