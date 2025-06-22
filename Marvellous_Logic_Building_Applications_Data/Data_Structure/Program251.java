import java.util.*;

abstract class ArrayX
{

	public int Arr[];

	public ArrayX(int size)
	{
		Arr =new int[size];
	}

	public void Accept()
	{
		Scanner sobj= new Scanner(System.in);

		System.out.println("Enter Elements: ");
		for(int i =0; i< Arr.length; i++)
		{
			Arr[i]= sobj.nextInt();
		}
	}

	public void Display()
	{
		System.out.println("Array Elements are: ");
		for(int i =0; i< Arr.length; i++)
		{
			System.out.println(Arr[i]);
		}

	}

	public abstract boolean search(int ArrayX);
}

class  searching extends ArrayX {
	
	public searching(int size)
	{
		super(size);
	}

	public boolean search(int no)
	{
		int i=0;
		for(i=0; i<Arr.length; i++)
		{
			if(Arr[i]==no)
			{
				break;
			}
		}
		if(i == Arr.length)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

class Program251
{
	public static void main(String[] args) {

		Scanner sobj= new Scanner(System.in);
		System.out.println("Enter size of Array: ");
		int size = sobj.nextInt();

		searching obj = new searching(size);

		obj.Accept();
		obj.Display();

		System.out.println("Enter element for search: ");
		int no = sobj.nextInt();

		boolean bret = obj.search(no);

		if(bret == true)
		{
			System.out.println("Element is there.");
		}
		else
		{
			System.out.println("Element is not there.");
		}
		
	}
}