#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum Bool { FALSE, TRUE };

#define MAX_LEN 64
#define MAX_WORD 10000

typedef struct {
    char word[MAX_LEN];
    int num[MAX_WORD];
} LexiconEntry;

int no_word = 0;

int FindWord(LexiconEntry lexicon[], int size, char word[]);
void DisplayLexicon(LexiconEntry lexicon[], int size);

enum CharType { ALPHABET, DIGIT, PUNCT, SPACE, OTHERS };
enum CharType GetCharType(char c);
int ExtractWord(char line[], int *pos, char word[]);

int main()
{
    FILE *fp = NULL;

    fp = fopen("words.txt","rt");

    int n =0;
    fscanf(fp,"%d",&n);
    LexiconEntry *myLex=NULL;

    myLex = (LexiconEntry*)malloc(sizeof(LexiconEntry *));
    

}