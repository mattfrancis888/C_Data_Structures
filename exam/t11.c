//11
/*  
 * @param Heap - start pointer of binary heap array 
 * @param index - start position of heapify
*/
void heapify_up(int *Heap, int index) {
	int parent,val = Heap[index];
	
	while(index){
		parent = (index+1)/2;
		if(Heap[parent] >= val){ //if parent is greater than val; no need to heapify
			break;
		}else{
			Heap[index] = Heap[parent]; //swap with parent
			index = parent; //swap the index
		}
		
	}
	Heap[index] = val; //finally assign the val
}

/*  
 * @param Heap - start pointer of binary heap array 
 * @param index - start position of heapify
 * @param n - the size of heap
*/
void heapify_down(int *Heap, int index, int n) {
	int val = Heap[0];
	int ci = index/2 + 1;
	
	while(ci <= n){
		if(ci < n && Heap[ci] < Heap[ci + 1]){
			ci++;
		}
		if(Heap[ci] > val){
			break;
		}else{
			Heap[index] = Heap[ci];
			index = ci;
			ci = index/2 + 1;
		}
	}
	Heap[index] = val;
}

/*
*  in place sort, increasing order, put the max element at end, delete, 
*  after Heap array hold the increasing order of the elements. 
*/
void heap_sort_heap(int *Heap) {
	int i, temp, n = size;
	for(i = 0; i < n; i++){
		temp = Heap[0];
		Heap[0] = Heap[size-1];
		Heap[size-1] = temp;
		
		size--;
		heapify_down(Heap,0,size-1);
	}

}

void insert(int *Heap, int value) {
	Heap[size] = value;
	Heapify_up(Heap,size);
	size++;
}

void delete(int *Heap) {
	Heap[0] = Heap[size-1];
	size--;
	Heapify_down(Heap,0,size-1);

}

 void heap_sort_array(int a[], int n) {
  int i, index, swindex;
  int val;
  for (i = 0; i<n; i++) {  //insert into max-heap
    //heapify-up
    index = i;
    val = a[index];
    while (index) {
       swindex = (index-1) >> 1;  //equivalent to swindex = (index-1)/ 2;
      if (a[swindex] >= val) break;
      else {
        a[index] = a[swindex];
         index = swindex;
      }
    }
    a[index] = val;
  } 
  
  for (i=n-1; i>=0; i--) { 
     //extract max and put to back, i.e. swap the top and the last heap elements. 
     val = a[i];
     a[i] = a[0];
     a[0] = val;
  
     //heapify-donw
     index = 0;
     swindex =  index << 1) + 1; //left child, equivalent to swindex = index * 2 + 1;
     while (swindex <= i-1) { // if has the left child 
       if ((swindex < i-1) && (a[swindex] < a[swindex+1])) 
         swindex++;  // swindex is now the child of bigger key
    
       if (a[swindex] < val)
          break;   // the both children has key values less the val, done stop.   
       else {
         a[index] = a[swindex]; //change key value by the bigger child's value 
         index = swindex; 
         swindex = (index << 1) + 1; 
       }
     }
     a[index] = val; 
  }
}