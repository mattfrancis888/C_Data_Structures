https://www.programmingsimplified.com/c/source-code/c-program-convert-string-to-integer-without-using-atoi-function


//str2int made by shyam dave :)))
int str2int(char *s){
  int res,count=0;
  while(*(s+count)!='\0'){
      res=res*10 + *(s+count)-{0};
      count+=1;
  }
   return res;
}