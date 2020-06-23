#include <stdio.h>
#include <malloc.h>
#include "common.h"

NODE *new_node(int data, int type)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->data = data;
    p->type = type;
    p->next = NULL;
    return p;
}

void display(NODE *start)
{
    while (start)
    {
        if (start->type == 0)
            printf("%d ", start->data);
        else
            printf("%c ", start->data);

        start = start->next;
    }
}

void clean(NODE **topp)
{
    NODE *np = *topp;
    NODE *temp;
    while (np != NULL)
    {
        temp = np;
        np = np->next;
        free(temp);
    }
    *topp = NULL;
}