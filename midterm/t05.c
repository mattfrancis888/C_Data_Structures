void int2str(int a, char s[]){
    int length = 0;
    int temp = a;

    while(temp != 0){
        temp = temp / 10;
        length++;
    }

    temp = a;
    for(int i = 0; i < length; i++){
        s[length - i - 1] = (temp % 10) + '0';
        temp = temp / 10;
    }

    s[length] = '\0';
}

