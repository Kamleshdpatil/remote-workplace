#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}NODE, *PNODE;

PNODE root=NULL;
int len;

void Append(void);
int Length(void);

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

void AddAtAfter()
{
	PNODE temp, p;
	int i, loc;
	
	printf("Enter Location: ");
	scanf("%d",&loc);
	len=Length();
	
	if(loc > len)
	{
		printf("Imvalid location..!!\n");
		printf("List Having %d elements in List.\n\n", len);
	}
	else
	{
		p=root;
		
		while(i < loc)
		{
			p=p->link;
			i++;
		}
		temp=(PNODE)malloc(sizeof(NODE));
		printf("Enter Node Data: ");
		scanf("%d", &temp->data);
		temp->link=NULL; // temp link NULL
		temp->link=p->link; // right side connection
		p->link=temp;     // left side connection
	}
}

int Length()
{
	int Count=0;
	PNODE temp=NULL;
	temp=root;
	
	while(temp != NULL)
	{
		Count++;
		temp= temp->link;
	}
	return Count;		
}

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
	        printf("|%d|->",temp->data);
	        temp = temp -> link;
	    }
    	printf("|NULL|\n");
	}
}
void Delete()
{
	PNODE temp;
	PNODE p, q;
	int loc, i=0;
	
	printf("Enter the location to Delete: ");
	scanf("%d", &loc);
	
	if(loc>Length())
	{
		printf("Invalid Location..!!\n");
	}
	else if(loc==1)
	{
		temp= root;
		root = temp->link;
		temp->link= NULL;
		free(temp);
	}
	else
	{
		p=root;
		while(i < loc-1)
		{
			p=p->link;
			i++;
		}
		q= p->link;
		p->link= q->link;
		q->link=NULL;
		free(q);
	}
}

int main()
{
	int ch=0;
	while(1)
	{
		printf("\n");
		printf("-----------------------------Single Linked list Operatons-----------------------------\n");
		printf("1. Append\n");
		printf("2. AddAtBegin\n");
		printf("3. AddAtAfter\n");
		printf("4. Length\n");
		printf("5. Display\n");
		printf("6. Delete\n");
		printf("7. Quit\n");
		printf("-----------------------------Single Linked list Operatons-----------------------------\n");
		printf("\n");
		
		printf("Enter Your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: Append();
					break;
			case 2: AddAtBegin();
					break;
			case 3: AddAtAfter();
					break;
			case 4: len=Length();
    				printf("Lenght of list is: %d\n", len);
					break;
			case 5: Display(root);
					break;
			case 6: Delete();
					break;
			case 7: exit(1);
			default: printf("Invalid input..!!\n\n");
		}
	}
	
	return 0;
}