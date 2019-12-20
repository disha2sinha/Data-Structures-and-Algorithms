#include<stdio.h>
int main()
{
	int arr[20],temp,key,i,j,n;
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
	
	for(i=0;i<key;i++)
	{
		temp=arr[0];
		for(j=0;j<n-1;j++)
		{
			arr[j]=arr[j+1];
		}
		arr[j]=temp;
	}
	printf("\nArray after Rotation by %d elements:\n",key);
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;

}
