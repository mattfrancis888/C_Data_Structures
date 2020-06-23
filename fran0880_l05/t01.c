//Put it at the end of name_list.c and to run just do 
void insert_name_list(sNAME_LIST *name_list,
                      sNODE *node)
{
   int listCount = name_list->count;
   sNODE *currentNode = name_list->front;
   if (listCount == 0)
   {
      name_list->front = node;
      name_list->rear = node;
      name_list->count = 1;
   }

   for (int i = 0; i < listCount; i++)
   {
      if (strcmp(currentNode->name.first_name, node->name.first_name) == 0 && strcmp(currentNode->name.last_name, node->name.last_name) == 0)
      {
         free(node);
         break;
      }
      if (i == listCount - 1)
      {
         currentNode->next = node;
         name_list->rear = node;
         name_list->count++;
      }
      currentNode = currentNode->next;
   }
}