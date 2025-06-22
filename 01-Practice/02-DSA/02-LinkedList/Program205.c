#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **  PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    //Step 1: Allocate the memory
    newn = (PNODE)malloc(sizeof(NODE));

    //Step 2: Initialise the node
    newn->data = no;
    newn->next = NULL;

    //Step 3: Insert the node
    if(*Head == NULL)   //LL is empty
    {
        *Head = newn;
    }
    else            //LL contains atleast one node
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    //Step 1 : Allocate the memory
    newn = (PNODE)malloc(sizeof(NODE));

    //Step 2 : Initialise the node 
    newn->data = no;
    newn->next = NULL;

    //Step 3 : Insert the node
    if(*Head == NULL) //LL is empty
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(PNODE head_ref)
{
    int i = 0;
    while(head_ref != NULL)
    {
        i++;
        printf("|%d| - |%d|\n",i, head_ref->data);
        head_ref = head_ref->next;
    }
}

int count(PNODE head_ref)
{
    int itr=0;
    while(head_ref != NULL)
    {
        itr++;
        head_ref = head_ref->next;
    }
    return itr;
}

int main(void)
{
    PNODE head = NULL;

    InsertFirst(&head, 10);
    InsertFirst(&head, 20);
    InsertFirst(&head, 30);
    InsertLast(&head, 40);

    int iCnt = count(head);
    printf("Total node is: %d\n", iCnt);

    Display(head);

    return(0);
}