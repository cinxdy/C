#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct tPerson {
    char name[64];
    char date_of_birth[16];
    struct tPerson *next;
} Person;

void DisplayByIndex(Person list[], int n);
void DisplayByAge(Person *head);

int main()
{
    Person avengers[3] = {
        { "Tony Stark", "19700529", NULL},
        { "Steven Rogers", "19180704", NULL },
        { "Natasha Romanova", "19841122", NULL }
    };
    Person *head = NULL;


    // List all members
    DisplayByIndex(avengers, 3);


    // Connect members by age in ascending order
    head = &avengers[2];
    avengers[2].next = &avengers[0];
    avengers[0].next = &avengers[1];

  // List all members
    printf("head = %p\n", head);
    DisplayByIndex(avengers, 3);

    // List avengers following links
    DisplayByAge(head);

    Person *new_node = (Person*)malloc(sizeof(Person));
    strcpy(new_node->name, "Scarlet Witch");
    strcpy(new_node->date_of_birth, "19991203");

    new_node->next = head;
    head = new_node;

    // List avengers following links
    printf("Scarlet Witch added\n");
    DisplayByAge(head);

    return 0;
}


void DisplayByIndex(Person list[], int n)
{
    int i = 0;

    for(i = 0; i < n; i++)
        printf("(%p)%-24s %s next = %p\n", &list[i], list[i].name, list[i].date_of_birth, list[i].next);
}

void DisplayByAge(Person *head)
{
    Person *p = head;

    while(p != NULL){
        printf("name = %s, date of birth = %s\n", p->name, p->date_of_birth);
        p = p->next;
    }
}