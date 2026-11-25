#include<stdio.h>
#include<malloc.h>

//
// Structure decleration
// 

struct List
{
    struct List* pPrev;
    int iData;
    struct List* pNext;
};

//
// Function Prototypes
//

// Insertion
void InsertLast(struct List **ppHead, struct List **ppTail, int iNo);
void InsertFirst(struct List **ppHead, struct List **ppTail, int iNo);
void InsertAtPosition(struct List **ppHead, struct List **ppTail, int iNo, int iPos);

// Deletion
int DeleteLast(struct List **ppHead, struct List **ppTail);
int DeleteFirst(struct List **ppHead, struct List **ppTail);
void DeleteAllNodes(struct List **ppHead, struct List **ppTail);
int DeleteAtPosition(struct List **ppHead, struct List **ppTail, int iPos);

// Searching
int SearchFirstOccurance(struct List *pHead, struct List *pTail, int iKey);
int SearchLastOccurance(struct List *pHead, struct List *pTail, int iKey);
int SearchAllOccurance(struct List *pHead, struct List *pTail, int iKey);

// Display & Counting
void Display(struct List *pHead, struct List *pTail);
void ReverseDisplay(struct List *pHead, struct List *pTail);
int CountNodes(struct List *pHead, struct List *pTail);

//
// Function Definations
//
int main()
{
    int iNo;
    int iPos;
    int iChoice;

    struct List *pFirst = NULL;
    struct List *pLast  = NULL;

    while(1)
    {
        printf("\n1. Insert \n2. Delete \n3. Search \n4. Count \n5. Reverse & Display \n6. Exit\n");
        printf("Enter your choice:\t");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
                while(1)
                {
                    printf("\n1. InsertFirst \n2. InsertLast \n3. InsertAtPosition \n4. Back\n");
                    printf("Enter your choice again:\t");
                    scanf("%d", &iChoice);

                    if(iChoice == 4) break;

                    if(iChoice <= 0 || iChoice > 3)
                    {
                        printf("Enter valid choice\n");
                        continue;
                    }

                    printf("Enter data to be insert: \t");
                    scanf("%d", &iNo);

                    switch(iChoice)
                    {
                        case 1:
                            InsertFirst(&pFirst, &pLast, iNo);
                            break;
                        case 2:
                            InsertLast(&pFirst, &pLast, iNo);
                            break;
                        case 3:
                            printf("Enter position: \t");
                            scanf("%d", &iPos);
                            InsertAtPosition(&pFirst, &pLast, iNo, iPos);
                            break;
                    }
                    Display(pFirst, pLast);
                }
                break;
            case 2:
                if(pFirst == NULL)
                {
                    printf("Linked List Empty, Deletion impossible.\n");
                    break;
                }

                while(1)
                {
                    printf("\n1. DeleteFirst \n2. DeleteLast \n3. DeleteAtPosition \n4. Back\n");
                    printf("Enter your choice again:\t");
                    scanf("%d", &iChoice);

                    if(iChoice == 4) break;

                    switch(iChoice)
                    {
                        case 1:
                            iNo = DeleteFirst(&pFirst, &pLast);
                            break;
                        case 2:
                            iNo = DeleteLast(&pFirst, &pLast);
                            break;
                        case 3:
                            printf("Enter position: \t");
                            scanf("%d", &iPos);
                            iNo = DeleteAtPosition(&pFirst, &pLast, iPos);
                            break;
                        default:
                            printf("Enter valid choice\n");
                            iChoice = 4; //For checking outside for deleted data printing & display
                    }
                    if(iNo == -1)
                    {
                        printf("Linked List Empty\n");
                    }
                    else if(iChoice != 4 && iNo != -2)
                    {
                        printf("Deleted data: %d\n", iNo);
                        Display(pFirst, pLast);
                    }
                }
                break;
            case 3:
                if(pFirst == NULL)
                {
                    printf("Linked List Empty, Searching impossible.\n");
                    break;
                }

                while(1)
                {
                    printf("\n1. SearchFirstOccurance \n2. SearchLastOccurance \n3. SearchAllOccurance \n4. Back\n");
                    printf("Enter your choice again:\t");
                    scanf("%d", &iChoice);

                    if(iChoice == 4) break;

                    if(iChoice <= 0 || iChoice > 3)
                    {
                        printf("Enter valid choice\n");
                        continue;
                    }

                    Display(pFirst, pLast);

                    printf("Enter data to be search: \t");
                    scanf("%d", &iNo);

                    switch(iChoice)
                    {
                        case 1:
                            iNo = SearchFirstOccurance(pFirst, pLast, iNo);
                            if(iNo == -1)
                            {
                                printf("Linked List Empty\n");
                            }else if(iNo == -2)
                            {
                                printf("Data Not found\n");
                            }else
                            {
                                printf("Data Not found at %d position\n", iNo);
                            }
                            break;
                        case 2:
                            iNo = SearchLastOccurance(pFirst, pLast, iNo);
                            if(iNo == -1)
                            {
                                printf("Linked List Empty\n");
                            }else if(iNo == -2)
                            {
                                printf("Data Not found\n");
                            }else
                            {
                                printf("Data Not found at %d position\n", iNo);
                            }
                            break;
                        case 3:
                            iNo = SearchAllOccurance(pFirst, pLast, iNo);
                            printf("Data found %d times\n", iNo);
                            break;
                    }
                }
                break;
            case 4:
                Display(pFirst, pLast);
                iNo = CountNodes(pFirst, pLast);
                printf("Total Nodes present: %d\n", iNo);
                break;

            case 5:
                Display(pFirst, pLast);
                ReverseDisplay(pFirst, pLast);
                break;

            case 6:
                Display(pFirst, pLast);
                if(pFirst != NULL)
                    DeleteAllNodes(&pFirst, &pLast);
                
                printf("Bye...\n");
                return(0);

            default:
                printf("Enter valid choice.\n");
        }

    }

    return(0);
}

// Insertion
void InsertLast(struct List **ppHead, struct List **ppTail, int iNo)
{
    struct List* pNewNode = NULL;
    pNewNode = (struct List*)malloc(sizeof(struct List));
    if(pNewNode == NULL)
    {
        printf("memory allocation FAILED\n");
        return;
    }

    pNewNode->iData = iNo;

    if(*ppHead == NULL) // if list initially empty
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;

        (*ppTail)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppTail;

        return;
    }

    (*ppTail)->pNext = pNewNode;
    pNewNode->pPrev = *ppTail;

    *ppTail = pNewNode;
    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev = *ppTail;
}


void InsertFirst(struct List **ppHead, struct List **ppTail, int iNo)
{
    struct List* pNewNode = NULL;
    pNewNode = (struct List*)malloc(sizeof(struct List));
    if(pNewNode == NULL)
    {
        printf("memory allocation FAILED\n");
        return;
    }

    pNewNode->iData = iNo;

    if(*ppHead == NULL) // if list initially empty
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;

        (*ppTail)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppTail;

        return;
    }

    pNewNode->pNext = *ppHead;
    (*ppHead)->pPrev = pNewNode;

    *ppHead = pNewNode;
    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev = *ppTail;
}


void InsertAtPosition(struct List **ppHead, struct List **ppTail, int iNo, int iPos)
{
    struct List* pNewNode = NULL;
    struct List* pTemp = NULL;
    int iCount;

    iCount = CountNodes(*ppHead, *ppTail);
    if(iPos <= 0 || iPos > iCount +1)
    {
        printf("Position is invalid\n");
        return;
    }

    if(1 == iPos)   // first position
    {
        InsertFirst(ppHead, ppTail, iNo);
        return;
    }

    if(iCount + 1 == iPos)  // last position
    {
        InsertLast(ppHead, ppTail, iNo);
        return;
    }

    // Middle position
    pTemp = *ppHead;
    iCount = 1;

    while (iCount < iPos -1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }
    
    pNewNode = (struct List*)malloc(sizeof(struct List));
    if(pNewNode == NULL)
    {
        printf("memory allocation FAILED\n");
        return;
    }

    pNewNode->iData = iNo;

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
}

// Deletion
int DeleteLast(struct List **ppHead, struct List **ppTail)
{
    int iDelData;
    if(*ppHead == NULL)
        return -1;
    
    iDelData = (*ppTail)->iData;

    if(*ppHead == *ppTail)  // Only single node present
    {
        (*ppHead)->pNext = NULL;
        (*ppHead)->pPrev = NULL;

        free(*ppHead);

        *ppHead = NULL;
        *ppTail = NULL;

        return iDelData;
    }

    *ppTail = (*ppTail)->pPrev;
    (*ppHead)->pPrev->pNext = NULL;
    (*ppHead)->pPrev->pPrev = NULL;
    free((*ppHead)->pPrev);

    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev = *ppTail;

    return iDelData;
}


int DeleteFirst(struct List **ppHead, struct List **ppTail)
{
    int iDelData;
    if(*ppHead == NULL)
        return -1;
    
    iDelData = (*ppHead)->iData;

    if(*ppHead == *ppTail)  // Only single node present
    {
        (*ppHead)->pNext = NULL;
        (*ppHead)->pPrev = NULL;

        free(*ppHead);

        *ppHead = NULL;
        *ppTail = NULL;

        return iDelData;
    }

    *ppHead = (*ppHead)->pNext;
    (*ppTail)->pNext->pNext = NULL;
    (*ppTail)->pNext->pPrev = NULL;
    free((*ppTail)->pNext);

    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev = *ppTail;

    return iDelData;
}


void DeleteAllNodes(struct List **ppHead, struct List **ppTail)
{
    if(*ppHead == NULL)
        return;
    
    while(*ppHead != *ppTail)   // till single node present
    {
        (*ppHead)->pPrev = NULL;
        *ppHead = (*ppHead)->pNext;
        (*ppTail)->pNext->pNext = NULL;

        free((*ppTail)->pNext);

        (*ppTail)->pNext = *ppHead;
    }

    (*ppHead)->pNext = NULL;
    (*ppHead)->pPrev = NULL;

    free(*ppHead);

    *ppHead = NULL;
    *ppTail = NULL;

    printf("\nDeleted All Nodes Successfully\n");
}


int DeleteAtPosition(struct List **ppHead, struct List **ppTail, int iPos)
{
    struct List* pTemp = NULL;
    int iCount;

    iCount = CountNodes(*ppHead, *ppTail);
    if(iPos <= 0 || iPos > iCount +1)
    {
        printf("Position is invalid\n");
        return -2;
    }

    if(1 == iPos)   // first position
    {
        return DeleteFirst(ppHead, ppTail);
    }

    if(iCount == iPos)  // last position
    {
        return DeleteLast(ppHead, ppTail);
    }

    // Middle position
    pTemp = *ppHead;
    iCount = 1;

    while (iCount < iPos)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }

    pTemp->pPrev->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = pTemp->pPrev;
    pTemp->pPrev = NULL;
    pTemp->pNext = NULL;

    iCount = pTemp->iData;
    free(pTemp);

    return iCount;
}


// Searching
int SearchFirstOccurance(struct List *pHead, struct List *pTail, int iKey)
{
    int iPos;

    if(pHead == NULL)
        return -1;
    
    iPos = 1;

    do
    {
        if(pHead->iData == iKey)
            break;
        iPos++;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);
    
    if(pHead == pTail->pNext && iPos != 1)  // Not found
        return -2;
    return iPos;
}


int SearchLastOccurance(struct List *pHead, struct List *pTail, int iKey)
{
    int iPos;
    int iLast;

    if(pHead == NULL)
        return -1;
    
    iPos = 1;
    iLast = 0;

    do
    {
        if(pHead->iData == iKey)
            iLast = iPos;
        iPos++;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);
    
    if(iLast == 0)  // not found
        return -2;

    return iLast;
}


int SearchAllOccurance(struct List *pHead, struct List *pTail, int iKey)
{
    int iCount = 0;

    if(pHead == NULL)
        return iCount;
    
    do
    {
        if(pHead->iData == iKey)
            iCount++;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iCount;
}


// Display & Counting
void Display(struct List *pHead, struct List *pTail)
{
    printf("\nLinked List is: ");
    if(pHead == NULL)
    {
        printf("\nEMPTY !!\n");
        return;   
    }
    
    do
    {
        printf("<--|%d|-->", pHead->iData);
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);
    printf("\n");
}


void ReverseDisplay(struct List *pHead, struct List *pTail)
{
    printf("\nLinked List is: ");
    if(pTail == NULL)
    {
        printf("\nEMPTY !!\n");
        return;   
    }
    
    do
    {
        printf("<--|%d|-->", pTail->iData);
        pTail = pTail->pPrev;
    } while (pTail != pHead->pPrev);
    printf("\n");
}


int CountNodes(struct List *pHead, struct List *pTail)
{
    int iCount = 0;

    if(pHead == NULL)
        return iCount;
    
    do
    {
        iCount++;
        pHead = pHead->pNext;
    } while (pHead != pTail->pNext);

    return iCount;
}
