#include "txtfind.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define FILE 250

char w[WORD];
char s[LINE];

//this function returns the size of the line
int Getline (char s[]) {
  int count=0;
  while((s[count]!='\n') && (count < LINE) && (s[count] != '\0')) {
    count++;
  }
  return count;
}

//this function returns the size of the word
int getword (char w[]){
int count=0;
while((w[count]!='\n') && (w[count]!='\t') && (w[count]!=' ') && (count < WORD) && (w[count] != '\0')){
  count++;
}
return count;
}

//This function checks if str1 contains str2 
int substring(char* str1, char* str2) {
    for (str1=str1; *str1; str1++) {
        if (*str1 == *str2) {
            if (strComp(str1, str2) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

//this helped function to compare between str1 and str2
int strComp(char* str1, char* str2){
    if (!*str1 || !*str2) return 0;
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return 1;
}

//the function returns str length
int strLen(char* str) {
    int len = 0;
    for (str=str; *str; str++) {
        len++;
    }
    return len;
}

//this function checks if it possible to go from string s to string t by deletion n chars

int similar(char* s, char* t, int n) {
    if (strLen(s) < strLen(t)) return 0;
    if (strLen(s) == strLen(t)) return strComp(s, t);
    // printf("%s %s", s, t);
    int ti = 0;
    int si = 0;
    
    while (*(t+ti) && *(s+si)) {
        if (*(t+ti) != *(s+si)) {
            n--;
            si++;

            if (n < 0) {
                return 0;
            }
        } else {
            si++;
            ti++;
        }
    }

    int slen = strLen(s+si);

    if (slen - n > 0) {
        return 0;
    } else {
        return 1;
    }
}

//This function prints the word that similar to str by up to one letter
void print_similar_words(char* str){
    char s[LINE];       // the whole line
    char word[WORD];    // the word that i check

    while(fgets(s,FILE,stdin)){
        int wordLength = 0;
        int lineLength = 0;

        while (*(s+lineLength) != 0) {
            while (*(s+lineLength) != ' ' 
            && *(s+lineLength) != '\t' 
            && *(s+lineLength) != '\n'
            && *(s+lineLength) != '\0') {
                *(word+wordLength) = *(s+lineLength);
                wordLength++;
                lineLength++;
            }

            if (*(s+lineLength)) {
                lineLength++; 
            }

            *(word+wordLength) = '\0';
            wordLength=0;

            if (similar(word, str, 1)) {
                printf("%s\n", word);
            }
        }
    }
}

void print_lines(char* str){
    char s[LINE];
    while(fgets(s,LINE,stdin)){
        if (substring(s,str)){
            printf("%s",s);
        }
    }
}
