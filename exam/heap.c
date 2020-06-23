
void insert(HEAP *heap, HNODE new_node)
{
  unsigned int index, parent;
  HNODE *temp;

  // Resize the array if it is overflow
  if (heap->size == heap->capacity)
  {
    heap->capacity <<= 1;
    temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
      if (temp) {
      heap->hnap = temp;
    } else {
      temp = malloc(sizeof(HNODE) * heap->capacity);
      if (temp) {
        memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
        free(heap->hnap);
        heap->hnap = temp;
      } else {
        printf("memory expansion failed\n");
        exit(1);
      }
    }
  }
  
  for(index = heap->size++; index; index = parent)
  {
    parent = (index - 1) >> 1;
    if (cmp(heap->hnap[parent].key, new_node.key)<=0)
      break;
    heap->hnap[index] = heap->hnap[parent];
  }
  heap->hnap[index] = new_node;
}

HNODE extract_min(HEAP *heap)
{
  unsigned int index, swap, other;
  HNODE top = heap->hnap[0];
  HNODE temp = heap->hnap[--heap->size];

  // Resize the array size to a 1/4
  if ((heap->size <= (heap->capacity >> 2)) && (heap->capacity > MIN_CAPACITY)) {
    heap->capacity >>= 1;
    heap->hnap = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
    if (!heap->hnap) exit(1); 
  }

  //heapify_down
  for(index = 0; 1; index = swap) {
    swap = (index << 1) + 1;
    if (swap >= heap->size) break;
    other = swap + 1;
    if ((other < heap->size) && cmp(heap->hnap[other].key, heap->hnap[swap].key)<=0)
      swap = other;
    if (cmp(temp.key, heap->hnap[swap].key)<=0)
      break;
    heap->hnap[index] = heap->hnap[swap];
  }

  heap->hnap[index] = temp;
  return top;
}