#include <iostream>
using namespace std;

typedef bool Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW 1

typedef char QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = QueuePtr(malloc(sizeof(QNode)));
    if(!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    while(Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue &Q) {
    QueuePtr p = Q.front->next;

    while(p) {
        Q.front->next = p->next;
        free(p);
        p = Q.front->next;
    }
    Q.rear = Q.front;
    return OK;
}

Status QueueEmpty(LinkQueue Q) {
    return (Q.rear == Q.front);
}

int QueueLength(LinkQueue Q) {
    int len = 0;
    QueuePtr p = Q.front->next;
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

Status GetHead(LinkQueue Q, QElemType &e) {
    if(Q.front == Q.rear)
        return ERROR;
    else
        e = Q.front->next->data;
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p = QueuePtr(malloc(sizeof(QNode)));
    if(!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
    if(Q.front == Q.rear)
        return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q) {
    QueuePtr p = Q.front->next;

    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    return OK;
}












