#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node 
{
	int data;
	struct node* link;
};

typedef struct node NODE;
typedef struct node* PNODE;

struct node* root=NULL;

void Display(PNODE temp)
{
    if(temp==NULL)
	{
		printf("List is Empty..!!\n");
	}
	else
	{
	    while (temp != NULL)
	    {
	        printf("|%d| -> ",temp->data);
	        temp = temp -> link;
	    }
    	printf("NULL\n");
	}
}

int Length(PNODE temp)
{
	int Count=0;
	temp=root;
	
	while(temp != NULL)
	{
		Count++;
		temp= temp->link;
	}
	return Count;
}

void AddAtBegin()
{
	PNODE temp;
	temp=(PNODE)malloc(sizeof(NODE));
	
	printf("Enter Node Data: ");
	scanf("%d", &temp->data);
	
	temp->link=NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}

void Append()
{
	PNODE temp=NULL;
	
	temp=(PNODE)malloc(sizeof(NODE));
	
	printf("Enter the element: ");
	scanf("%d", &temp->data);
	
	temp->link=NULL;
	
	if(root == NULL)
	{
		root= temp;
	}
	else
	{
		PNODE p;
		p=root;
		
		while(p->link!=NULL)
		{
			p= p->link;
		}
		p->link= temp;
	}
}

int main()
{
	struct node data;
	int iCnt=0;
	Append();
	Append();
	Append();
	printf("Elemenet of Linked list are\n");
    Display(root);
    
    AddAtBegin();
    
    Display(root);
    iCnt=Length(root);
    printf("Lenght of list is: %d\n", iCnt);
	return 0;
}
