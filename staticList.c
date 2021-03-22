//
// Created by 姚政 on 2021/3/22.
//
#include <stdio.h>
#include <stdlib.h>

#define maxSize 6
typedef struct {
    int data;
    int cur;
} component;


// 所有分量链接到备用链表中---创建备用链表
void reserveArr(component *array) {
    for (int i = 0; i < maxSize; i++) {
        array[i].cur = i + 1;
        array[i].data = -1;
    }
    array[maxSize - 1].cur = 0;
}

//提取分配空间---构造malloc函数
int mallocArr(component *array) {
    //备用链表非空返回分配的结点下标
    //备用链表空则返回0
    int i = array[0].cur;//1
    if (array[0].cur) {
        array[0].cur = array[i].cur;//2
    }
    return i;//1
}

//初始化静态链表
int initArr(component *array) {
    reserveArr(array);
    int body = mallocArr(array);//1
    //声明一个变量，当成指针，始终指向当前链表的最后一个。因为链表为空，所以和头结点重合。当
    int tempBody = body;//1
    for (int i = 1; i < 4; i++) {
        int j = mallocArr(array);//取出空闲分量//2
        array[tempBody].cur = j;//将其当前节点追加到头结点(tempBody指针指向的节点)后面。
        array[j].data = i;//初始化当前数据源
        tempBody = j;//将琳指针指到当前链表的最后一个节点
    }
    array[tempBody].cur = 0;//当前指向链表的最后节点的cur(下一个设为0)
    return body;
}

//展示函数
void displayArr(component *array, int body) {
    int tempBod = body;
    while (array[tempBod].cur) {
        printf("%d,\t在备用链表的index:%d,\t当前指向的后继位置cur在备用链表中的位置:%d\n", array[tempBod].data, tempBod, array[tempBod].cur);
        tempBod = array[tempBod].cur;
    }
//    printf("%d,%d\n", array[tempBod].data, array[tempBod].cur);
    printf("%d,\t在备用链表的index:%d,\t当前指向的后继位置cur在备用链表中的位置:%d\n", array[tempBod].data, tempBod, array[tempBod].cur);

}

//添加函数
//1.从备用链表中摘除一个节点。(申请节点)insert
//2.找到要插入位置的前一个位置index。
//3.array[insert].cur=array[index].cur
//4.array[index].cur=array[insert]
void insertArr(component *array, int body, int add, int a) {
    int tempBody = body;//遍历节点数组用
    for (int i = 1; i < add; ++i) {
        tempBody = array[tempBody].cur;
    }
    int insert = mallocArr(array);
    array[insert].data = a;
    array[insert].cur = array[tempBody].cur;
    array[tempBody].cur = insert;
}

//删除函数
//1.将目标元素从节点数组中删除
//2.将释放的节点恢复到备用链表中
void freeArr(component *array, int k) {
    array[k].cur = array[0].cur;
    array[0].cur = k;
}

void deleteArr(component *array, int body, int a) {
    int tempBody = body;
    while (array[tempBody].data != a) {
        tempBody = array[tempBody].cur;
        //当tempBody为0时，表示链表遍历结束。说明链表中没有存储该数据的节点。
        if (tempBody == 0) {
            printf("no data");
            return;
        }
    }
    //至此，说明有该节点
    int del = tempBody;
    tempBody = body;
    //找到该节点的上一个节点
    while (array[tempBody].cur != del) {
        tempBody = array[tempBody].cur;
    }
    array[tempBody].cur = array[del].cur;
    freeArr(array, del);
}

//查找元素
int selectElem(component *array, int body, int elem) {
    int tempBody = body;
    while (array[tempBody].cur != 0) {
        int cc=array[tempBody].data;
        tempBody = array[tempBody].cur;
        if (array[tempBody].data == elem) {

            return tempBody;
        }

    }
    return -1;//返回-1，表示链表中没有找到该元素
}

//更新数据
void updateElem(component *array, int body, int oldElem, int newElem) {
    int add = selectElem(array, body, oldElem);
    if (add = -1) {
        printf("无更改元素");
        return;
    }
    array[add].data = newElem;
}

int main() {
    printf("good boy");
    component array[maxSize];
    int body = initArr(array);
    printf("静态链表为：\n");
    displayArr(array, body);

    printf("\n第3个位置上插入 333 \n");
    insertArr(array, body, 3, 333);
    displayArr(array, body);

    printf("\n第3个位置上删除 333 \n");
    deleteArr(array,body,333);
    displayArr(array, body);

//    printf("\n修改第3个位置上的元素为 333 \n");
//    updateElem(array,body,3,333);
//    displayArr(array, body);

    printf("\n查找元素3在数组(备用链表)中的位置 \n");
    int result=selectElem(array,body,3);
    printf("***%d***\n",result);
    return 0;
}