#include "txtfind.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define FILE 250


int main()
{
    // line
    char line[LINE];
    // the word to find
    char word[WORD];
    // a/b
    char sign;

    // get the first word (cat)
    scanf("%s", word);
    scanf(" %c", &sign);

// clear spaces and new lines
    scanf("%c", line);
    scanf("%c", line);

    if (sign == 'a') {
        print_lines(word);
    } else if (sign == 'b') {
        print_similar_words(word);
    } else {
        printf("Unknown action\n");
    }

    return 0;
}

void getWord(char* buf) {

}