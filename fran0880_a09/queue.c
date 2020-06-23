#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np)
{
    if (qp->front == NULL)
    {
        qp->front = np;
        qp->rear = np;
        qp->front->next = qp->rear->next = NULL;
    }
    else
    {
        qp->rear->next = np;
        qp->rear = np;
        qp->rear->next = NULL;
    }
}

NODE *dequeue(QUEUE *qp)
{
    if (qp->front == NULL)
        return NULL;
    NODE *ptr = qp->front;
    qp->front = ptr->next;
    return ptr;
}

void clean_queue(QUEUE *qp)
{
    while (qp->front != NULL)
        free(dequeue(qp));
}