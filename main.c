#include <stdio.h>
#include <stdlib.h>

#define Size 5

typedef struct Table {
    int *Head;
    int length;
    int size;
} table;

table initTable() {
    table t;
    t.Head = (int *) malloc(Size * sizeof(int));
    if (!t.Head) {
        printf("err");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}

void displayFun(table t) {
    for (int i = 0; i < t.length; i++) {
        printf("%d\t", t.Head[i]);
    }
    printf("\n");
}

table insertTable(table t, int elem, int index) {
//    printf("aaaaa");
    if (index > t.length + 1 || index < 1) {
        printf("err index");
        return t;
    }

    if (t.length = t.size) {
        t.Head = realloc(t.Head, (t.size + 1) * sizeof(int));
        if (!t.Head) {
            printf("err");
            exit(0);
        }
    }

    for (int i = t.length - 1; i >= index - 1; i--) {
        t.Head[i + 1] = t.Head[i];
    }
    t.Head[index - 1] = elem;
    t.length++;
    return t;
}

table deleteTable(table t,int index){
    if (index > t.length + 1 || index < 1) {
        printf("err index");
        return t;
    }

    for (int i=index-1;i<=t.length-1;i++){
        t.Head[i]=t.Head[i+1];
    }
    t.length--;
    return t;
}
int findTable(table t,int elem){
    for (int i=0;i<t.length;i++){
        if (t.Head[i]==elem){
            return i+1;
        }
    }
    return -1;
}

table updateTable(table t,int elem,int newElem){
    int index=findTable(t,elem);
    t.Head[index-1]=newElem;
    return t;
}


int main() {
    printf("Hello, World!\n");
    table c = initTable();
    for (int i = 0; i < 5; i++) {
        c.Head[i] = i+1;
        c.length++;
    }
    c=insertTable(c,1111,6);
    c=deleteTable(c,6);
    int tt=findTable(c,4);
    displayFun(c);
    printf("this index is:%d\n",tt);
    c=updateTable(c,4,6789);
    displayFun(c);
    return 0;
}
