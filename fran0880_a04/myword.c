// add your program signature
#include "myword.h"
#include <string.h>
void set_stopword(char *filename, char *stopwords[])
{   //note to me: read stop words from file and put into stopwords[]
    FILE *fp = fopen(filename, "r"); //open file for reading
    
    char line[1000];
    char delimiters[] = ".,\n\t\r";
    char *token;
    
    int i;
    
    while (fgets(line, 1000, fp) != NULL)                               
    {
        token = (char*) strtok(line, delimiters);
        
        while (token != NULL)
        {
            i = (int) (*token - 'a');
            strcat(stopwords[i], token);
            strcat(stopwords[i], ",");
            token = (char*) strtok(NULL, delimiters);
        }
    }
    
    fclose(fp);
}


// this function checks if the word is contained in directory stopwords[] 
// returns 1 if yes, 0 otherwise. It use function str_contain_word()
int contain_word(char *stopwords[], char *word)
{
    if (word == NULL || *word == '\0')
        return 0;
    else
    {
        return str_contain_word(stopwords[*word - 'a'], word);
    }
}

// this function check if word is a word in string str, 
// returns 1 if yes, 0 otherwise
int str_contain_word(char *str, char *word){
    if (str == NULL || word == NULL) return 0;
        
    char temp[20] = {0};
    strcat(temp, ",");   
    // use , as word separator
    strcat(temp, word);
    strcat(temp, ",");
    if (strstr(str, temp)) // you can string.hfunction strstrto see if str contains temp 
        return 1;
    else       
        return 0;
        // You can also write your program to check if strcontains tem
    
}

int process_word(char *filename, WORDSUMMARY *words, char *stopwords[])
{
  FILE *fp = fopen(filename, "r");                                          //open file to read 
  const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";                     
  char line[1000];                                                        
  char *word_token;                                                         //pointer
    
  while (fgets(line, MAX_LINE_LEN, fp) != NULL)                             //loop until end of file
  {
      words->line_count++;                                                  //add 1 to the line_count of words struture
      lower_case(line);                                                  
      trim(line);                                                          
      word_token = (char*) strtok(line, delimiters);                        //point word_token to first char in line split by delimiters 
      
      while (word_token != NULL)                                            //loop until end of line
      {
          words->word_count++;                                    
          
          if (contain_word(stopwords, word_token) == 0)                     //word not in stopwords
          {
              int i = 1;

              if (strcmp(word_token, words->word_array[i].word) == 0)       //word exist in the array
              {
                  if (i >= 0 && i < words->keyword_count)               
                  {
                      words->word_array[i].frequency++;
                  }
              }
              else 
              {
                  i = words->keyword_count;
                  strcpy(words->word_array[i].word, word_token);
                  words->word_array[i].frequency = 1;
                  words->keyword_count++;
              }
          }
          
          word_token = (char*) strtok(NULL, delimiters); //next word
      }
  }
  
  fclose(fp);
  
}

int save_to_file(char *filename, WORDSUMMARY *words)
{
  FILE *fp = fopen(filename, "w");

  fprintf(fp, "%-20s  %8d\n", "Line count", words->line_count);
  fprintf(fp, "%-20s  %8d\n", "Word count", words->word_count);
  fprintf(fp, "%-20s  %8d\n", "Keyword count", words->keyword_count);
  fprintf(fp, "%-18s  %10s\n", "Keyword", "frequency");
  
  for (int i = 0; i < (*words).keyword_count; i++) {
      fprintf(fp, "%-20s  %8d\n", words->word_array[i].word, words->word_array[i].frequency);
  }
  fprintf(fp, "\n");
  fclose(fp);
  return 1;
}