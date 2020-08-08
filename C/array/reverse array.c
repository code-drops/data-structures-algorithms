#include<stdio.h>
#include<conio.h>

int main()
{
	int n , temp , i , j , a[100];
	printf("Enter number of elements to be in array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter  %d element : ",(i+1));
		scanf("%d",&a[i]);
	}
	for(i=0,j=n-1;i<j;i++,j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
    }
	printf("Reversed array : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	getch();
	return 0;
}
