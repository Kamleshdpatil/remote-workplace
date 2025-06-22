#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *pNext;
}NODE, *PNODE, **PPNODE;

void Display(PPNODE head_ref)
{
    PNODE pNewn = NULL;
    pNewn = (PNODE)malloc(sizeof(NODE));

    pNewn = (*head_ref);

    printf("Head node data\n");
    printf("Head node data: %d\n", (*head_ref)->data);
    printf("New node data\n");
    printf("New node data: %d\n", pNewn->data);
}


int main(void)
{
    PNODE pNode = NULL;

    pNode = (PNODE)malloc(sizeof(NODE));

    pNode->data = 10;
    pNode->pNext = 0;

    Display(&pNode);

    return(0);
}
