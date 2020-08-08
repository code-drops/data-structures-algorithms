#include<stdio.h>
#include<conio.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push()
{
	int data;
    if (top >= MAX)
    {
        printf("Stack overflow");
        return ;
    }
    printf("Enter element to be inserted : ");
	scanf("%d",&data);
	top++;
	stack[top] = data;
	printf("Data pushed to stack.\n\n");
}
void pop()
{
	int data;
	if(top==-1)
	{
		printf("Stack underflow");
		return ;
	}
	data=stack[top];
	top--;
	printf("Element removed : %d",data);
	printf("\n\n");
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("No elements to display");
	}
	printf("Stack : ");
	for(i=0;i<=top;i++)
	{
		printf("%d ",stack[i]);
	}
	printf("\n\n");
}
int main()
{
	int ch;
	do
	{
		printf("1. Insert an element \n 2. Remove an element \n 3. Display elements \n 4 . Exit");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : push();
					 break;
			case 2 : pop();
					 break;
			case 3 : display();
					 break;
			case 4 : exit(0);
			default : printf("Invalid choice");
					break;
		}
	}while(ch!=4);
	getch();
	return 0;
}
