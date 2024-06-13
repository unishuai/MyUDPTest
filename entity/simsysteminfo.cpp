#include "simsysteminfo.h"

#include <QStringList>
/******************************************************************************
  @Project Name  : 04TestConnectMysql
  @File Name     : simsysteminfo.cpp
  @Version       : 1.0
  @Function      : to be determined
  @Author        : unishuai
  @Date          : 2024-05-22
******************************************************************************/

SimSystemInfo::SimSystemInfo():
    slider01(0), slider02(0), slider03(0), slider04(0), slider05(0), slider06(0),
    attack_ag(0), roll_ag(0),
    dual_axis_ag01(0), dual_axis_ag02(0),
    mp_x(0), mp_y(0), mp_z(0), mp_rx(0), mp_ry(0), mp_rz(0)
{

}

SimSystemInfo::SimSystemInfo(double slider01, double slider02, double slider03, double slider04,
                             double slider05, double slider06):
    slider01(slider01), slider02(slider02), slider03(slider03),
    slider04(slider04), slider05(slider05), slider06(slider06),
    attack_ag(0), roll_ag(0),
    dual_axis_ag01(0), dual_axis_ag02(0),
    mp_x(0), mp_y(0), mp_z(0), mp_rx(0), mp_ry(0), mp_rz(0)
{

}

SimSystemInfo::SimSystemInfo(double slider01, double slider02, double slider03,
                             double slider04, double slider05, double slider06,
                             double attack_ag, double roll_ag):
    slider01(slider01), slider02(slider02), slider03(slider03),
    slider04(slider04), slider05(slider05), slider06(slider06),
    attack_ag(attack_ag), roll_ag(roll_ag),
    dual_axis_ag01(0), dual_axis_ag02(0),
    mp_x(0), mp_y(0), mp_z(0), mp_rx(0), mp_ry(0), mp_rz(0)
{

}

SimSystemInfo::SimSystemInfo(double slider01, double slider02, double slider03,
                             double slider04, double slider05, double slider06,
                             double attack_ag, double roll_ag,
                             double dual_axis_ag01, double dual_axis_ag02):
    slider01(slider01), slider02(slider02), slider03(slider03),
    slider04(slider04), slider05(slider05), slider06(slider06),
    attack_ag(attack_ag), roll_ag(roll_ag),
    dual_axis_ag01(dual_axis_ag01),dual_axis_ag02(dual_axis_ag02)
{

}

//SimSystemInfo::SimSystemInfo(double slider01, double slider02, double slider03,
//                             double slider04, double slider05, double slider06,
//                             double mp_x, double mp_y, double mp_z,
//                             double mp_rx, double mp_ry, double mp_rz):
//    slider01(slider01), slider02(slider02), slider03(slider03),
//    slider04(slider04), slider05(slider05), slider06(slider06),
//    mp_x(mp_x), mp_y(mp_y), mp_z(mp_z),
//    mp_rx(mp_rx), mp_ry(mp_ry), mp_rz(mp_rz)
//{
//}

SimSystemInfo::SimSystemInfo(double slider01, double slider02, double slider03,
                             double slider04, double slider05, double slider06,
                             double attack_ag, double roll_ag,
                             double mp_x, double mp_y, double mp_z,
                             double mp_rx, double mp_ry, double mp_rz):
    slider01(slider01), slider02(slider02), slider03(slider03),
    slider04(slider04), slider05(slider05), slider06(slider06),
    attack_ag(attack_ag), roll_ag(roll_ag),
    mp_x(mp_x), mp_y(mp_y), mp_z(mp_z),
    mp_rx(mp_rx), mp_ry(mp_ry), mp_rz(mp_rz),
    dual_axis_ag01(0), dual_axis_ag02(0)
{

}


//std::ostream &SimSystemInfo::operator<<(std::ostream &os, const SimSystemInfo &info)
//上面那样是有问题的，这里面银行了一个this指针，而且严格来讲重载函数不算是其一部分
std::ostream &operator<<(std::ostream &os, const SimSystemInfo &info)
{
    os << "SimSystemInfo (Slider01:" << info.getSlider01()<< ",Slider02:" << info.getSlider02() << ",Slider03:" << info.getSlider03()
       << ",Slider04:" << info.getSlider04() << ",Slider05:" << info.getSlider05() << ",Slider06:" << info.getSlider06()
       << ",Attack_ag:" << info.getAttack_ag() << ",Roll_ag:" << info.getRoll_ag()<<")";
    return os;
}

double SimSystemInfo::getSlider01() const
{
    return slider01;
}

void SimSystemInfo::setSlider01(double value)
{
    slider01 = value;
}

double SimSystemInfo::getSlider02() const
{
    return slider02;
}

void SimSystemInfo::setSlider02(double value)
{
    slider02 = value;
}

double SimSystemInfo::getSlider03() const
{
    return slider03;
}

void SimSystemInfo::setSlider03(double value)
{
    slider03 = value;
}

double SimSystemInfo::getSlider04() const
{
    return slider04;
}

void SimSystemInfo::setSlider04(double value)
{
    slider04 = value;
}

double SimSystemInfo::getSlider05() const
{
    return slider05;
}

void SimSystemInfo::setSlider05(double value)
{
    slider05 = value;
}

double SimSystemInfo::getSlider06() const
{
    return slider06;
}

void SimSystemInfo::setSlider06(double value)
{
    slider06 = value;
}

double SimSystemInfo::getAttack_ag() const
{
    return attack_ag;
}

void SimSystemInfo::setAttack_ag(double value)
{
    attack_ag = value;
}

double SimSystemInfo::getRoll_ag() const
{
    return roll_ag;
}

void SimSystemInfo::setRoll_ag(double value)
{
    roll_ag = value;
}

double SimSystemInfo::getDual_axis_ag01() const
{
    return dual_axis_ag01;
}

void SimSystemInfo::setDual_axis_ag01(double value)
{
    dual_axis_ag01 = value;
}

double SimSystemInfo::getDual_axis_ag02() const
{
    return dual_axis_ag02;
}

void SimSystemInfo::setDual_axis_ag02(double value)
{
    dual_axis_ag02 = value;
}

double SimSystemInfo::getMp_x() const
{
    return mp_x;
}

void SimSystemInfo::setMp_x(double value)
{
    mp_x = value;
}

double SimSystemInfo::getMp_y() const
{
    return mp_y;
}

void SimSystemInfo::setMp_y(double value)
{
    mp_y = value;
}

double SimSystemInfo::getMp_z() const
{
    return mp_z;
}

void SimSystemInfo::setMp_z(double value)
{
    mp_z = value;
}

double SimSystemInfo::getMp_rx() const
{
    return mp_rx;
}

void SimSystemInfo::setMp_rx(double value)
{
    mp_rx = value;
}

double SimSystemInfo::getMp_ry() const
{
    return mp_ry;
}

void SimSystemInfo::setMp_ry(double value)
{
    mp_ry = value;
}

double SimSystemInfo::getMp_rz() const
{
    return mp_rz;
}

void SimSystemInfo::setMp_rz(double value)
{
    mp_rz = value;
}


SimSystemInfo* SimSystemInfo::str2SimSystemInfo(QString strInfo) {
    QStringList values = strInfo.split(",");

    // Clean up the string list: trim spaces and remove empty entries
    for (auto it = values.begin(); it != values.end(); ) {
        *it = it->trimmed();
        if (it->isEmpty()) {
            it = values.erase(it);
        } else {
            ++it;
        }
    }

    // Early return if the count of values doesn't match any known constructor
    if (values.size() != 6 && values.size() != 8 && values.size() != 10 && values.size() != 14) {
        std::cout << "This string cannot convert to SimSystemInfo";
        return NULL;
    }

    // Convert the string values to doubles
    double slider01 = values[0].toDouble();
    double slider02 = values[1].toDouble();
    double slider03 = values[2].toDouble();
    double slider04 = values[3].toDouble();
    double slider05 = values[4].toDouble();
    double slider06 = values[5].toDouble();

    if (values.size() == 6) {
        return new SimSystemInfo(slider01, slider02, slider03, slider04, slider05, slider06);
    }

    double attack_ag = values[6].toDouble();
    double roll_ag = values[7].toDouble();

    if (values.size() == 8) {
        return new SimSystemInfo(slider01, slider02, slider03, slider04, slider05, slider06, attack_ag, roll_ag);
    }

    if (values.size() == 10) {
        double dual_axis_ag01 = values[8].toDouble();
        double dual_axis_ag02 = values[9].toDouble();
        return new SimSystemInfo(slider01, slider02, slider03, slider04, slider05, slider06, attack_ag, roll_ag, dual_axis_ag01, dual_axis_ag02);
    }

    double mp_x = values[8].toDouble();
    double mp_y = values[9].toDouble();
    double mp_z = values[10].toDouble();
    double mp_rx = values[11].toDouble();
    double mp_ry = values[12].toDouble();
    double mp_rz = values[13].toDouble();

    return new SimSystemInfo(slider01, slider02, slider03, slider04, slider05, slider06, attack_ag, roll_ag, mp_x, mp_y, mp_z, mp_rx, mp_ry, mp_rz);
}

