#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tNode
{
    int data;
    struct tNode *pNext;
}TNODE, *PTNODE, **PPTNODE;

int itr = 0;

int Display(PTNODE head_ref)
{
    itr = 0;
    while (head_ref != NULL)
    {
        ++itr;
        printf(" (%d)|%d|-|*next|-> ", itr, head_ref->data);
        head_ref = head_ref->pNext;
    }
    printf(" |null| \n");
    
    return(itr);
}

bool AppendLL(PPTNODE head_ref, int newData)
{
    PTNODE pNewn = (PTNODE)malloc(sizeof(TNODE));

    PTNODE temp = (*head_ref);

    pNewn->data = newData;
    pNewn->pNext = NULL;

    if((*head_ref) == NULL)
    {
        (*head_ref) = pNewn;
    }
    else
    {
        while(temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = pNewn;
    }


    return true;
}

bool AddAtFirst(PPTNODE head_ref, int iNewData)
{
    PTNODE pNewn = (PTNODE)malloc(sizeof(TNODE));
    if(pNewn == NULL || NULL == (*head_ref))
    {
        printf("\nFailed.\n");
        return false;
    }

    PTNODE temp = NULL;
    temp = (*head_ref);

    pNewn->data = iNewData;
    (*head_ref) = pNewn;

    (*head_ref)->pNext = temp;
    return true;
}

bool AddAtPos(PPTNODE head_ref, int iData, int iPos)
{
    PTNODE temp = (*head_ref);
    PTNODE newn = (PTNODE)malloc(sizeof(TNODE));
    newn->data = iData;
    newn->pNext = NULL;

    int i=1;
    while (temp != NULL)
    {
        if(i+1 == iPos)
        {
            printf("Now at pos %d data is-> %d\n\n", i, temp->data);
            break;
        }

        temp = temp->pNext;
        i++;
    }
    
    newn->pNext = temp->pNext;
    temp->pNext = newn;
    return true;
}

int main(void)
{
    PTNODE pHead = NULL;
   
    bool bRet = false;
    int i=0;

    bRet = AppendLL(&pHead, 10); 
    if(bRet == false)
    {
        printf("\nAppendLL failed.\n");
    }
    
    bRet = AppendLL(&pHead, 20); 
    if(bRet == false)
    {
        printf("\nAppendLL failed.\n");
    }
    
    bRet = AppendLL(&pHead, 30); 
    if(bRet == false)
    {
        printf("\nAppendLL failed.\n");
    }

    bRet = AddAtFirst(&pHead, 101); 
    if(bRet == false)
    {
        printf("\nddAtFirst failed.\n");
    }

    bRet = AddAtPos(&pHead, 77, 4); 
    if(bRet == false)
    {
        printf("\nddAtFirst failed.\n");
    }

    i = Display(pHead);
    printf("Total count: %d\n", i);

    return(0);
}

