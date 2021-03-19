#include <stdio.h>
#include <stdlib.h>
//#define Size 5
#define Size 5
typedef struct Table{
    int * head;
    int length;
    int size;
}table;

table initTable(){
    table t;
    t.head=(int *)malloc(Size* sizeof(int));//malloc 函数的作用是什么
    if (!t.head){
        printf("err");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}

void displayTable(table t){
    for (int i = 0; i < t.length; i++) {
        printf("%d",t.head[i]);
    }
    printf("\n");
}

int main() {
    printf("Hello, World!\n");
//    printf(Size);
    table t =initTable();
    printf("%d", sizeof(t.head));
    for(int i=1;i<=Size;i++){
        t.head[i-1]=i;
        t.length++;
    }
    displayTable(t);
    return 0;
}


