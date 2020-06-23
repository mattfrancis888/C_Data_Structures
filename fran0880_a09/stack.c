#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(STACK *sp, NODE *np)
{
    if (sp->top == NULL)
    {
        sp->top = np;
        sp->top->next = NULL;
    }
    else
    {
        np->next = sp->top;
        sp->top = np;
    }
}

NODE *pop(STACK *sp)
{
    if (sp->top == NULL)
        return NULL;
    NODE *top = sp->top;
    sp->top = sp->top->next;
    top->next = NULL;
    return top;
}

void clean_stack(STACK *sp)
{
    while (sp->top != NULL)
        free(pop(sp));
}
