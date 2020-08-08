#include<stdio.h>
#include<conio.h>
#define MAX 100
int queue[MAX];
int front=0;
int rear=-1;
void enqueue()
{
    int data;
    if(rear==MAX-1)
    {
        printf("Queue overflow \n\n");
        return ;
    }
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    rear++;
    queue[rear]=data;
    printf("Element inserted to queue. .\n\n");
}
void dequeue()
{
    if(front>rear)
    {
        printf("Stack underflow. \n\n");
        return ;
    }
    printf("Element removed : %d\n\n",queue[front]);
    front++;
}
void display()
{
    int i;
    if(front>rear)
    {
        printf("No elements to display. \n\n");
        return ;
    }
    printf("Queue : ");
    for(i=front;i<=rear;i++)
    {
        printf("%d \t",queue[i]);
    }
    printf("\n\n");
}
int main()
{
int ch;
	do
	{
		printf("1. Insert an element to queue \n 2. Remove an element from queue \n 3. Display elements of queue \n 4 . Exit");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : enqueue();
					 break;
			case 2 : dequeue();
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
