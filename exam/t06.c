
WORD frequent_word(const char *s){
        
    typedef struct word{
        char data[50];
        int count;
    }WORD;

    typedef frequency{
        WORD array[50];
        int maxindex;
    }FREQ;

	FREQ freq = {0};
	char *tok = strtok(s," ");
	
	while(tok){
		for(int i = 0; i <  sizeof(freq.array);i++){
			if(strcmp(freq.array[i].data,tok) == 0){
				freq.array[i].count++;
				if(freq.array[i].count > freq.array[maxindex].count){
					maxindex = i;
					break;
				}
			}else if(freq.array[i] ==0){
				strcpy(tok,freq.array[i].data);
				freq.array[i].count++;
				break;
			}
		}
		tok = strtok(NULL, " ");
	}
	return freq.array[maxindex];
}
