https://www.programmingsimplified.com/c/source-code/c-program-convert-string-to-integer-without-using-atoi-function


//str2int made by shyam dave :)))
int main(void) {
  int res=0;
  int i=0;
  char s[100] = "123";

  while(*(s+i)!='\0'){
    res=res*10 + *(s+i) - '0';
    i++;
  }
  printf("%d", res);
  return 0;
}
