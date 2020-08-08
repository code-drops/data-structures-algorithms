#include <stdio.h>
#include<conio.h>
#define MAX 5

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push_stack1()
{
    int data;
    if(top1==top2-1)
    {
        printf("Stack 1 is full. \n\n");
        return ;
    }
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    top1++;
    stack[top1]=data;
    printf("Element inserted");
}

void push_stack2()
{
    int data;
    if(top1==top2-1)
    {
        printf("Stack 2 is full. \n\n");
        return ;
    }
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    top2--;
    stack[top2]=data;
    printf("Element inserted");
}

void pop_stack1()
{
  if (top1 >= 0)
  {
      printf("%d is popped from stack1",stack[top1]);
      top1--;
  }
  else
  {
    printf ("Stack1 Empty! Cannot Pop\n");
    return ;
  }
}

void pop_stack2()
{
  if (top2 < MAX)
  {
      printf("%d is popped from stack2",stack[top2]);
      top2++;
  }
  else
  {
    printf ("Stack2 Empty! Cannot Pop\n");
    return ;
  }
}

void display()
{
    int i;
    if(top1==-1 && top2==MAX)
    {
        printf("No elements to display");
        return 0;
    }
    printf("Stack 1 : ");
    for(i=0;i<=top1;i++)
    {
        printf("\t%d",stack[i]);
    }
    printf("\nStack 2 : ");
    for(i=top2;i<MAX;i++)
    {
        printf("\t%d",stack[i]);
    }
}

int main()
{
    int ch;
    do{
    printf("\n\n1. Insert an element to stack1 \n 2. Insert an element to stack2 \n 3. Remove an element from stack1 \n 4. Remove an element from stack2 \n 5. Display elements \n 6. Exit");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : push_stack1();
					 break;
			case 2 : push_stack2();
					 break;
			case 3 : pop_stack1();
					 break;
			case 4 : pop_stack2();
                    break;
            case 5 : display();
                    break;
            case 6 : exit(0);
                    break;
			default : printf("Invalid choice");
					break;
		}
	}while(ch!=6);
	getch();
	return 0 ;
}
