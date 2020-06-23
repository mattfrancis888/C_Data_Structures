//sort is in a03

void selection_sort(int *a, int left, int right)
{   
    //left is the beginigng and right is the end of the array
     int i, j, k;
     // printf("SIZE: %d \n", right + 1); //right gives out size of 8 instead of size of 9. len - 1 is simmilar to sizeof(array)/sizeof(a)
     // printf("LEFT AND RIGHT: %d  %d \n", left, right);
     // printf("ARRAY %d: \n",*a);
     for (i = left; i < right + 1; ++i) {
         k = i;
         for(j = i+1; j < right + 1 ; ++j) {
            if (*(a+j) < *(a+k)){
                k = j;
            }
        }
        if (i!= k) {
            swap(*(a+k), *(a+i));      
        }
    }
}

void quick_sort(int *a, int left, int right)
{ 
    int key,i,j,k;
    if( left < right ) {  
        k = (left+right)/2; //midpt
        // use *(a+k) as the pivot; 
        swap(*(a+left), *(a+k)); //swap left with pivot

        i = left +1; //move to right
        j = right;
        key = a[left];
        while(i <= j) {
            // split  such that elements from left to j  are less or equal *(a+k) 
            while((i <= right) && (a[i] <= key))
                i++; //keep moving to right

            //  elements from  j+2 to right  are bigger than  *(a+k) 
            while((j >= left) && (a[j] > key))
                j--; //move to left
            if( i < j)
                swap(*(a + i), *(a + j));
        }
        swap(*(a + left), *(a + j));

        quick_sort(*a, left, j-1); //a or a* dosent matter
        quick_sort(*a, j+1, right); 
     }
     //do nothing if left > right

}