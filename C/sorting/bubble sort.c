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
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
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
