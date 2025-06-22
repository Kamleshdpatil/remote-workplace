#include<stdio.h>
#include<stdlib.h>

typedef int BOOL;

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
	int Occ=0;
	
	while(Head != NULL)
	{
		Occ++;
		if(Head->Data == no)
		{
			break;
		}
		Head=Head->Next;
	}
	return Occ;	
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("%d\t",Head->Data);
        Head = Head -> Next;
    }
}

int main()
{
	PNODE First = NULL;
	int iRet=0;
	InsertFirst(&First, 70);
	InsertFirst(&First, 60);
	InsertFirst(&First, 50);
	InsertFirst(&First, 40);
	InsertFirst(&First, 30);
	InsertFirst(&First, 20);
	InsertFirst(&First, 10);
	
	// Call all functions for below problem statements
	iRet=SearchFirstOcc(First,60);
	Display(First);
	printf("\nPosition at which element is: %d", iRet);
	
	return 0;	
}