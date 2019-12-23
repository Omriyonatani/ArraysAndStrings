#include <string.h>
#define LINE 256
#define WORD 30
#define FILE 250

char w[WORD];
char s[LINE];

//this function returns the size of the line
int Getline (char s[]) {  
  int count = 0;
  while((s[count] != '\n') && (count < LINE) && s[count] != '\0') {
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
int substring(char * str1, char * str2){
       for (str1; *str1; str1++) {
        if (*str1 == *str2) {
            if (strComp(str1, str2) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

//this helped function to compare between str1 and str2
int strComp(char* str1, char* str2) {
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
    for (str; *str; str++) {
        len++;
    }
    return len;
}


//this function checks if it possible to go from string s to string t by deletion n chars
    int similar(char *s, char *t, int n){
        while (*s) {
        while (*t && *s) {
            if (*s != *t) {
                if (n == 0)
                    return 0;
                n--;
                s++;
            } else {
                s++;
                t++;
            }
        }
    }
    return 1;
}


//This function prints the lines that str exist there
void print_lines(char* str) {
int line_size = 0; 
int i = 0;
while (i<FILE) {
  line_size = Getline(s);
  if (substring(s,str)) printf("%s" , s);
  i++;
  }
}

//This function prints the word that similar to str by up to one letter
void print_similar_words(char* str){
    for(int i=0; i<FILE*LINE; i++){
        char s[WORD];
        getword(s);
        if(similar(str,s,1)){
            printf("%s\n",s);
        }
    }
}

