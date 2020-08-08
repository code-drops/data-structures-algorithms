#include<stdio.h>
#include<conio.h>

int main()
{
	int n , i , k , a[100];
	printf(" Enter number of elements to be in array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter  %d element : ",(i+1));
		scanf("%d",&a[i]);
	}
	printf("Enter element to be searched : ");
	scanf("%d",&k);
	for(i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
		    printf("%d  found at index %d ",k,(i+1));
			getch();
			return 0;
		}
	}
	printf("Element not found");
	getch();
	return 0;
}
