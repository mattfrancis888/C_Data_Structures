#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

int hash(char *word)
{
    unsigned int hash = 0, i;
    for (i = 0; word[i] != '\0'; i++)
    {
        hash = 31 * hash + word[i];
    }
    return hash % htsize;
}

HTNODE *new_hashnode(char *name, int value)
{
    HTNODE *hashnode = (HTNODE *)malloc(sizeof(HTNODE));
    strcpy(hashnode->name, name);
    hashnode->value = value;
    hashnode->next = NULL;
    return hashnode;
}

HASHTABLE *new_hashtable(int size)
{
    HASHTABLE *hashtable = (HASHTABLE *)malloc(sizeof(HASHTABLE));
    hashtable->size = size;
    hashtable->count = 0;
    hashtable->hnp = (HTNODE **)malloc(sizeof(HTNODE) * size);
    for (int i = 0; i < size; i++)
        hashtable->hnp[i] = NULL;
    return hashtable;
}

HTNODE *search(HASHTABLE *ht, char *name)
{
    int index = hash(name);
    if (ht->hnp[index])
    {

        HTNODE *temp = ht->hnp[index];
        while (temp)
        {
            if (strcmp(temp->name, name) == 0)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

int insert(HASHTABLE *ht, HTNODE *np)
{
    int index = hash(np->name);
    HTNODE *temp = ht->hnp[index];
    if (temp) { //pretend like if (a[i])
        while (temp) {
            if (strcmp(temp->name, np->name) == 0) {
                temp->value = np->value; //override value in node
                free(np);
                return 0;
            }
            temp = temp->next;
        }
        temp = np;
        ht->count++;
        return 1;
    }
    //pretend a[i] = x
    *(ht->hnp + index) = np; //simmilar to  HTNODE **temp = &(ht->hnp[index]); double pointer because we are changing the node/struct 
    ht->count++;
    return 1;
    
}

int delete (HASHTABLE *ht, char *name)
{
    int index = hash(name);
    HTNODE *temp = ht->hnp[index], *prev = NULL;
    if (temp)
    {
        while (temp)
        {
            if (strcmp(temp->name, name) == 0)
            {
                if (prev) //if prev is not null
                    prev->next = temp->next;

                if (temp == ht->hnp[index])  //if same, delete 
                {
                    ht->hnp[index] = NULL;
                }
                free(temp);
                ht->count--;
                return 1;
            }
            //iterate
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
}

void clean_hash(HASHTABLE **htp)
{
    if (*htp == NULL)
        return;
    HASHTABLE *ht = *htp;
    HTNODE *sp = ht->hnp[0], *p, *temp;
    int i;
    for (i = 0; i < ht->size; i++)
    {
        p = ht->hnp[i];
        while (p)
        {
            temp = p;
            p = p->next;
            free(temp);
        }
        ht->hnp[i] = NULL;
    }
    free(ht->hnp);
    ht->hnp = NULL;
    *htp = NULL;
}

void display_hashtable(HASHTABLE *ht, int option)
{
    int i = 0;
    HTNODE *p;
    if (option == 0)
    {
        printf("size:  %d\n", ht->size);
        printf("count: %d\n", ht->count);
        printf("hash data:\nindex: list of the data elements");
        for (i = 0; i < ht->size; i++)
        {
            p = *(ht->hnp + i);
            if (p)
                printf("\n%2d: ", i);
            while (p)
            {
                printf("(%s, %d) ", p->name, p->value);
                p = p->next;
            }
        }
        printf("\n");
    }
    else
    {

        for (i = 0; i < ht->size; i++)
        {
            p = *(ht->hnp + i);
            while (p)
            {
                printf("%s=%d\n", p->name, p->value);
                p = p->next;
            }
        }
    }
}