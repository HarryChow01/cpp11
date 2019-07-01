
#include <cstdlib>
#include <cstdio>

#include "stack_tree.h"

const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;

Status InitStack(SqStack& s) {
    s.base = (StackDataType *)malloc(STACK_INIT_SIZE * sizeof(StackDataType));
    if(s.base == NULL)
        exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack& s) {
    StackDataType* p = s.base;
    StackDataType* q = NULL;

    int i;
    for(i = 0; i < s.stacksize; i++) {
        q = p;
        p++;
        free(q);
    }
    return OK;
}

Status DestroyStack2(SqStack& s) {
    delete [] s.base;
    return OK;
}

Status ClearStack(SqStack& s) {
    s.top = s.base;
    return OK;
}

Status StackEmpty(SqStack s) {
    if(s.top == s.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack s) {
    return (s.top - s.base) / sizeof(StackDataType);
}

Status GetTop(SqStack s, StackDataType& e) {
    if(s.top == s.base)
        return ERROR;
    e = *(s.top - 1);
    return OK;
}

Status Push(SqStack& s, StackDataType e) {
    if(s.top - s.base >= s.stacksize) {
        s.base = (StackDataType *)realloc(s.base,
                                          (s.stacksize + STACKINCREMENT) * sizeof(StackDataType));
        if(s.base == NULL)
            exit(OVERFLOW);
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREMENT;
    }
    *s.top++ = e;
}

Status Pop(SqStack& s, StackDataType& e) {
    if(s.top == s.base)
        return ERROR;
    e = *--s.top;
    return OK;
}

Status StackTraverse(SqStack s) {
    StackDataType *p = s.base;
    while(p != s.top) {
        printf("%c ", *p);
        p++;
    }
    printf("\n");
    return OK;
}

#if 0
int main(int argc, char *argv[]) {
    SqStack s;
    StackDataType element;

    InitStack(s);
    StackTraverse(s);
    DestroyStack(s);

#ifdef WIN32
    system("PAUSE");
#endif
    return EXIT_SUCCESS;
}

#endif

