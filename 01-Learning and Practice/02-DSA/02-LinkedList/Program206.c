#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *pNext;
} NODE, *PNODE, **PPNODE;

void Display(PNODE href)
{
    while (href != NULL)
    {
        printf("|%d| ", href->data);
        href = href->pNext;
    }
}

int Count(PNODE href)
{
    int iCount = 0;
    while (href != NULL)
    {
       iCount++;
       href = href->pNext;
    }
    return iCount;
}

void InsertLast(PPNODE href, int iData)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    PNODE temp = (*href);

    newn->data = iData;
    newn->pNext = NULL;

    if(*href == NULL)
    {
        *href = newn;
    }
    else
    {
        while (temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        
        temp->pNext = newn;
    }
}

void InsertFirst(PPNODE href, int iData)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = (*href);

    newn->data = iData;
    newn->pNext = NULL;

    if(*href == NULL)
    {
        *href = newn;
    }
    else
    {
        newn->pNext = temp;
        (*href) = newn;
    }
}

void DeleteFirst(PPNODE href)
{
    PNODE temp = (*href);
    if(temp != NULL)
    {
        temp = temp->pNext;
    }

    *href = temp;
}

void DeleteLast(PPNODE href)
{
    PNODE temp = (*href);
    if(temp != NULL)
    {
        while (temp->pNext->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = NULL;
    }
}

int main(void)
{
    PNODE head = NULL;
    InsertLast(&head, 10);
    InsertLast(&head, 20);
    InsertFirst(&head, 60);
    InsertLast(&head, 30);

    int i = Count(head);
    printf("\nCount of Nodes is: %d\n", i);
    Display(head);

    DeleteLast(&head);
    DeleteFirst(&head);

    int j = Count(head);
    printf("\nCount of Nodes is: %d\n", j);
    Display(head);

    return(0);
}
