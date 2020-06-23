int evaluate_polynomial(int a[],int n,int x){
  int s=a[0];
  for(int i=1;i<n;i++){
     s=s*x + a[i];
  }
   return s;
}
