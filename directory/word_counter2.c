#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Bool { FALSE, TRUE };

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

enum CharType { ALPHABET, DIGIT, PUNCT, SPACE, OTHERS };
enum CharType GetCharType(char c);
int ExtractWord(char line[], int *pos, char word[]);

int main()
{
    FILE *fp = NULL;
    char file_name[MAX_LEN];
    char line[2048];
    char word[MAX_LEN];

    printf("Input filename: ");
    gets(file_name);

    fp = fopen(file_name, "r");

    int n = 0;
    while(fgets(line, 2048, fp) != NULL){
        int position = 0;
        while(ExtractWord(line, &position, word)){
            int idx = FindWord(my_lexicon, no_word, word);
            if(idx >= 0)
                my_lexicon[idx].count++;
            else
            {
                strcpy(my_lexicon[no_word].word, word);
                my_lexicon[no_word].count = 1;
                no_word++;
            }
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

enum CharType GetCharType(char c)
{
    if(isalpha(c))
        return ALPHABET;
    else if(isdigit(c))
        return DIGIT;
    else if(ispunct(c))
        return PUNCT;
    else if(isspace(c))
        return SPACE;
    
    return OTHERS;
}

int ExtractWord(char line[], int *pos, char word[])
{
    int i = 0;
    int start = 0;
    // skip space characters
    while(line[*pos] != 0 && isspace(line[*pos]))
        (*pos)++;

    // check if it's the end of string
    if(line[*pos] == 0){
        word[0] = 0;
        return FALSE;
    }

    start = *pos;
    enum CharType curType = GetCharType(line[start]);
    while(line[*pos] != 0 && GetCharType(line[*pos]) == curType) //끝이 아니고 타입이 같으면 계속 넘어감
        (*pos)++;

    for(i = start; i < *pos; i++) //그 넘어간 데까지 단어 복사
        word[i-start] = line[i];
    word[i - start] = 0;

    return TRUE;
}
