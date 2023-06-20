#include "MdMeasureDistance.h"
//#include "M5All-In-One-Gadget.h"
#include "M5All-In-One-Gadget.h"
//#include <M5Stack.h>
#include "DrUltraSonic.h"
#include <Arduino.h>

//DrUltraSonic DrUltraSonic;
DrUltraSonic drul = DrUltraSonic(ECHO_PIN, TRIG_PIN);

double MdMeasureDistance::getDistance(){
   double tim = drul.measureReturnTime();//修正すること.ｔを受け取る
   Serial.println(tim);
   double distance = tim * 340 * 0.000001 * 0.5 * 100;   //m→cmなので100倍する
   Serial.print(distance);//ここで測定した値を表示させる！
   Serial.println("cm");

   //double tim = drul.measureReturnTime();
   return distance;//distanceを戻す
}