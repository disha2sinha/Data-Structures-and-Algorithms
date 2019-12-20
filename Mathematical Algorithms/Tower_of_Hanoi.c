#include<stdio.h>

void tower(int n,char beg, char aux,char end)
{
	if(n==1)
	{
		printf("\nMove Disk 1 from %c ---> %c\n",beg,end);
		return;
	}
	tower(n-1,beg,end,aux);
	printf("\nMove disk %d from %c ---> %c\n",n,beg,end);
	tower(n-1,aux,beg,end);
	return;
}

void main()
{
	int number;
	printf("ENTER NUMBER OF DISCS:\n");
	scanf("%d",&number);
	tower(number,'A','B','C');
}

