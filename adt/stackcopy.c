#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// forward declaration
unsigned long size();
status isEmpty();
status isFull();
void destroy();


int* elementsStack1 = NULL;
short topOfStack = -1;

void create1(){
    destroy1();
    elementsStack1 = (int*)malloc(MAX_SIZE_STACK * sizeof(int));
    topOfStack = -1;
    return;
}

void destroy1(){
    if(NULL != elementsStack1){
        free(elementsStack1);
        elementsStack1 = NULL;
    }
    return;
}

status push1(int val){
    if(STACK_FALSE == isFull1()){
        topOfStack++;
        elementsStack1[topOfStack] = val;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status pop1(int* ptrVal){
    if(STACK_FALSE == isEmpty1()){
        *ptrVal = elementsStack1[topOfStack];
        topOfStack--;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status peek1(int* ptrVal){
     if(STACK_FALSE == isEmpty1()){
        *ptrVal = elementsStack1[topOfStack];
        //topOfStack--;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

unsigned long size1(){
    return topOfStack + 1;
}

status isEmpty1(){
    if(-1 == topOfStack)
        return STACK_TRUE;

    return STACK_FALSE;
}

status isFull1(){
    if(MAX_SIZE_STACK == topOfStack + 1)
        return STACK_TRUE;

    return STACK_FALSE;
}

void printStack1(){
    if(STACK_TRUE == isEmpty())
        return;

    printf("++++++++++++\n");
    for(short i=topOfStack; i > -1; i--){
        printf("Element %d: %d\n", i, elementsStack1[i]);
    }
    printf("-----------\n");
}
