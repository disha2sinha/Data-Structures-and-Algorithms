#include<stdio.h>
void main()
{
	int array[20],max_position=0,min,min_position=0,n,i;
	printf("ENTER NUMBER OF ELEMENTS IN ARRAY:\n");
	scanf("%d",&n);
	printf("ENTER ELEMENTS IN THE ARRAY:\n");
	for(i=0;i<n;i++)
	{
		printf("ENTER %dth ELEMENT:\n",i+1);
		scanf("%d",&array[i]);
	}
	for(i=1;i<n;i++)
	{
		if (array[i]>array[max_position])
		{
			max_position=i;
		}
	}
	printf("MAX ELEMENT:%d AT POSITION:%d\n",array[max_position],max_position+1);
	for(i=1;i<n;i++)
	{
		if (array[i]<array[min_position])
		{
			min_position=i;
		}
	}
	printf("MIN ELEMENT:%d AT POSITION:%d\n",array[min_position],min_position+1);
}
