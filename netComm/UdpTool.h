#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H
/******************************************************************************
  @Project Name  : MyUDPTest
  @File Name     : UdpTool.h
  @Version       : 1.0
  @Function      : to be determined
  @Author        : unishuai
  @Date          : 2024-06-12
******************************************************************************/

#include <QHostAddress>
#include <QObject>

class QUdpSocket;
//用来存储接收和发送的UDP端口和ID
class NetParameter {
public:
    QString localhost;
    int localport;
    QString remotehost;
    int remoteport;
};

//这个就是一个用来接收和发送UDP数据的工具类
class UdpTool : public QObject {
    Q_OBJECT
  public:
    explicit UdpTool(QObject* parent = nullptr);
    ~UdpTool();



    void SetLocalNetParameter(NetParameter parameter);
    NetParameter GetLocalNetParameter();

  public slots:
    /*
     * 初始化需要声明为槽，
     * 将该类moveToThread时，
     * 该类中的所有槽函数在新线程中运行，
     * 初始化声明为普通函数会导致
     * socket的初始化和使用不在同一个线程
     */
    void InitSocket();//初始化udp socket
    void initParam();//初始化NetParameter参数


    void ReceiveData();//取出管道的数据
    void ReceiveDataAndSender();//取出管道的数据和发送者
    //发送数据，这里没有指定发送者的信息，直接用默认的网络参数里面的就好
    void sendData(QByteArray array);
    void sendData(QByteArray array,QHostAddress senderhost,quint16 senderport);


  private:
    QUdpSocket* socket;
    NetParameter netParameter;
    QHostAddress senderhost;
    quint16 senderport;


  signals:
    void ReceivedData(QByteArray array);
    void ReceivedDataAndSenderSignal(QByteArray array,QHostAddress senderhost,quint16 senderport);

};

#endif // UDPRECEIVER_H
