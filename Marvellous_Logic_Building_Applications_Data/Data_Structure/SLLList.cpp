#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
    //PNODE First = NULL;
    struct node *Head=NULL; 

    Head=(PNODE)malloc(sizeof(struct node));


    return 0;
}
