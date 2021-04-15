//
// Created by 姚政 on 2021/4/11.
//
#include "stdio.h"
#include "stdlib.h"
//实际存储长度是max-1,因为rear始终是指向队尾数据的下一个位置。
#define max 5
int enQueue(int *a,int rear,int front,int data){
//    printf("before is rear:%d\n",rear);
    //添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
//    printf("%d %% 5:%d\n",rear,rear%max);
    if ((rear+1)%max==front){
//        printf("this is front:%d\n",front);
//        printf("%d %% 5:%d\n",rear,rear+1%max);
        printf("空间已满,this is front:%d\tthis is rear:%d\n",front,rear);
        return rear;
    }
//    a[rear%max]=data;
//    if (rear==5){
//        rear=0;
//        return front;
//    }
    a[rear]=data;

//    printf("******");
//    printf("index %d %% 5:%d\n",rear,rear%max);
    rear++;
//    printf("after is rear:%d\n",rear);
//    printf("-------------------\n");
    return rear;
}
int deQueue(int *a,int front,int rear){
    //如果front==rear,表示队列为空
//    if (front==rear%max){
    if (front==rear){
        printf("队列为空\n");
        return front;
    }
    printf("%d\n",a[front]);
    //front不再直接+1，而是+1后同max进行比较，如果=max，则直接跳到a[0]
//    front=(front+1)%max;//为了保证可以循环,也可以按照下面的方法写
    front=front+1;
    if (front==5){
        front=0;
        return front;
    }
    return front;
}
int main(){
    int a[max];
    int front,rear;
    //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址。
    front=rear=0;
    //入队
    rear=enQueue(a,rear,front,1);
    rear=enQueue(a,rear,front,2);
    rear=enQueue(a,rear,front,3);
    rear=enQueue(a,rear,front,4);
//    rear=enQueue(a,rear,front,5);
    //-----
    front=deQueue(a,front,rear);//1

    rear=enQueue(a,rear,front,5);

    front=deQueue(a,front,rear);//2
//
    rear=enQueue(a,rear,front,6);


    front=deQueue(a,front,rear);//3
    front=deQueue(a,front,rear);//4
    front=deQueue(a,front,rear);//5
    front=deQueue(a,front,rear);
//    printf("%d\n",front);
    return 0;
}