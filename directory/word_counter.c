#include <stdio.h>
#include <string.h>

#define MAX_LEN 64
#define MAX_WORD 10000

typedef struct {
    char word[MAX_LEN];
    int count;
} LexiconEntry;

LexiconEntry my_lexicon[MAX_WORD];
int no_word = 0;

int FindWord(LexiconEntry lexicon[], int size, char word[]);
void DisplayLexicon(LexiconEntry lexicon[], int size);

int main()
{
    FILE *fp = NULL;
    char file_name[MAX_LEN];
    char word[MAX_LEN];

    printf("Input filename: ");
    gets(file_name);

    fp = fopen(file_name, "r");

    int n = 0;
    while(fscanf(fp, "%s", word) != EOF){
        int idx = FindWord(my_lexicon, no_word, word);
        if(idx >= 0)
            my_lexicon[idx].count++;
        else{
            strcpy(my_lexicon[no_word].word, word);
            my_lexicon[no_word].count = 1;
            no_word++;
        }
    }
    fclose(fp);

    DisplayLexicon(my_lexicon, no_word);

    return 0;
}

int FindWord(LexiconEntry lexicon[], int size, char word[])
{
    int i = 0;
    for(i = 0; i < size; i++){
        if(strcmp(lexicon[i].word, word) == 0)
            return i;
    }

    return -1;
}

void DisplayLexicon(LexiconEntry lexicon[], int size)
{
    int i = 0;
    printf("totally, %d words\n", size);
    for(i = 0; i < size; i++){
        printf("lexicon[%d] = [%s], (%d)\n", i, lexicon[i].word, lexicon[i].count);
    }
}
