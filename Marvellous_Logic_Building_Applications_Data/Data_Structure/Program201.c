#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;          //4
    struct node *next; //8
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
    PNODE First = NULL;
    struct node *Head=NULL; 

    Head=(struct node*)malloc(sizeof(struct node));

    PNODE newn = NULL;
    
    // Step 1 : Allocate the memory
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = 10;
    newn->next = NULL;

    printf("Size of Head: %d",sizeof(Head)); 
    printf("\nSize of First: %d",sizeof(First));
    printf("\n Size of data: %d",sizeof(First->data));
    printf("\n Size of next: %d",sizeof(First->next));
    printf("\n Size of newn: %d",sizeof(newn));

    // Head->data=10;
    // printf("Data %d",Head->data);

    return(0);
}
