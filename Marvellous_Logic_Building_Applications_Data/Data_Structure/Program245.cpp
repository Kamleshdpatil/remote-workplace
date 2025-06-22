#include<iostream>
using namespace std;

typedef struct node 
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head, int no)
{
	PNODE newn = new NODE;
	
	newn->data = no;
	newn->lchild = NULL;
	newn->rchild = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		PNODE temp= *Head;
		while(1)   //Unconditional loop
		{
			if(temp->data == no)
			{
				cout<<"Duplicate node\n";
				delete newn;
				break;
			}
			else if(no< (temp->data)) // lahan data
			{
				if(temp->lchild = NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp->lchild;
			}
			else if(no > (temp->data)) // motha data
			{
				if(temp->rchild = NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp->rchild;
			}
		}
	}
}

bool Search(PNODE Head, int no)
{
	bool flag=false;
	if(Head == NULL) // tree is emplty
	{
		return false;
	}
	else //atleast one node
	{
		while(Head != NULL)
		{
			if(Head->data == no )  // node sapdla
			{
				flag=true;
				break;
			}
			else if(no > (Head->data)) // motha data
			{
				Head = Head->rchild;
			}
			else if(no < (Head->data)) // lahan data
			{
				Head = Head->lchild;
			}
		}
		return flag;
	}
}

//data to be inserted: 51, 21, 101, 55, 75, 20, 105, 36
int main()
{
	PNODE first =NULL;
	int no=0;
	bool bRet=false;
	
	Insert(&first, 51);
	Insert(&first, 21);
	Insert(&first, 101);
	
	cout<<"Enter number to search: "<<"\n";
	cin>>no;
	
	bRet=Search(first, no);
	if(bRet==true)
	{
		cout<<"Data is there.\n";
	}
	else{
		cout<<"Data is not there.\n";
		
	}
	
	return 0;
}