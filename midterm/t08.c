#include "mystring.h"

int letter_count(char *s) {
    if (s == NULL)  return  -1;
    int counter = 0;
    char *p = s;
    while (*p) {
        if ( (*p >= 'a' &&  *p <= 'z') ||(*p >= 'A' &&  *p <= 'Z') )    // pattern   
            counter++;   // action
        p++;             // move to next
    }
    return counter; 
}

void lower_case(char *s) {
    if (s == NULL)  return;
    int counter = 0;
    char *p = s;
    while (*p) {
        if (*p >= 'A' && *p <= 'Z')    // pattern   
            *p += 32;   // action
        p++;             // move to next
    }
     
}

int word_count(char *s) {
// your implementation
    if (s == NULL ) return -1;
    int counter = 0;
    char *p = s;
    char prevWord = ' '; //Needs to be defined as ' ' because of prevword if statement below
    while (*p) {
        if (*p == ' ')   {  // pattern
            if(prevWord != ' '){
                counter++;  // action
            }
        }
        prevWord = *p; 
        p++;            //next
    } 
    return counter; 
}

void trim(char *s) {
// given in lecture
    if(s == NULL || *s == '\0') return;
    char *p = s, *dp = s;
    while (*p) {
        if (*p != ' ' || (p > s && *(p - 1) != ' '))
            *dp++ = *p;
        p++;
    }
    if (*(p - 1) == ' ') *(dp - 1) = '\0';
    else *dp = '\0'; 
}