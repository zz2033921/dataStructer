//
// Created by 姚政 on 2021/4/10.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct lineStack {
    int data;
    struct lineStack *next;
} lineStack, *ls;

ls push(ls stack, int data) {

    ls newNode = (ls) malloc(sizeof(struct lineStack));
    newNode->data = data;
    newNode->next = stack;
    stack = newNode;
    return stack;
}

ls pop(ls stack) {
    if (stack) {
        printf("当前出栈元素%d\n",stack->data);
        if (stack){
            stack=stack->next;
            printf("新的栈顶元素%d\n",stack->data);
        }
//        else{
//            printf("栈内没有元素\n");
//        }
    } else {
        printf("栈内没有元素\n");
        return -1;
    }
    return stack;
}
int main(){
    lineStack * stack=NULL;
    stack=push(stack, 1);
    stack=push(stack, 2);
    stack=push(stack, 3);
    stack=push(stack, 4);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    return 0;
}