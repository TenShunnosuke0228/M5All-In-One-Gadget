/* インクルードガード */
#pragma once

//#include "MdMeasureDistance.h"
//#include "M5All-In-One-Gadget.h"
//#include <M5Stack.h>
//#include "AppControl.h"
//#include <Arduino.h>

class DrUltraSonic // classの定義
{
private: // privateはクラス内からしかアクセスできない
    int m_echo_pin;
    int m_trig_pin;

public: // publicはどこからでもアクセス可能
    DrUltraSonic(int echo_pin, int trig_pin);
    double measureReturnTime();
};