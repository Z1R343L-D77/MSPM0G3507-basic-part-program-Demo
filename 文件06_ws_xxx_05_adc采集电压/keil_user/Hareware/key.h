#ifndef _KEY_H
#define _KEY_H
#include "common_inc.h"


#define COMKEY_ClickThreshold           20  //单击时间阈值，短于此时间视为抖动
#define COMKEY_HoldThreshold            800 //长按时间阈值，长于此时间视为长按
#define COMKEY_IntervalVal              200 //间隔时间阈值，短于此时间视为连按
#define COMKEY_HoldTriggerThreshold     400 //长按触发阈值，长按时每隔该事件触发一次按键

typedef struct comKeyTypedef 
{
    u8 preVal: 1;
    u8 val: 1;
    u32 preTimer;// 按下计时
    u32 intervalTimer;// 放开计时
    u16 triggerTimer;// 长按触发计时
    struct comKeyTypedef *next;
    enum 
	{
        Release = 0,
        PrePress,
        Prelong,
        LongHold,
        MultiClick
    } state;// 状态枚举
    uint32_t holdTime;// 长按计时
    uint8_t clickCnt;// 按下计数
} comkey_t, *pcomkey_t;

// KEY
extern comkey_t Key_0,Key_1,Key_2,Key_3,Key_D3_1,Key_D3_2,Key_D3_3,Key_D3_4,Key_D3_5;

//Fuction
void ComKey_GetValue(comkey_t *key);

void ComKey_Init(comkey_t *key, int pollingPeriod);

void ComKey_Porc(void);

void key_init(void);

//CallBack_Fuction
void ComKey_LongHoldCallback(comkey_t *key);

void ComKey_HoldTriggerCallback(comkey_t *key);

void ComKey_FirstLongTriggerCallback(comkey_t *key);

void ComKey_MultipleClickCallback(comkey_t *key);

void ComKey_KeyReleaseCallback(comkey_t *key);

void ComKey_KeyPressCallback(comkey_t *key);

#endif 







