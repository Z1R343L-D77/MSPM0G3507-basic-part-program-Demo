#include <string.h>
#include "ring_buffer.h"
//#include "usart.h"

RINGBUFF_T Ringbuff0;


/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
 //Tip for Cao:数组定大小的时候要为2 4 8 16 32 64 128 256 512 1024 2048 4096 8192这种有规则的，否满对头跟队尾到达数组终点时回起点会有BUG
#define RB_INDH(rb) ((rb)->head & ((rb)->count - 1))//当没写到数组终点时得到的是head，写到终点时就会获得一个0，就从头开始写
#define RB_INDT(rb) ((rb)->tail & ((rb)->count - 1))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
/*****************************************************************************
 * Private functions
 ****************************************************************************/
/*****************************************************************************
 * Public functions
 ****************************************************************************/
/* Initialize ring buffer */
int RingBuffer_Init(RINGBUFF_T *RingBuff, void *buffer, int itemSize, int count)
{
    RingBuff->data = buffer;
    RingBuff->count = count;
    RingBuff->itemSz = itemSize;
    RingBuff->head = RingBuff->tail = 0;
    return 1;
}
/* Insert a single item into Ring Buffer */
int RingBuffer_Insert(RINGBUFF_T *RingBuff, const void *data)
{
    uint8_t *ptr = RingBuff->data;
    /* We cannot insert when queue is full */
    if (RingBuffer_IsFull(RingBuff))
    {
//			printf("full\r\n");
      return 0;
    }
    ptr += RB_INDH(RingBuff) * RingBuff->itemSz;
		memcpy(ptr,data, RingBuff->itemSz);
    RingBuff->head++;
    return 1;
}
/* Insert multiple items into Ring Buffer */
int RingBuffer_InsertMult(RINGBUFF_T *RingBuff, const void *data, int num)
{
    uint8_t *ptr = RingBuff->data;
    int cnt1, cnt2;
    /* We cannot insert when queue is full */
    if (RingBuffer_IsFull(RingBuff))
    {
//			printf("full\r\n");
        return 0;
    }
    /* Calculate the segment lengths */
    cnt1 = cnt2 = RingBuffer_GetFree(RingBuff);
    if (RB_INDH(RingBuff) + cnt1 >= RingBuff->count)//head在tail前面
    {
        cnt1 = RingBuff->count - RB_INDH(RingBuff);//cnt1为head到环形数组的终点相隔的个数
    }
    cnt2 -= cnt1;//head在tail前面，cnt2为环形数组的起点到tail相隔的个数
    cnt1 = MIN(cnt1, num);//如果tail在head前面，如果空间满了，入队的数据就会被舍弃一点
    num -= cnt1;
    cnt2 = MIN(cnt2, num);
    num -= cnt2;//head在tail前面，如果空间满了，入队的数据就会被舍弃掉一些
    /* Write segment 1 */
    ptr += RB_INDH(RingBuff) * RingBuff->itemSz;
    memcpy(ptr, data, cnt1 * RingBuff->itemSz);
    RingBuff->head += cnt1;
    /* Write segment 2 */
    ptr = (uint8_t *)RingBuff->data + RB_INDH(RingBuff) * RingBuff->itemSz;
    data = (const uint8_t *)data + cnt1 * RingBuff->itemSz;
    memcpy(ptr, data, cnt2 * RingBuff->itemSz);
    RingBuff->head += cnt2;
    return cnt1 + cnt2;
}



/* Pop single item from Ring Buffer */
int RingBuffer_Pop(RINGBUFF_T *RingBuff, void *data)
{
    uint8_t *ptr = RingBuff->data;
    /* We cannot pop when queue is empty */
    if (RingBuffer_IsEmpty(RingBuff))
    {
        return 0;
    }
    ptr += RB_INDT(RingBuff) * RingBuff->itemSz;
    memcpy(data, ptr, RingBuff->itemSz);
    RingBuff->tail++;
    return 1;
}
/* Pop multiple items from Ring buffer */
int RingBuffer_PopMult(RINGBUFF_T *RingBuff, void *data, int num)
{
    uint8_t *ptr = RingBuff->data;
    int cnt1, cnt2;
    /* We cannot insert when queue is empty */
	
//		data
	
    if (RingBuffer_IsEmpty(RingBuff))
    {
        return 0;
    }
    /* Calculate the segment lengths */
    cnt1 = cnt2 = RingBuffer_GetCount(RingBuff);
    if (RB_INDT(RingBuff) + cnt1 >= RingBuff->count)
    {
        cnt1 = RingBuff->count - RB_INDT(RingBuff);
    }
    cnt2 -= cnt1;
    cnt1 = MIN(cnt1, num);
    num -= cnt1;
    cnt2 = MIN(cnt2, num);
    num -= cnt2;
    /* Write segment 1 */
    ptr += RB_INDT(RingBuff) * RingBuff->itemSz;
    memcpy(data, ptr, cnt1 * RingBuff->itemSz);
    RingBuff->tail += cnt1;
    /* Write segment 2 */
    ptr = (uint8_t *)RingBuff->data + RB_INDT(RingBuff) * RingBuff->itemSz;
    data = (uint8_t *)data + cnt1 * RingBuff->itemSz;
    memcpy(data, ptr, cnt2 * RingBuff->itemSz);
    RingBuff->tail += cnt2;
    return cnt1 + cnt2;
}
