//NOTE TO ME: MAKE SURE TO ADD TO STRING ARRAY!!
int main(void) {
   char s[1000], r[1000];
   int begin, end, count = 0;

   printf("Input a string\n");
   scanf("%s", s); //store in s; s does not use &s becuase it is a %s

   // Calculating string length

   while (s[count] != '\0')
      count++;

   end = count - 1;

   for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }

   r[begin] = '\0';

   printf("%s\n", r);

}
https://www.programmingsimplified.com/c-program-reverse-string