//
// Created by 姚政 on 2021/3/21.
//
#include <stdio.h>
#include <stdlib.h>

//构造节点
typedef struct Link {
    int elem;
    struct Link *next;
} link;

//无头结点
link *initLinkNodeNo() {
    link *p = NULL;//1
    link *temp = (link *) malloc(sizeof(link));//2
    //首元节点
    temp->elem = 1;//3
    temp->next = NULL;//4
    p = temp;//p只是一个指向temp链表的指针
    for (int i = 2; i < 5; ++i) {
        //创建新节点并初始化
        link *a = (link *) malloc(sizeof(link));// 5.1
        a->elem = i;//5.2
        a->next = NULL;//5.3
        //将a链接到temp的下一个位置。
        temp->next = a;//5.4
        //把temp更新到最后一个，让temp始终指向到链表的最后一位。
        temp = temp->next;//5.5
    }

    return p;
}

//含头结点
//那么此时，p就不再指向temp链表，而是p中的next指向temp中的首元结点
// O=A=B=C=D
link *initLinkNode() {
    link *p = (link *) malloc(sizeof(link));
    link *temp = p;//指向头结点
    //生成链表
    for (int i = 1; i < 5; i++) {
        link *a = (link *) malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;//temp当前指向是的p，那么p.next就指向了a。
        temp = temp->next;//当p.next指向a后，将temp指向当a。始终让temp指针指向最后一个。
    }
    return p;//将p设置为结点(头结点)，p.next后跟上temp
}

link *noFirstNode() {
    link *p = NULL;
    link *temp = (link *) malloc(sizeof(link));
    temp->elem = 1;
    temp->next = NULL;
    p = temp;
    for (int i = 2; i < 5; ++i) {
        link *a = (link *) malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

link *firstNode() {
    link *p = (link *) malloc(sizeof(link));
    link *temp = p;
    for (int i = 1; i < 5; ++i) {
        link *a = (link *) malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

void display(link *l) {
    link *p = l;
    while (p) {
        printf("%d\t", p->elem);
        p = p->next;
    }
}

void nodeDisplay(link *l) {
    link *p = l;
    printf("%d\t", p->elem);

    while (p->next) {
        p = p->next;
        printf("%d\t", p->elem);
//        p=p->next;

    }
}

//插入节点
link *insertLink(link *p, int elem, int index) {
    link *temp = p;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    link *c = (link *) malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

//链表删除元素
link *deleteLink(link *p, int index) {
    link *temp = p;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    link *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

//查找元素
int findLink(link *p, int elem) {
    link * t=p;
    int i=1;
    //判断头节点
    while (t->next){
        t=t->next;
        if(t->elem==elem){
            return i;
        }
        i++;
    }
    return -1;
}

//更新元素
link *updateLink(link *p,int index,int newElem) {
link *temp=p;
temp=temp->next;//跳过头结点、指向首元节点
    for (int i = 1; i <index ; i++) {
        temp=temp->next;
    }
    temp->elem=newElem;
    return p;
}


int main() {
    printf("Hello, World!\n");
//    link *cc=firstNode();
//    nodeDisplay(cc);
    link *cc = noFirstNode();
    display(cc);
    return 0;
}