#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include <netComm/UdpTool.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_send_clicked();
    void dealReceivedData(QByteArray array);

private:
    Ui::MainWindow *ui;
    //用来控制UDP发送和写入的工具类
    UdpTool udpTool;
    //目前我是准备把UDP的接收和发送数据整进来
    QThread *udpThread;
};

#endif // MAINWINDOW_H
