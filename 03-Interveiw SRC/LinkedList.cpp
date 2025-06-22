#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node
{
  int data;
  struct node* pNext; 
}NODE, *PNODE, **PPNODE;

int LLSize(PNODE headRef)
{
    int iCount = 0;
    if(headRef == NULL)
    {
        cout<<"List is empty"<<endl;
        return(0);
    }
    
    while (headRef != NULL) 
    {
        iCount++;
        headRef = headRef->pNext;
    }
    
    return(iCount);
}

void InsertAtFirst(PPNODE headRef, int data)
{
    PNODE newNode = (PNODE)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->pNext = NULL;
    
    if(*headRef == NULL)
    {
        *headRef = newNode; 
    }
    else 
    {
        PNODE temp = *headRef;
        newNode->pNext = temp;
        *headRef = newNode;    
    }
}

int main(void)
{
    
    /*PNODE head = (PNODE)malloc(sizeof(NODE));
    head->data = 10;
    head->pNext = NULL;*/
    PNODE head = nullptr;
    
    InsertAtFirst(&head, 70);
    
    cout<<"Size of list: "<<LLSize(head);
    
    return(0);
}

