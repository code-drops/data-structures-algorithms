#include<stdio.h>
#include<conio.h>

int main()
{
	int n,temp,i,j,a[100];
	printf("Enter number of  elements to be sort : ");
	scanf("%d",&n);
	printf(" \n ");
	for(i=0;i<n;i++)
	{
	    printf("Enter %d element : ",(i+1));
	    scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j] > a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
	{
	    printf("%d ",a[i]);
	}
	getch();
	return 0;
}
