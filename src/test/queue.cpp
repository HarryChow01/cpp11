#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "queue.h"

using namespace std;

#if 0
int main(int argc, char *argv[]) {
    LinkQueue Q;

    InitQueue(Q);
    EnQueue(Q, 'A');
    EnQueue(Q, 'B');
    EnQueue(Q, 'C');
    EnQueue(Q, 'D');
    QueueTraverse(Q);

    QElemType e;
    DeQueue(Q, e);
    DeQueue(Q, e);
    QueueTraverse(Q);
    cout << "QueueLength:" << QueueLength(Q) << endl;
    DestroyQueue(Q);
    printf("Address:%d", Q.front);

#ifdef WIN32
    system("PAUSE");
#endif
    return EXIT_SUCCESS;
}

#endif
