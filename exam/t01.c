
void transpose(int *m,int n){
   int i,j;
   int temp;
   for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         temp=*(m+i*n+j);
         *(m+i*n+j)=*(m+j*n+i);
         *(m+j*n+i)=temp;
     }
   }
}

