#include<stdio.h>
#include<stdlib.h>

typedef struct tagNode
{
    int ID;
    float Salary;
    char Name[20];
    char Address[50];
    struct tagNode* pNext;
} NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head_ref, NODE nData)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {   
        printf("Malloc Failed. exit");
        return;
    }

    newn->ID = nData.ID;
    newn->Salary= nData.Salary;
    strcpy(newn->Name, nData.Name);
    strcpy(newn->Address, nData.Address);
    newn->pNext = NULL;

    if(*Head_ref == NULL)
    {
        *Head_ref = newn;
    }
    else
    {
        newn->pNext = *Head_ref;
        *Head_ref = newn;
    }
}

void Display(PNODE Head_ref)
{
    if(Head_ref == NULL)
    {
        printf("\nLinked list is empty !!\n\n");
        return;
    }

    while (Head_ref != NULL)
    {
        printf("Empleyee ID:        %d\n", Head_ref->ID);
        printf("Empleyee Name:      %s\n", Head_ref->Name);
        printf("Empleyee Salary:    %.2f\n", Head_ref->Salary);
        printf("Empleyee Address:   %s\n\n", Head_ref->Address);
        Head_ref = Head_ref->pNext;
    }
}

void InsertLast(PPNODE Head_ref, NODE nData)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {   
        printf("Malloc Failed. exit");
        return;
    }

    newn->ID = nData.ID;
    newn->Salary= nData.Salary;
    strcpy(newn->Name, nData.Name);
    strcpy(newn->Address, nData.Address);
    newn->pNext = NULL;

    if(*Head_ref == NULL)
    {
        *Head_ref = newn;
    }
    else
    {
        PNODE Temp = *Head_ref;
        while (Temp->pNext != NULL)
        {
            Temp = Temp->pNext;
        }
        Temp->pNext = newn;
    }
}

void InsertAtPos(PPNODE Hed_ref, NODE nData, int iPos)
{
    int GetLLCount(PNODE);
    void InsertFirst(PPNODE, NODE);
    void InsertLast(PPNODE, NODE);

    int size = GetLLCount(*Hed_ref);
    printf("\nCurrent size of LL is: %d\n", size);
    printf("\nCurrent iPos is: %d\n", iPos);
    if((iPos < 1) || (iPos > size+1))
    {
        printf("Invalid Position\n");
		return;
    }

    if(iPos == 1)
    {
        InsertFirst(Hed_ref, nData);
        //return;
    }
    else if(iPos == size + 1)
    {
        InsertLast(Hed_ref, nData);
        //return;
    }
    else
    {
        int iCount = 0;
        // 1) Create new node
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        // 2) Insert Data

        newn->ID = nData.ID;
        newn->Salary= nData.Salary;
        strcpy(newn->Name, nData.Name);
        strcpy(newn->Address, nData.Address);
        newn->pNext = NULL;

        if(*Hed_ref == NULL)
        {
            *Hed_ref = newn;
        }
        else
        {
            PNODE Temp = *Hed_ref;  // 1
            while (Temp->pNext != NULL) // 2
            {
                iCount++; // 3
                if(iCount == iPos-1)
                {
                    break;
                }
                Temp = Temp->pNext;
            }
            newn->pNext = Temp->pNext; // 4
            Temp->pNext = newn; // 5
        }
    }
}

void DeleteFirst(PPNODE Head_ref)
{
    PNODE Temp = *Head_ref;
    if(Temp == NULL)
    {
        printf("\nHead_ref is NULL!!\n");
        return;
    }
    else if(Temp->pNext == NULL)
    {
        free(*Head_ref);
        *Head_ref = NULL;
        return;
    }
    else
    {
        Temp = Temp->pNext;
        *Head_ref = Temp;
    }
}

void DeleteLast(PPNODE Head_ref)
{
    PNODE Temp = *Head_ref;
    if(Temp == NULL)
    {
        printf("\nHead_ref is NULL!!\n");
        return;
    }
    else if(Temp->pNext == NULL)
    {
        free(*Head_ref);
        *Head_ref = NULL;
        return;
    }
    else
    {
        while (Temp->pNext->pNext != NULL)
        {
            Temp = Temp->pNext;
        }
        Temp->pNext = NULL;
    }
}

void DeleteAtPos(PPNODE Head_ref, int iPos)
{
    int GetLLCount(PNODE);
    void DeleteFirst(PPNODE);
    void DeleteLast(PPNODE);

    PNODE Temp = *Head_ref;
    int iCount = 0;
    int size = GetLLCount(*Head_ref);
    printf("\nCurrent size of LL is: %d\n", size);
    printf("\nCurrent iPos is: %d\n", iPos);
    if((iPos < 1) || (iPos > size))
    {
        printf("\nInvalid position!!\n\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head_ref);
        return;
    }

    if(iPos == size)
    {
        DeleteLast(Head_ref);
    }
    else
    {
        while (Temp->pNext != NULL)
        {
            iCount++;
            if(iCount == iPos-1)
            {
                break;
            }
            Temp = Temp->pNext;
        }

        Temp->pNext = Temp->pNext->pNext;
    }

}

int GetLLCount(PNODE Head_ref)
{ 
    int count = 0; 
    while (Head_ref != NULL)
    {
        count++;
        Head_ref = Head_ref->pNext;
    }
    return(count);
}

int main(void)
{
    PNODE Head = NULL;

    int count = 0;
    
    NODE nData1 = {442, 39898.45f, "Kamlesh", "Pune"};

    InsertFirst(&Head, nData1);

    NODE nData2 = {447, 39898.45f, "Gouri", "Pune"};

    InsertFirst(&Head, nData2);

    NODE nData4 = {457, 50898.45f, "Shivam", "Pune"};

    InsertFirst(&Head, nData4);

    NODE nData3 = {448, 39898.45f, "Jeswin", "Pune"};

    InsertLast(&Head, nData3);

    NODE nData5 = {457, 70898.45f, "Akash", "Pune"};

    InsertAtPos(&Head, nData5, 5);

    count = GetLLCount(Head);
    printf("\nBefore delete. count of node is: %d\n", count);
    Display(Head);

    // DeleteFirst(&Head);
    // DeleteLast(&Head);

    DeleteAtPos(&Head, 5);

    printf("\nAfter delete.\n");

    count = GetLLCount(Head);

    printf("\nCurrent count of node is: %d\n", count);

    Display(Head);

    
    if(Head)
    {
        free(Head);
        Head = NULL;
    }
    
    return(0);
}
