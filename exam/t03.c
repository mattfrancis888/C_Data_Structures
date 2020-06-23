void reverse(char *s){
   if(s==NULL)return;
   char *p=s,temp;
   while(*p++); // traverse to null position;
   p--; //get rid of null; let p point to last characther
   while(s<p){
    temp=*s;
    *s=*p;
    *p=temp;
    s++;
    p--;
 }
}