//
// Created by 姚政 on 2021/4/10.
//
#include "stdio.h"
#include "stdlib.h"

int pushQueue(int *a, int rear, int elem) {
    a[rear++] = elem;
    return rear;
}

int popQueue(int *a, int rear, int top) {
    if (top != rear) {
        printf("this is %d\n", a[top]);
    }
    top++;
    return top;
}

void clearQueue(int *a, int rear, int top) {
    while (top != rear) {
        printf("this is %d\n", a[top]);
        top++;
    }
}


int main() {
//    int a[100];
//    int cc=pushQueue(a,0,1);
//    printf("%d,%d\n",cc,a[0]);
    int a[100];
    int front, rear;
    //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front = rear = 0;
    //入队
    rear = pushQueue(a, rear, 1);
    rear = pushQueue(a, rear, 2);
    rear = pushQueue(a, rear, 3);
    rear = pushQueue(a, rear, 4);
    //出队
//    clearQueue(a, front, rear);
    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d\n", a[2]);
    printf("%d\n", a[3]);
//    int cc=popQueue(a,rear,front);
    clearQueue(a, rear,front);

    return 0;
}