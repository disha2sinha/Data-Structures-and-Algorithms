#include<stdio.h>
int main()
{
	int arr[20],temp[20],key,i,n;
	printf("\nEnter the Number Of Elements of the Array:\n");
	scanf("%d",&n);
	printf("Enter Elements Of the Array:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter %dth Element:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the number of elements by which you want the array to be rotated:\n");
	scanf("%d",&key);
	printf("\nArray before Rotation:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	
	int p=key;
	int j=0;
	for(i=0;i<key;i++)
	{
		temp[i]=arr[i];
	}
	for(i=0;i<n;i++)
	{
		if(p>=n)
		{
			arr[i]=temp[j];
			j=j+1;
		}
		else{
		
			arr[i]=arr[p];
			p=p+1;
		}
	}
	printf("\nArray after Rotation by %d elements:\n",key);
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
