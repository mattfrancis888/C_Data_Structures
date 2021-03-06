#include "heap.h"

HEAP *new_heap(int capacity)
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    heap->capacity = capacity;
    heap->size = 0;
    heap->hnap = (HNODE *)malloc(sizeof(HNODE) * capacity);
}

void insert(HEAP *heap, HNODE new_node)
{
//https://media.discordapp.net/attachments/676264655798403084/692779850175610930/binaryheap.png
//breath first 
//code given for resizing:
//temp is being reallocated, if heap->hnap doesn't exist or isn't malloc'd to begin with there's nothing to realloc
//in which case you run the else which mallocs it
//if the 2nd else is ran (can be whatever) and it failed
    if (heap->size < heap->capacity)
    {
        heap->hnap[heap->size] = new_node; //last index is new node
    }
    else
    {
        heap->capacity *= 2; //increase size
        HNODE *temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity); //reallocate memory

        if (temp)
        {
            heap->hnap = temp;
        }
        else
        {
            temp = malloc(sizeof(HNODE) * heap->capacity);
            if (temp)
            {
                memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
                free(heap->hnap);
                heap->hnap = temp;
            }
            else
            {
                printf("array resize failed\n");
            }
        }
        heap->hnap[heap->size] = new_node;
    }
    //end of code given
    heap->size++;
    int curr_index = heap->size - 1; //refer to last index
    int parent_index = (curr_index - 1) / 2;
    while (cmp(heap->hnap[curr_index].key, heap->hnap[parent_index].key) == -1) //curent index (the child) is lower than parent index 
    //(min- heap)
    {
        HNODE temp = heap->hnap[curr_index];
        heap->hnap[curr_index] = heap->hnap[parent_index]; //swap with parent
        heap->hnap[parent_index] = temp; 
        //update index
        curr_index = parent_index;
        parent_index = (curr_index - 1) / 2;
    }
    return;
}

HNODE extract_min(HEAP *heap)
{
    HNODE min = heap->hnap[0];
    heap->hnap[0] = heap->hnap[heap->size - 1];
    free(heap->hnap + heap->size - 1);
    heap->size--;
    int curr_index = 0;
    
    //for child index, if it helps:https://gyazo.com/55b3c303b7187214b2e6802276783d5b
    int child_index = 2 * curr_index + 2 < heap->size ? 
    cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 
    ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
    
    while (cmp(heap->hnap[curr_index].key, heap->hnap[child_index].key) == 1)
    {
        HNODE temp = heap->hnap[curr_index];
        heap->hnap[curr_index] = heap->hnap[child_index];
        heap->hnap[child_index] = temp;
        curr_index = child_index;
        child_index = 2 * curr_index + 2 < heap->size ? cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
    }
    if (heap->size < heap->capacity / 2)
    {
        heap->capacity /= 2; //shrink the data
        HNODE *temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
        if (temp)
        {
            heap->hnap = temp;
        }
        else
        {
            temp = malloc(sizeof(HNODE) * heap->capacity);
            if (temp)
            {
                memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
                free(heap->hnap);
                heap->hnap = temp;
            }
            else
            {
                printf("array resize failed\n");
            }
        }
    }
    return min;
}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value)
{
    if (heap->hnap[node_index].key > key_value)
    {
        heap->hnap[node_index].key = key_value;
        int curr_index = 0;
        int child_index = 2 * curr_index + 2 < heap->size ? cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
        while (cmp(heap->hnap[curr_index].key, heap->hnap[child_index].key) == 1)
        {
            HNODE temp = heap->hnap[curr_index];
            heap->hnap[curr_index] = heap->hnap[child_index];
            heap->hnap[child_index] = temp;
            curr_index = child_index;
            child_index = 2 * curr_index + 2 < heap->size ? cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
        }
    }
    else
    {
        heap->hnap[node_index].key = key_value;
        int curr_index = heap->size - 1;
        int parent_index = (curr_index - 1) / 2;
        while (cmp(heap->hnap[curr_index].key, heap->hnap[parent_index].key) == -1)
        {
            HNODE temp = heap->hnap[curr_index];
            heap->hnap[curr_index] = heap->hnap[parent_index];
            heap->hnap[parent_index] = temp;
            curr_index = parent_index;
            parent_index = (curr_index - 1) / 2;
        }
    }
}

int find_index(HEAP *heap, DATA value)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (heap->hnap[i].data == value)
            return i;
    }
    return -1;
}

void display_heap(HEAP *hp)
{
    printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
    printf("(index, key, data):\n");
    int i;
    for (i = 0; i < hp->size; i++)
    {
        printf("(%d %d %d) ", i, hp->hnap[i].key, hp->hnap[i].data);
        if (i % 10 == 9)
            printf("\n");
    }
    printf("\n");
}

int cmp(KEYTYPE a, KEYTYPE b)
{
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}