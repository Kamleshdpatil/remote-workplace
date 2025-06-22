import java.util.*;

class StringX
{
	public String str;

	public void Accept()
	{
		Scanner sobj= new Scanner(System.in);
		System.out.println("Enter String: ");
		str=sobj.nextLine();

	}

	public void Display()
	{
		System.out.println("Original String is: " + str);
	}
}

class Marvellous extends StringX
{
	public boolean CheckPalimdrome()
	{
		char Arr[]= str.toCharArray();
		int iStart=0, iEnd=Arr.length-1;
		char temp;

		while(iStart < iEnd)
		{
			temp=Arr[iStart];
			Arr[iStart] = Arr[iEnd];
			Arr[iEnd]=temp;

			iStart++;
			iEnd--;	
		}
		String newstr = new String(Arr);
		boolean bRet = newstr.equals(str);
		return bRet;
	}
}

class Program156
{
	public static void main(String[] args)
	{
		Marvellous mobj = new Marvellous();
		mobj.Accept();
		mobj.Display();
		boolean bRet;
		bRet=mobj.CheckPalimdrome();

		if(bRet == true)
		{
			System.out.println("String is Palimdrome");
		} else {
			System.out.println("String is Not Palimdrome");
		}
	}
}