//
// Created by 姚政 on 2021/4/12.
//

#include "stdio.h"
#include "stdlib.h"

typedef struct QNode {
    int data;
    struct QNode *next;
} node;

node *initQueue() {
    //创建一个头结点
    node *queue = (node *) malloc(sizeof(node));
    queue->next = NULL;
    return queue;
}

node *enQueue(node *rear, int data) {
    //1.用节点包裹入队元素
    node *enElem = (node *) malloc(sizeof(node));
    enElem->data = data;
    enElem->next = NULL;

    //2.新节点与rear节点建立逻辑关系
    rear->next = enElem;

    //3.rear指向新节点
    rear = enElem;
    //返回新的rear，为后续元素入队做准备
    return rear;
}

//含头结点的队列，top是指向头结点的指针。头指针
node *delQueue(node *top, node *rear) {
    if (top->next == NULL) {
        printf("队列为空\n");
        return 0;
    }
    node *p = top->next;//
    printf("%d\n", p->data);
    top->next = p->next;
    if (rear == p) {
        rear = top;
    }
    free(p);
}

int main() {
    node *queue, *top, *rear;
    queue = top = rear = initQueue();//创建头结点
    //向链队列中添加节点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
}