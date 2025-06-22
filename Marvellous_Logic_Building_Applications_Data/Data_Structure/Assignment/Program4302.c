#include<stdio.h>
#include<stdlib.h>

struct node
{
	int Data;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void InsertFirst(PPNODE Head, int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->Next=NULL;
	newn->Data= no;
	
	if(*Head == NULL)
	{
	 *Head = newn;
	}
	else
	{
	 newn -> Next = *Head;
	 *Head = newn;
	}
}

int SearchFirstOcc(PNODE Head, int no)
{
	int fOcc=0;
	
	while(Head != NULL)
	{
		fOcc++;
		if(Head->Data == no)
		{
			break;
		}
		Head=Head->Next;
	}
	return fOcc;	
}

int SearchLastOcc(PNODE Head, int no)
{
	int Occ=0, index=0;
	
	while(Head != NULL)
	{
		Occ++;
		if(Head->Data == no)
		{
			index=Occ;
		}
		Head=Head->Next;
	}
	return index;	
}

int Addition(PNODE Head)
{
	int sum=0;
	
	while(Head != NULL)
	{
		sum=((Head->Data) + sum);
		Head= Head->Next;
	}
	return sum;
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("%d\t",Head->Data);
        Head = Head -> Next;
    }
}

int Maximum(PNODE Head)
{
	PNODE max;
	max = Head;
	while(Head != NULL)
    {
        if(Head->Data > max->Data)
        {
        	max =Head;
		}
        Head = Head -> Next;
    }
    
    return max->Data;
}

int Minimum(PNODE Head)
{
	PNODE min;
	min = Head;
	while(Head != NULL)
    {
        if(Head->Data < min->Data)
        {
        	min = Head;
		}
        Head = Head -> Next;
    }
    
    return min->Data;
}

int main()
{
	PNODE First = NULL;
	int iRet=0;
	
	InsertFirst(&First, 30);
	InsertFirst(&First, 5);
	
	InsertFirst(&First, 70);
	InsertFirst(&First, 30);
	InsertFirst(&First, 50);
	InsertFirst(&First, 40);
	InsertFirst(&First, 30);
	InsertFirst(&First, 10);
	InsertFirst(&First, 10);
	
	// Call all functions for below problem statements
	//iRet=SearchFirstOcc(First,60);
	Display(First);
	//iRet=SearchLastOcc(First,30);
	//iRet=Addition(First);
    //printf("\nPosition at which element is: %d", iRet);
	//printf("\nAddition of All Node: %d", iRet);
	
	//iRet=Maximum(First);
	// printf("\nMaximum element is: %d", iRet);
	
	iRet=Minimum(First);
    printf("\nMinimum element is: %d", iRet);
	
	return 0;	
}