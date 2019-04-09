#include <stdio.h>
#include <stdlib.h>

typedef struct tPerson {
    char name[64];
    char date_of_birth[16];
    struct tPerson *next; //pointer
} Person;

void LinkingInAscending(Person *head, Person list[], int n);
void DisplayByAge(Person *head);
void DisplayByIndex(Person list[], int n);

int main(){
    Person avengers[3] = {
        { "Tony Stark", "19700529", NULL},
        { "Steven Rogers", "19180704", NULL },
        { "Natasha Romanova", "19841122", NULL }
    };
    Person *head = NULL;

    // List all members
    //DisplayByIndex(avengers, 3);

    // Connect members by age in ascending order
    LinkingInAscending(head,avengers,3);

    // List avengers following links
    DisplayByAge(head);

    return 0;
}


void LinkingInAscending(Person *head, Person list[], int n){
    int* index[n]={0};

    //Sorting in Ascending Order //Make Index
    for(int current=0;current< n;current++){
        int minimum = 0;
        int walk=0;

        //make minimum
        minimum = current;
        for(walk=current;walk<n;walk++){
            if(list[minimum].date_of_birth > list[walk].date_of_birth ){ //&& walk!=index[current-1]
                minimum = walk;
            }
        }
        
        index[current] = minimum;
    }

    printf("%d")
    
    //Linking as index
    head = &list[index[0]];
    for(int i=0;i<n-1;i++){
        list[index[i]].next = &list[index[i+1]];
    }

    printf("Success to Link!\n\n");
}

void DisplayByIndex(Person list[], int n){
    int i = 0;

    for(i = 0; i < n; i++)
        printf("%p -> %-24s %s next -> %p\n", &list[i], list[i].name, list[i].date_of_birth,list[i].next);

        
    printf("Success to Display By Index!\n\n");
}

void DisplayByAge(Person *head){
    Person *p = head;
    while(p!=NULL){
        printf("name = %s, date of birth = %s\n",p->name,p->date_of_birth);
        p = p->next;
    }

    printf("Success to Display By Age!\n\n");
}