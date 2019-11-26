#include<stdio.h>
void main()
{
	int array[20],n,i,key;
	printf("ENTER NUMBER OF ELEMENTS IN ARRAY:\n");
	scanf("%d",&n);
	printf("ENTER ELEMENTS IN THE ARRAY:\n");
	for(i=0;i<n;i++)
	{
		printf("ENTER %dth ELEMENT:\n",i+1);
		scanf("%d",&array[i]);
		
	}
	printf("ENTER ELEMENT TO BE SEARCHED:\n");
	scanf("%d",&key);
	int result = binarySearch(array, 0, n - 1, key); 
    if (result == -1) 
	{
		printf("ELEMENT NOT FOUND") ;
	}
	else
	{
		printf("ELEMENT IS PRESENT AT POSITION %d", result+1); 
	}
    
}
int binarySearch(int arr[], int low, int high, int x) 
{ 
    while (low<= high) 
	{ 
        int mid = low + (high - low) / 2; 
  
        if (arr[mid] == x)
		{
			return mid; 
		} 
            
   
        if (arr[mid] < x)
		{
			low = mid+ 1; 
		} 
            
  
        else
        {
        	high = mid - 1; 
		}
            
    } 
  
    return -1;
}
