//Three Classes including main
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
	public float Average()
	{
		int iCnt=0, iSum=0;
		float fAvg;
		for(iCnt=0; iCnt< Arr.length; iCnt++)
		{
			iSum=iSum+Arr[iCnt];
		}
		return (iSum/Arr.length);
	}
}

class Program147
{
	public static void main(String[] args) 
	{
		Scanner sobj=new Scanner(System.in);

		int iLength=0;
		float fRet=0.0f;

		System.out.println("Enter the Number of Elements");

		iLength=sobj.nextInt();

		Marvellous mobj=new Marvellous(iLength);
		mobj.Accept();
		mobj.Display();
		fRet=mobj.Average();
		System.out.println("\nAverage is: "+ fRet);

	}
}