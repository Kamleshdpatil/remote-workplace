//Addition Of Array

import java.util.*;

class Marvellous
{
	public int Addition(int Brr[])
	{
			int iSum=0, iCnt=0;

			for(iCnt=0; iCnt< Brr.length; iCnt++)
			{
				iSum=iSum + Brr[iCnt];
			}
			return iSum;
	}
}

class Program144
{
	public static void main(String[] args) 
	{
		Scanner sobj = new Scanner(System.in);
		int iSize=0, iCnt=0, iRet=0;

		System.out.println("Enter Number of element");
		iSize=sobj.nextInt();
		//Arr=(int *)malloc(sizeof(int)* iSize);   in C
		int Arr[]= new int[iSize];

		System.out.println("Enter Numbers");

		for(iCnt=0; iCnt< Arr.length; iCnt++)
		{
			Arr[iCnt]=sobj.nextInt();
			//scanf("%d",&Arr[iCnt]);             in C
		}
		Marvellous mobj =new Marvellous();
		iRet=mobj.Addition(Arr);

		System.out.println("Addition of Numbers: "+iRet);

	}
}