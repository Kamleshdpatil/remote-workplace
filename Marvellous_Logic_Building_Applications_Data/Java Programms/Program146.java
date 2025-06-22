//Three Classes
//
//ArrayX class -same as array class
//Addition() -Extends to ArrayX(Inheritance)

import java.util.*;
import MarvellousNumbers.ArrayX;

class Marvellous extends ArrayX
{
	public Marvellous(int iValue)
	{
		super(iValue);
	}
	public int Addition()
	{
		int iCnt=0, iSum=0;
		for(iCnt=0; iCnt< Arr.length; iCnt++)
		{
			iSum=iSum+Arr[iCnt];
		}
		return iSum;
	}
}

class Program146
{
	public static void main(String[] args) 
	{
		Scanner sobj=new Scanner(System.in);

		int iLength=0, iRet=0;

		System.out.println("Enter the Number of Elements");

		iLength=sobj.nextInt();

		Marvellous mobj=new Marvellous(iLength);
		mobj.Accept();
		mobj.Display();
		iRet=mobj.Addition();
		System.out.println("\nAddition is: "+ iRet);

	}
}