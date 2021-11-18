//https://blog.csdn.net/abc15766228491/article/details/83585190
#include <stdio.h>

struct Node{
    int value;
    int position;
    int next;
};

typedef struct Node item;
item item_list[100010];

void ReadLink(int head_node)
{
    while(head_node!=-1)
    {
        if(item_list[head_node].next!=-1)
            printf("%05d %d %05d\n",item_list[head_node].position, item_list[head_node].value, item_list[head_node].next);
        else
            printf("%05d %d %d\n",item_list[head_node].position, item_list[head_node].value, item_list[head_node].next);
        head_node = item_list[head_node].next;
    }

}

int main() {
    int head_position, node_num, next_postion, value, position, key;
    scanf("%d %d %d", &head_position, &node_num, &key);
    // 输入
    for (int i = 0; i < node_num; ++i) {
        scanf("%d %d %d", &position, &value, &next_postion);
        item_list[position].position = position;
        item_list[position].value = value;
        item_list[position].next = next_postion;
    }
    int front, rear, p;
    // 初始化front和rear
    front = item_list[head_position].position;
    rear = item_list[item_list[head_position].next].position;
    int head = 100000, tail;
    // 开始处理有多余点不在链表上，下面是计算一下真正又用的节点有多少个
    int count = 1;
    int front1;
    front1 = item_list[head_position].position;
    while (item_list[front1].next != -1) {
        count++;
        front1 = item_list[front1].next;
    }
    // 计算要输出几组的时候，用count/key，不是用节点的总数去除
    for (int i = 0; i < count / key; ++i) {
        // 看下能反转几次
        // 前一个的开头，就是下一个的结尾
        tail = front;
        for (int j = 1; j < key; ++j) {
            //反转多少个
            p = item_list[rear].next;
            item_list[rear].next = item_list[front].position;
            front = rear;
            rear = p;
        }
        item_list[head].next = front;
        head = tail;
        front = item_list[rear].position;
        rear = item_list[item_list[rear].next].position;
    }
    // 如果count%key有余数，说明，后面有一部分是没有反转的，需要把后面没有反转的节点连起来
    // 如果需要反转的每一组的个数最小为key，但是在链表上的多余的节点的个数小于Key，则不反转，直接照着头节点位置向下输出即可
    // 上面这种情况也是count%key为0连的front初始化过了
    if (count % key) {
        item_list[head].next = front;
        ReadLink(item_list[100000].next);
    } else {
        item_list[head].next = -1;
        ReadLink(item_list[100000].next);
    }
    return 0;
}
/*
00100 8 7
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
11111 7 22222
22222 8 -1
 */