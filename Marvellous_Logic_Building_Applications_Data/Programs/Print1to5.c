// Loop for(), while()
#include<stdio.h>
void iterate(int);

void iterate(int iNo){
	int i=0;
	if(iNo==3){
		for(i; i<=iNo;i++)
		{
			printf("Kamlesh %d\n", i);
		}
	} else if(iNo==7){
		for(i; i<=iNo;i++)
		{
			printf("Kamlesh %d\n", i);
		}
	} else
		printf("%d This number is invalid for this Problem statement.",iNo);
	
}

int main(){
	int iNo;
	printf("Enter number for dispaly: ");
	scanf("%d",&iNo);
//while(i<=8){
//	printf("# \n");
//	i++;	
//	}
	iterate(iNo);
	return 0;
}