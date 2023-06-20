#include "MdWBGTMonitor.h"
#include "DrTHSensor.h"
#include "M5All-In-One-Gadget.h"
#include <Arduino.h>

DrTHSensor dthsen;

void MdWBGTMonitor::init(){
    dthsen.init();
}

void MdWBGTMonitor::getWBGT(double* temperature, double* humidity, WbgtIndex* index){
    

    // DrTHSensorから温度と湿度を取得
    double temp;
    double humi;
    dthsen.getTempHumi(&temp, &humi);

    // 取得した値を引数であるtemperatureとhumidityに格納
    *temperature = temp;
    *humidity = humi;

    double WbgtIndex = 0.68 * (*temperature) + 0.12 * (*humidity);

    if(WbgtIndex <= 15){
        *index = SAFE;
        }else if(16 <= WbgtIndex && WbgtIndex <= 24){
            *index = ATTENTION;
            }else if(25 <= WbgtIndex && WbgtIndex <= 27){
                *index = ALERT;
                }else if(28 <= WbgtIndex && WbgtIndex <= 30){
                    *index = HIGH_ALERT;
                    }else if(WbgtIndex > 31){
                        *index = DANGER;
                        }
}