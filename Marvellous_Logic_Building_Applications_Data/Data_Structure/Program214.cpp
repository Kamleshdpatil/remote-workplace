#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE, *PNODE;

class DoublyCL
{
	private:
		PNODE first;
		PNODE last;
		int size;
	
	public:
		DoublyCL()
		{
			first=NULL;
			last=NULL;
			size=0;
		}
		
	void Display();
	int Count();
	void InsertFirst(int no);
	void InsertLast(int no);
	void InsertAtPos(int no, int iPos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int iPos);
	
};

// return_value class_name :: Function_name(parameter)

void DoublyCL :: InsertFirst(int no)
{
	PNODE newn = new NODE;
	newn->data= no;
	newn->next= NULL;
	newn->prev= NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first= newn;
		last = newn;
	}
	else
	{
		newn->next= first;
		first->prev= newn;
		first = newn;
	}
	last->next=first;
	first->prev= last;
	size ++;
}

void DoublyCL :: InsertLast(int no)
{
	PNODE newn = new NODE;
	newn->data= no;
	newn->next= NULL;
	newn->prev= NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first= newn;
		last = newn;
	}
	else
	{
		last->next = newn;
        newn->prev = last;
        last = newn;
	}
	last->next=first;
	first->prev= last;
	size ++;
}

void DoublyCL :: Display()
{
	PNODE temp = first;
	
	for(int i=1; i<=size; i++)
	{
		cout<<"|"<<temp->data<<"|";
		temp=temp->next;
	}
	cout<<"\n";
}

int DoublyCL :: Count()
{
	return size;
}

void DoublyCL :: DeleteFirst()
{
	if((first==NULL) && (last==NULL))
	{
		return;
	}
	else if(first== last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first= first->next;
		delete last->next;
		first->prev=last;
		last->next=first;
	}
	size--;
}

void DoublyCL :: DeleteLast()
{
	if((first==NULL) && (last==NULL))
	{
		return;
	}
	else if(first== last)
	{
		delete last;
		first = NULL;
		last = NULL;
	}
	else
	{
		last= last->prev;
		delete last->next; // delete first->prev;
		first->prev=last;
		last->next=first;
	}
	size--;
}

void DoublyCL :: InsertAtPos(int no, int iPos)
{
	if((iPos < 1) || (iPos > size + 1))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos== size +1)
	{
		InsertLast(no);
	}
	else
	{
		PNODE newn = new NODE;
		int i=0;
		newn->data= no;
		newn->next=NULL;
		newn->prev=NULL;
		
		PNODE temp = first;
		
		for(i=1; i < iPos-1; i++)
		{
			temp= temp->next;
		}
		
		newn->next=temp->next;
		newn->next->prev= newn;
		temp->next=newn;
		newn->prev= temp;
		size++;
	}
}

void DoublyCL :: DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > size))
	{
		return;
	}
	if(iPos ==1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = first;
		
		for(int i=1; i < iPos-1; i++)
		{
			temp= temp->next;
		}
		temp->next= temp->next->next;
		delete temp->next->prev;
		temp->next->prev= temp;
	}
}
int main()
{
	DoublyCL obj;
	int iRet=0;
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.InsertLast(51);
	obj.InsertLast(101);
	
	obj.InsertAtPos(75,3);
	obj.Display();
	
	iRet=obj.Count();
	cout<<"Node Elements are: "<<iRet<<endl;
	
	obj.DeleteLast();
	obj.DeleteLast();
	
	obj.DeleteAtPos(3);
	obj.Display();
	
	iRet=obj.Count();
	cout<<"Node Elements are: "<<iRet<<endl;
	
	return 0;
}