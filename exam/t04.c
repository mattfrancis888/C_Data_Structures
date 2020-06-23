int is_palindrome(char *str){
   char *p=str;
   while(*p++);
   p--;
   while(str < p){
     if(*str!=*p)return 0;
     str++;
     p--;
  } 
  return 1;
 }
