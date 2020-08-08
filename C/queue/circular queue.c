#include<stdio.h>
#include<conio.h>
#define MAX 4
int queue[MAX];
int front=0;
int rear=-1;
void enqueue()
{
    int data;
    if((front==0 && rear==MAX-1) || (front>0 && rear==front-1))
    {
        printf("Queue overflow \n\n");
        return ;
    }
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    if(rear==MAX-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=data;
    printf("Element inserted to circular queue. .\n\n");
}
void dequeue()
{
    int data;
    if((front==0) && (rear==-1))
    {
        printf("Queue underflow. \n\n");
        return ;
    }
    if(front==rear)
    {
        data=queue[front];
        rear=-1;
        front=0;
    }
    else
    {
        if(front==MAX-1)
        {
            data=queue[front];
            front=0;
        }
        else
        {
            data=queue[front];
        }
    }
    printf("Element removed : %d\n\n",queue[front]);
    front++;
}
void display()
{
    int i;
    if((front==0)&&(rear==-1))
    {
        printf("No elements to display. \n\n");
        return ;
    }
    printf("Queue : ");
    if(front>rear)
    {
        for(i=0;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        for(i=front;i<=MAX-1;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\nRear is at %d ",queue[rear]);
        printf("\nFront is at %d",queue[front]);
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",queue[i]);
        }
        printf("\nrear is at %d\n",queue[rear]);
        printf("front is at %d\n",queue[front]);
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
