void display_backward(NODE *start){
    if (start == NULL) return;
    NODE *stk = NULL; *ptr;
    while (start != NULL) {
        insert_beg(&stk, start -> data); //insert into stk
        start = start -> next;
    }
    while (stk != NULL) {
        printf("%d", stk -> data);
        ptr = stk;
        stk = stk -> next;
        free(ptr);
    }
}