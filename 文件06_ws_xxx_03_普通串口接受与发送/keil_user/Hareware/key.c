#include "key.h"


// 定义键值对象数组
comkey_t Key_0,Key_1,Key_2,Key_3,Key_4;
//******************************************

void key_init(void)
{
	ComKey_Init(&Key_1, 10);
	ComKey_Init(&Key_2, 10);
	ComKey_Init(&Key_3, 10);
}
//******************************************
 void ComKey_GetValue(comkey_t *key) 
 {
     //如果按下了该键，“key->val”应为 1。
     if (key == &Key_1) {
         key->val = !DL_GPIO_readPins(GPIO_KEY_PORT, GPIO_KEY_KEY_1_PIN);
     }
     if (key == &Key_2) {
         key->val = !DL_GPIO_readPins(GPIO_KEY_PORT, GPIO_KEY_KEY_2_PIN);
     }
     if (key == &Key_3) {
         key->val = !DL_GPIO_readPins(GPIO_KEY_PORT, GPIO_KEY_KEY_3_PIN);
     }
     //此处添加其他按键，如上
     key->preVal = key->val;
 }

// 弱属性定义，允许用户自定义回调函数
/**
 * @brief 第一个长按触发事件发生时的回调函数
 */
__attribute__((weak)) void ComKey_FirstLongTriggerCallback(comkey_t *key)
{

}

/**
 * @brief 长按保持状态下的回调函数
 */
__attribute__((weak)) void ComKey_LongHoldCallback(comkey_t *key)
{

}

/**
 * @brief 长按触发后的回调函数
 */
__attribute__((weak)) void ComKey_HoldTriggerCallback(comkey_t *key)
{

}

/**
 * @brief 短时间内连续多次点击回调函数
 */
__attribute__((weak)) void ComKey_MultipleClickCallback(comkey_t *key)
{

}

/**
 * @brief 按键释放回调函数
 */
__attribute__((weak)) void ComKey_KeyReleaseCallback(comkey_t *key)
{

}

/**
 * @brief 按下按键并保持按压状态下的回调函数
 */
__attribute__((weak)) void ComKey_KeyPressCallback(comkey_t *key)
{

}

// 链表头尾指针，用于管理键值对象
static pcomkey_t head = NULL, tail = NULL;
// IT周期，用于定时器间隔设置
static u8 ITPeriod = 10;

/**
 * 初始化按键模块
 * 
 * 该函数用于初始化一个按键对象，并将其添加到按键链表中。如果链表为空，此按键将成为第一个元素；
 * 否则，它将被添加到链表的末尾。按键的状态被设置为释放状态，且不关联下一个按键。
 * 
 * @param key 指向要初始化的按键结构体的指针。
 * @param pollingPeriod 指定按键轮询周期，用于设置中断定时器的间隔。
 */
void ComKey_Init(comkey_t *key, int pollingPeriod) 
{
    /* 设置按键轮询周期 */
    ITPeriod = pollingPeriod;
    
    /* 初始化按键状态为释放，并设置下一个按键指针为NULL */
    key->state = Release;
    key->next = NULL;

    /* 如果链表头指针为空，说明链表为空，将当前按键设为头指针和尾指针 */
    if (head == NULL) 
    {
        head = key;
        tail = key;
    } 
    /* 如果链表不为空，将当前按键添加到链表尾部 */
    else 
	{
        tail->next = key;
        tail = tail->next;
    }
}
/**
 * 按键所有事件处理函数
 * 10ms中断循环
 */
void ComKey_Porc(void) 
{
    for (pcomkey_t key = head; key != NULL; key = key->next) 
    {
		//按键读取
        ComKey_GetValue(key);
        // 按下状态更新和计时器处理//判断长短按键
        if (!key->val) 
        {
            if (key->state == LongHold) 
            {
                key->holdTime = key->preTimer;
            }
            key->preTimer = 0;
        }
        if (key->preVal & key->val) 
        {
            key->preTimer += ITPeriod;
        }

        // 多次点击状态下的间隔计时器更新//连续点击处理
        if (key->state == MultiClick) 
        {
            key->intervalTimer += ITPeriod;
        } else 
		{
            key->intervalTimer = 0;
        }

        // 根据当前状态执行相应处理
        // 事件生成
         switch (key->state) 
        {
            /* 当按键状态为释放时，重置点击次数，并根据当前值决定是否进入预按压状态 */
            case Release:
                key->clickCnt = 0;
                if (key->val) {
                    key->state = PrePress;
                }
                break;
            /* 当按键状态为预按压时，根据当前值和预按压时间决定是否进入预长按状态 */
            case PrePress:
                if (!key->val) 
                {
                    key->state = Release;
                } else if (key->preTimer > COMKEY_ClickThreshold) 
                {
                    key->state = Prelong;
                    ComKey_KeyPressCallback(key);
                }
                break;
            /* 当按键状态为预长按时，根据当前值和预长按时间决定是否进入长按状态 */
            case Prelong:
                if (!key->val) 
                {
                    key->state = MultiClick;
                    key->clickCnt++;
                } else if (key->preTimer > COMKEY_HoldThreshold) 
                {
                    key->state = LongHold;
                    key->triggerTimer = COMKEY_HoldTriggerThreshold;
                    ComKey_FirstLongTriggerCallback(key);
                }
                break;
            /* 当按键状态为长按时，管理触发计时器，并根据当前值决定是否触发长按回调并释放 */
            case LongHold:
                if (key->triggerTimer > 0)
                    key->triggerTimer -= ITPeriod;
                else 
				{
                    key->triggerTimer = COMKEY_HoldTriggerThreshold;
                    ComKey_HoldTriggerCallback(key);
                }
                if (!key->val) 
                {
                    ComKey_LongHoldCallback(key);
                    ComKey_KeyReleaseCallback(key);
                    key->state = Release;
                }
                break;
            /* 当按键状态为多击时，根据间隔时间决定是否触发多击回调并释放 */
            case MultiClick:
                if (key->intervalTimer > COMKEY_IntervalVal) 
                {
                    ComKey_MultipleClickCallback(key);
                    ComKey_KeyReleaseCallback(key);
                    key->state = Release;
                } else if (key->preTimer > COMKEY_ClickThreshold) 
                {
                    key->state = Prelong;
                }
                break;
        }
    }
}
//**************************************************