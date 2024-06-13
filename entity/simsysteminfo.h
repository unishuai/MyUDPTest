#ifndef SIMSYSTEMINFO_H
#define SIMSYSTEMINFO_H
/******************************************************************************
  @Project Name  : 04TestConnectMysql
  @File Name     : simsysteminfo.h
  @Version       : 1.0
  @Function      : to be determined
  @Author        : unishuai
  @Date          : 2024-05-22
******************************************************************************/
#include <QString>
#include<iostream>

class SimSystemInfo
{
public:
    SimSystemInfo();

    //6参数：这种情况就是没有考虑攻角和滚转角的情况
    SimSystemInfo(double slider01,double slider02,double slider03,
                  double slider04,double slider05,double slider06
                  );

    //8参数：只进行仿真的时候调用的构造函数
    SimSystemInfo(double slider01,double slider02,double slider03,
                  double slider04,double slider05,double slider06,
                  double attack_ag,double roll_ag
                  );
//    //
//    SimSystemInfo(double slider01,double slider02,double slider03,
//                  double slider04,double slider05,double slider06,
//                  double mp_x,double mp_y,double mp_z,
//                  double mp_rx,double mp_ry,double mp_rz
//                  );

    //双转轴角度,10参数
    SimSystemInfo(double slider01,double slider02,double slider03,
                  double slider04,double slider05,double slider06,
                  double attack_ag,double roll_ag,

                  double dual_axis_ag01,
                  double dual_axis_ag02
                  );
    //14参数
    SimSystemInfo(double slider01,double slider02,double slider03,
                  double slider04,double slider05,double slider06,
                  double attack_ag,double roll_ag,
                  double mp_x,double mp_y,double mp_z,
                  double mp_rx,double mp_ry,double mp_rz
                  );


    /**=================by unishuai====================
    *设置友元函数
    *===================2024-05-23 ====================*/
    friend std::ostream& operator<<(std::ostream& os,const SimSystemInfo& info);

    /**=================by unishuai====================
    *设置访问器
    *===================2024-05-23 ====================*/
    //对基本数据类型进行封装
    double getSlider01() const;
    void setSlider01(double value);

    double getSlider02() const;
    void setSlider02(double value);

    double getSlider03() const;
    void setSlider03(double value);

    double getSlider04() const;
    void setSlider04(double value);

    double getSlider05() const;
    void setSlider05(double value);

    double getSlider06() const;
    void setSlider06(double value);

    double getAttack_ag() const;
    void setAttack_ag(double value);

    double getRoll_ag() const;
    void setRoll_ag(double value);

    double getDual_axis_ag01() const;
    void setDual_axis_ag01(double value);

    double getDual_axis_ag02() const;
    void setDual_axis_ag02(double value);

    double getMp_x() const;
    void setMp_x(double value);

    double getMp_y() const;
    void setMp_y(double value);

    double getMp_z() const;
    void setMp_z(double value);

    double getMp_rx() const;
    void setMp_rx(double value);

    double getMp_ry() const;
    void setMp_ry(double value);

    double getMp_rz() const;
    void setMp_rz(double value);

public:
    //这个方法主要是把字符串类型转化成SimSystemInfo类型
    /**=================by unishuai====================
    *                   字符转换器
    *===================2024-06-12 ====================*/
    static SimSystemInfo* str2SimSystemInfo(QString strInfo);



private:
    //六个滑块的角度
    double slider01;
    double slider02;
    double slider03;
    double slider04;
    double slider05;
    double slider06;
    //攻角
    double attack_ag;
    //滚转角
    double roll_ag;
    //双转轴角度
    double dual_axis_ag01;
    double dual_axis_ag02;
    //动平台坐标和旋转
    double mp_x;
    double mp_y;
    double mp_z;
    double mp_rx;
    double mp_ry;
    double mp_rz;




};

#endif // SIMSYSTEMINFO_H
