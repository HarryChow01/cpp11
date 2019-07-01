
#ifndef STACK_H
#define STACK_H


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW 1

typedef bool Status;
typedef char StackDataType;

typedef struct {
    StackDataType* base;
    StackDataType* top;
    int stacksize; //current allocated memory(elemtype)
} SqStack;
typedef SqStack Stack;

extern const int STACK_INIT_SIZE;
extern const int STACKINCREMENT;

Status InitStack(SqStack& s);
Status DestroyStack(SqStack& s);
Status DestroyStack2(SqStack& s);
Status ClearStack(SqStack& s);
Status Push(SqStack& s, StackDataType e);
Status GetTop(SqStack s, StackDataType& e);
Status Pop(SqStack& s, StackDataType& e);
Status StackEmpty(SqStack s);
int StackLength(SqStack s);
Status StackTraverse(SqStack s);



#endif /* STACK_H */

