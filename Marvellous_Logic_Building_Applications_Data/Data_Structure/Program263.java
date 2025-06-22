import java.util.*;

class node
{
	public int data;
	public node next;
}

class SinglyLL
{
	private node first;
	private int size;

	public SinglyLL()
	{
		this.first= null;
		this.size=0;
	}

	public void InsertFirst(int no)
	{
		node newn = null;
		newn = new node();

		newn.data = no;
		newn.next = null;

		if(first==null)
		{
			first = newn;
		}
		else
		{
			newn.next = first;
			first = newn;
		}
		this.size++;
	}

	public void InsertLast(int no)
	{
		node newn = null;
		newn = new node();

		newn.data = no;
		newn.next = null;

		if(first==null)
		{
			first = newn;
		}
		else
		{
			node temp = first;

			while(temp.next != null)
			{
				temp=temp.next;
			}
			temp.next = newn;
		}
		this.size++;
	}

	public void DeleteFirst()
	{
		if(size ==0)
			return;
		if(size==1)
		{
			first = null;
		}
		else
		{
			first = first.next;
		}
		this.size--;
	}

	public void DeleteLast()
	{
		if(size ==0)
			return;
		if(size==1)
		{
			first = null;
		}
		else
		{
			node temp =null;
			temp=first;

			while(temp.next.next != null)
			{
				temp = temp.next;
			}
			temp.next = null;
		}
		this.size--;
	}

	public void Display()
	{
		node temp =first;

		System.out.println("Elements from linked list are: ");
		while(temp != null)
		{
			System.out.print("|" + temp.data+ "|->");
			temp=temp.next;
		}
		System.out.println("null");
	}

	public void InsertAtPos(int no, int iPos)
	{
		if((iPos < 0) || (iPos > size+1))
		{
			return;
		}
		if(iPos ==1)
		{
			InsertFirst(no);
		}
		else if(iPos ==size+1)
		{
			InsertLast(no);
		}
		else
		{
			node newn = new node();
			newn.data = no;
			newn.next = null;

			node temp = first;

			for(int i =1; i < iPos-1; i++)
			{
				temp = temp.next;
			}

			newn.next = temp.next;
			temp.next = newn;

			this.size++;
		}
	}

	public void DeleteAtPos(int iPos)
	{
		if((iPos < 0) || (iPos > size+1))
		{
			return;
		}
		if(iPos ==1)
		{
			DeleteFirst();
		}
		else if(iPos ==size+1)
		{
			DeleteLast();
		}
		else
		{
			node temp = first;

			for(int i =1; i < iPos-1; i++)
			{
				temp = temp.next;
			}

			temp.next = temp.next.next;

			this.size--;
		}
	}

	public int Count()
	{
		return size;
	}

}


class Program263
{
	public static void main(String str[])
	{
		int iRet=0;
		SinglyLL obj = new SinglyLL();

		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);
		obj.InsertLast(111);

		obj.InsertAtPos(75,4);

		obj.Display();
		iRet=obj.Count();
		System.out.println("Count of Elements is: "+iRet);

		// obj.DeleteFirst();
		// obj.DeleteLast();

		obj.DeleteAtPos(5);

		obj.Display();
		iRet=obj.Count();
		System.out.println("Count of Elements after delete is: "+iRet);
	}
}