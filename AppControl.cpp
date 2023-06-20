#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;




const char* g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};


const char* g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};

void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState()
{
    return m_state;
}

void AppControl::setState(State state)
{
    m_state = state;
}

Action AppControl::getAction()
{
    return m_action;
}

void AppControl::setAction(Action action)
{
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState()
{
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}

void AppControl::displayTitleInit(){
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit(){
    mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}


void AppControl::displayMenuInit_MENU_WBGT(){
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}

void AppControl::displayMenuInit_MENU_MUSIC(){
    mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}

void AppControl::displayMenuInit_MENU_MEASURE(){
    mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}

void AppControl::displayMenuInit_MENU_DATE(){
    mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}


void AppControl::focusChangeImg(FocusState current_state, FocusState next_state){
    setFocusState(current_state);
    setFocusState(next_state);
}

void AppControl::displayWBGTInit(){
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH, WBGT_TEMPERATURE_X_CRD, WBGT_TEMPERATURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
}


void AppControl::displayTempHumiIndex(){
        double temperature;
        double humidity;
        WbgtIndex index;
    mwbgt.getWBGT(&temperature, &humidity, &index);
        int decimalDigit1 = ((int)(temperature*10))%10; //小数点第1位の値を取得
        int digit11 = ((int)temperature)%10; //1の位の値を取得
        int digit12 = ((int)(temperature/10))%10; //10の位の値を取得
        mlcd.displayJpgImageCoordinate(g_str_orange[decimalDigit1], WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        mlcd.displayJpgImageCoordinate(g_str_orange[digit11], WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        mlcd.displayJpgImageCoordinate(g_str_orange[digit12], WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);
        mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH ,WBGT_TDOT_X_CRD, WBGT_TDOT_Y_CRD);

        
        int decimalDigit2 = ((int)(humidity*10))%10; //小数点第1位の値を取得
        int digit21 = ((int)humidity)%10; //1の位の値を取得
        int digit22 = ((int)(humidity/10))%10; //10の位の値を取得
        mlcd.displayJpgImageCoordinate(g_str_blue[decimalDigit2], WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        mlcd.displayJpgImageCoordinate(g_str_blue[digit21], WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        mlcd.displayJpgImageCoordinate(g_str_blue[digit22], WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);
        mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_HDOT_X_CRD, WBGT_HDOT_Y_CRD);

        if(index == SAFE){
            mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        }else if(index == ATTENTION){
                mlcd.displayJpgImageCoordinate(WBGT_ATTENTION_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
            }else if(index == ALERT){
                    mlcd.displayJpgImageCoordinate(WBGT_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
                }else if(index == HIGH_ALERT){
                        mlcd.displayJpgImageCoordinate(WBGT_HIGH_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
                    }else if(index == DANGER){
                            mlcd.displayJpgImageCoordinate(WBGT_DANGER_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
                        }

        delay(100);
}

void AppControl::displayMusicInit(){
    
}

void AppControl::displayMusicStop(){
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
    mlcd.displayJpgImageCoordinate(mmplay.getTitle(), MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
    char* title = mmplay.getTitle();
    mlcd.displayText(title, MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}

void AppControl::displayMusicTitle()
{
}

void AppControl::displayNextMusic(){
    mmplay.selectNextMusic();
}

void AppControl::displayMusicPlay(){
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_STOP_IMG_PATH, MUSIC_STOP_X_CRD, MUSIC_STOP_Y_CRD);
    char* title1 = mmplay.getTitle();
    mlcd.displayText(title1, MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}

void AppControl::displayMeasureInit(){
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
}

void AppControl::displayMeasureDistance(){
    Serial.println("check1");
    double index = mmdist.getDistance();//この関数で距離を測定させる
        Serial.println("check2");
        int decimalDigit=((int)(index*10))%10; //小数点第1位の値を取得
        Serial.println("check3");
        int digit1=((int)index)%10; //1の位の値を取得
        Serial.println("check4");
        int digit2=((int)(index/10))%10; //10の位の値を取得
        Serial.println("check5");
        int digit3=((int)(index/100))%10; //100の位の値を取得
        Serial.println("check6");
        /*
        const char* imagePathDecimal=g_str_blue[decimalDigit];
        const char* imagePath1=g_str_blue[digit1];
        const char* imagePath2=g_str_blue[digit2];
        const char* imagePath3=g_str_blue[digit3];
        */
        if(digit3==0){
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        }else{
            mlcd.displayJpgImageCoordinate(g_str_blue[digit3], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        }

        if(digit2==0){
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }else{
            mlcd.displayJpgImageCoordinate(g_str_blue[digit2], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }
        mlcd.displayJpgImageCoordinate(g_str_blue[decimalDigit], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        mlcd.displayJpgImageCoordinate(g_str_blue[digit1], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);
        mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
        delay(100);
    }

void AppControl::displayDateInit(){
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    //mlcd.displayJpgImageCoordinate(DATE_SLASH_IMG_PATH, DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    //mlcd.displayJpgImageCoordinate(DATE_COLON_IMG_PATH, DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
}

void AppControl::displayDateUpdate(){
    //mdtime.MdDateTime();
    String data = mdtime.readDate();
    String time = mdtime.readTime();
    mlcd.displayDateText(data, DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayDateText(time, DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
    delay(100);
}

void AppControl::controlApplication()
{
    mmplay.init();

    while (1) {

        switch (getState()) {
        case TITLE:
            switch (getAction()) {
            case ENTRY:
                /*
                ** まずはここにタイトル画面の表示処理を呼び出してみよう。
                ** タイトル画面表示の関数はdisplayTitleInit()である。
                ** この関数の中身はまだ何もないので、この関数にタイトル画面表示処理を書いてみよう。
                */
                displayTitleInit();          //画面表示

                if(m_flag_btnA_is_pressed==true||m_flag_btnB_is_pressed==true||m_flag_btnC_is_pressed==true){

                    setStateMachine(TITLE, DO);
                    setBtnAllFlgFalse();
                }

                break;

            case DO:
                setStateMachine(TITLE, EXIT);
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                mlcd.clearDisplay();
                break;

            default:
                setStateMachine(TITLE, ENTRY);
                break;
            }

            break;

        case MENU:

        switch (getAction()) {
            case ENTRY:
            //displayMenuInit();
                switch(getFocusState()){
                        case MENU_DATE:
                            setFocusState(MENU_DATE);
                            displayMenuInit_MENU_DATE();
                            if(m_flag_btnA_is_pressed==true){
                                focusChangeImg(MENU_DATE, MENU_MEASURE);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnB_is_pressed==true){
                                setStateMachine(DATE, ENTRY);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnC_is_pressed==true){
                                focusChangeImg(MENU_DATE, MENU_WBGT);
                                setBtnAllFlgFalse();
                            }
                        break;

                        case MENU_WBGT:
                            setFocusState(MENU_WBGT);
                            displayMenuInit_MENU_WBGT();
                            if(m_flag_btnA_is_pressed==true){
                                focusChangeImg(MENU_WBGT, MENU_DATE);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnB_is_pressed==true){
                                setStateMachine(WBGT, ENTRY);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnC_is_pressed==true){
                                focusChangeImg(MENU_WBGT, MENU_MUSIC);
                                setBtnAllFlgFalse();
                            }
                        break;

                        case MENU_MUSIC:
                            setFocusState(MENU_MUSIC);
                            displayMenuInit_MENU_MUSIC();
                            if(m_flag_btnA_is_pressed==true){
                                focusChangeImg(MENU_MUSIC, MENU_WBGT);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnB_is_pressed==true){
                                setStateMachine(MUSIC_STOP, ENTRY);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnC_is_pressed==true){
                                focusChangeImg(MENU_MUSIC, MENU_MEASURE);
                                setBtnAllFlgFalse();
                            }
                        break;

                        case MENU_MEASURE:
                            setFocusState(MENU_MEASURE);
                            displayMenuInit_MENU_MEASURE();
                            if(m_flag_btnA_is_pressed==true){
                                focusChangeImg(MENU_MEASURE, MENU_MUSIC);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnB_is_pressed==true){
                                setStateMachine(MEASURE, ENTRY);
                                setBtnAllFlgFalse();
                            }else if(m_flag_btnC_is_pressed==true){
                                focusChangeImg(MENU_MEASURE, MENU_DATE);
                                setBtnAllFlgFalse();
                            }
                        break;
                    }
                  break;  
            

            case DO:
                setStateMachine(MENU, EXIT);
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);

            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction()) {
            case ENTRY:
                mwbgt.init();
                mlcd.fillBackgroundWhite();
                setStateMachine(WBGT, DO);
                break;
            case DO:
                displayWBGTInit();
                displayTempHumiIndex();
                if(m_flag_btnB_is_pressed==true){
                    setStateMachine(WBGT, EXIT);
                    setBtnAllFlgFalse();
                }
                break;
            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;
            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
                setStateMachine(MUSIC_STOP, DO);
                mlcd.fillBackgroundWhite();
                break;
            case DO:
                displayMusicStop();
                if(m_flag_btnA_is_pressed==true){
                    setStateMachine(MUSIC_PLAY, ENTRY);
                    mlcd.fillBackgroundWhite();
                    setBtnAllFlgFalse();
                }else if(m_flag_btnB_is_pressed==true){
                    setStateMachine(MUSIC_STOP, EXIT);
                    mlcd.fillBackgroundWhite();
                    setBtnAllFlgFalse();
                }else if(m_flag_btnC_is_pressed==true){
                    mmplay.selectNextMusic();
                    displayNextMusic();
                    setBtnAllFlgFalse();
                }

                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
                setStateMachine(MUSIC_PLAY, DO);
                break;
            case DO:
                displayMusicPlay();
                mmplay.prepareMP3();
                while(1){
                bool isPlaying = mmplay.playMP3();
                if(isPlaying == false||m_flag_btnA_is_pressed == true){
                    setStateMachine(MUSIC_PLAY, EXIT);
                    setBtnAllFlgFalse();
                    break;
                }
                }
            case EXIT:
                mmplay.stopMP3();
                setStateMachine(MUSIC_STOP, ENTRY);
                mlcd.fillBackgroundWhite();
                break;

            default:
                break;
            }

            break;

        case MEASURE:
            switch (getAction()) {
            case ENTRY:
                mlcd.fillBackgroundWhite();
                setStateMachine(MEASURE, DO);
                break;
            case DO:
                /*
                do{
                    displayMeasureInit();
                    displayMeasureDistance();
                }while(!m_flag_btnB_is_pressed==true);
                setStateMachine(MEASURE, EXIT);
                setBtnAllFlgFalse();
                break;
                */
                displayMeasureInit();
                displayMeasureDistance();
                if(m_flag_btnB_is_pressed==true){
                    setStateMachine(MEASURE, EXIT);
                    setBtnAllFlgFalse();
                }
                break;
            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;
            default:
                break;
            }

            break;

        case DATE:

            switch (getAction()) {
            case ENTRY:
                mlcd.fillBackgroundWhite();
                setStateMachine(DATE, DO);
                break;
            case DO:
                displayDateInit();
                displayDateUpdate();
                if(m_flag_btnB_is_pressed==true){
                    setStateMachine(DATE, EXIT);
                    setBtnAllFlgFalse();
                }
                break;
            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
