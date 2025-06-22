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
		System.out.println("String is: " + str);
	}
}

class Marvellous extends StringX
{
	public int CountVowels()
	{
		int iCnt=0, i=0;
		char Arr[]= str.toCharArray();

		for(i=0; i<Arr.length; i++)
		{
			if(Arr[i]=='A' || Arr[i]=='E' || Arr[i]=='I' || Arr[i]=='O' || Arr[i]=='U' || Arr[i]=='a' || Arr[i]=='e' || Arr[i]=='i' || Arr[i]=='o' || Arr[i]=='u')
			{
				iCnt++;
			}
		}
		return iCnt;
	}
}

class Program151
{
	public static void main(String[] args)
	{
		Marvellous mobj = new Marvellous();
		int iRet=0;
		mobj.Accept();
		mobj.Display();
		
		iRet=mobj.CountVowels();
		System.out.println("Number Of Vowels Are: " + iRet);
	}
}