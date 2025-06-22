#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE, **PPNODE;

int main(void)
{
    PNODE First = NULL;
    NODE *Head = NULL;

    Head = (PNODE)malloc(sizeof(NODE));

    PNODE newn = NULL;

    // Step 1 allocate the memory
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = 10;
    newn->next = NULL;

    printf("Size of Head: %d",sizeof(Head)); 
    printf("\nSize of First: %d",sizeof(First));
    printf("\n Size of data: %d",sizeof(First->data));
    printf("\n Size of next: %d",sizeof(First->next));
    printf("\n Size of newn: %d",sizeof(newn));

    Head->data=10;
    printf("\nData %d",Head->data);

    return(0);
}
