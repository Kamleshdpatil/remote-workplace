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
		if(Head == NULL)
		{
			return false;
		}
		
	}
}

int Count(PNODE Head)
{
	static int iCnt=0;
	
	if(Head != NULL)
	{
		iCnt++;
		Count(Head->lchild);
		Count(Head->rchild);
	}
	return iCnt;
}

int CountLeaf(PNODE Head)
{
	static int iCnt=0;
	
	if(Head != NULL)
	{
		if((Head->lchild == NULL) && (Head->rchild == NULL))
		{
			iCnt++;	
		}
		
		CountLeaf(Head->lchild);
		CountLeaf(Head->rchild);
	}
	return iCnt;
}

int CountParent(PNODE Head)
{
	static int iCnt=0;
	
	if(Head != NULL)
	{
		if((Head->lchild != NULL) || (Head->rchild != NULL))
		{
			iCnt++;	
		}
		
		CountParent(Head->lchild);
		CountParent(Head->rchild);
	}
	return iCnt;
}

//data to be inserted: 51, 21, 101, 55, 75, 20, 105, 36
int main()
{
	
	int no=0, iRet=0, iLeaf=0;
	bool bRet=false;
	
	PNODE first =NULL;
	
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
	
	iRet=Count(first);
	cout<<"Number of Nodes are: "<<iRet<<"\n";
	
	iLeaf=CountLeaf(first);
	cout<<"Number of Leaf Nodes are: "<<iLeaf<<"\n";
	
	iParent=CountParent(first);
	cout<<"Number of Parent Nodes are: "<<iParent<<"\n";
	
	return 0;
}