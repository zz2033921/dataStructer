//
// Created by 姚政 on 2021/3/22.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct line *prior;//前驱节点
    int data;
    struct line *next;//后继节点
} line;

line *initLine(line *head) {
    //1.创建首元节点，链表的头指针为head
    head = (struct line *) malloc(sizeof(line));
    //2.对首元节点进行初始化
    head->data = 1;
    head->prior = NULL;
    head->next = NULL;
    //3.声明一个指向首元节点的指针，方便后期向链表添加新创建的节点。
    line *list = head;
    for (int i = 2; i <= 5; i++) {
        line *body = (line *) malloc(sizeof(struct line));
        body->next = NULL;
        body->prior = NULL;
        body->data = i;

        list->next = body;
        body->prior = list;

        //让list指针始终指向最后
        list = list->next;
    }

    return head;
}

void displayList(line *head) {
    //1.声明工具指针,指向head，当前双向链表
    line *body = head;
    //2.进行循环处理
    while (body) {
        if (body->next == NULL) {
            printf("%d\n", body->data);
        } else {
            printf("%d <-> ", body->data);
        }
        body = body->next;
    }
}

//添加节点
line *insertLine(line *head, int data, int add) {
    //新建数据域为data的结点
    line *temp = (line *) malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    } else {
        line *body = head;
        for (int i = 1; i < add - 1; i++) {
            body = body->next;
        }
        //判断条件为真，说明插入位置为链表尾部
        if (body->next == NULL) {
            body->next = temp;
            temp->prior = body;
        } else {
            body->next->prior = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;

        }
    }
    return head;
}

//删除节点
line *delLine(struct line *head, int data) {
    line *temp = head;
    while (temp) {
        if (temp->data = data) {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}

//查找节点
int selectElem(line *head, int elem) {
    //新建一个指针t，初始化为头指针head
    line *t = head;
    int i = 1;
    while (t) {
        if (t->data == elem) {
            return i;
        }
        i++;
        t = t->next;
    }
    //执行到这里的时候说明没有找到，查询失败
    return -1;
}

//更改节点 1 2 3 4 5 6 7 8
line *updateElem(line *p, int add, int newElem) {
    line *temp = p;
    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->data = newElem;
    return p;
}

int main() {
    printf("good booy\n ");
    line *cc = (line *) malloc(sizeof(line));
    line *head = initLine(cc);
    displayList(head);

    printf("\n");
    head = updateElem(head, 3, 6);
    displayList(head);

    printf("\n");
    head = insertLine(head, 999, 3);
    displayList(head);

}
