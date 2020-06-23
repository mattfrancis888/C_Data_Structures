void int2str(int n, char s[]){
    char *p = s;
    int temp = m;
    int num;
    int len;
    
    while (temp != 0){
        temp = temp/10;
        len++;
        }
    temp =n;
    for (int i=0; i <len; i++){
        s[len-1-i] = (temp %10) +'0';
        temp = temp/10}
    s[len] = '\0';
    }