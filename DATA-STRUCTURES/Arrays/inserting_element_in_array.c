#include<stdio.h>
int main()
{
	int array[20],num,pos,i;
	printf("ENTER 10 ELEMENTS FOR ARRAY : \n");
	for(i=0;i<10;i++)
	{
		printf("ENTER %dTH ELEMENT : ",i+1);
		scanf("%d",&array[i]);
		printf("\n");
	}
	printf("ENTER ELEMENT TO BE INSERTED IN ARRAY: \n");
	scanf("%d",&num);
	printf("ENTER POSITION OF ARRAY AT WHICH ELEMENT IS TO BE INSERTED: \n");
	scanf("%d",&pos);
	for(i=10;i>=pos;i--)
	{
	 	array[i+1]=array[i];
	}
	array[pos]=num;
	printf("MODIFIED ARRAY: \n");
	for(i=0;i<11;i++)
	{
		printf("%d	",array[i]);
	}
}
