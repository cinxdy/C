#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 64
#define MAX_WORD 1000
char words[MAX_WORD][MAX_LEN];
int no_word=0;

void ConcatenateWords(char words[][MAX_LEN],int no_word,char text[]);
void RetrieveWords(char text[],char words[][MAX_LEN],int *no_word);
void ShuffleString(char words[][MAX_LEN],int n);

int main(){
    char text1[2048];
    char text2[2048];
    int i=0;

    srand(time(NULL));

    printf("Input a text line: ");
    gets(text1);

    RetrieveWords(text1,words,&no_word);
    ShuffleString(words,no_word);
    ConcatenateWords(words,no_word,text2);

    printf("shuffled text = [%s]\n",text2);

    return 0;
    
}

void ConcatenateWords(char words[][MAX_LEN],int no_word,char text[]){
    int i=0;

    text[0]=0;
    for(i=0;i<no_word;i++){
        strcat(text,words[i]);
        strcat(text," ");
    }
}

void RetrieveWords(char text[],char words[][MAX_LEN],int *no_word){
    int i = 0;
    int start = 0;
    int pos =0;

    while(text[pos]!=0){
        // skip space characters
        while(text[pos] != 0 && isspace(text[pos]))
            pos++;

        //단어 복사
        start = pos;
        while(text[pos] != 0 && !isspace(text[pos])) //끝이 아니고 타입이 같으면 계속 넘어감
            pos++;

        for(i = start; i < pos; i++) //그 넘어간 데까지 단어 복사
            words[*no_word][i-start] = text[i];
        words[*no_word][i - start] = 0;

        (*no_word)++;
    }

}


void ShuffleString(char words[][MAX_LEN],int n){
    char temp[MAX_LEN]={0};
    int x=0;
    int i=0;

    for(int i=0;i<n;i++){
        x=rand()%n;
        
        if(i!=x){
            strcpy(temp,words[i]);
            strcpy(words[i],words[x]);
            strcpy(words[x],temp);
        }
        
    }
}