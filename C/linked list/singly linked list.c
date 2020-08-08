#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *ptr =  NULL;
struct node *new_node =  NULL;
void  insert_beg()
{
    int data;
    new_node =(struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
        return ;
    }
    new_node->next=head;
    head=new_node;
}

void  insert_mid()
{
    int data,key;
    new_node =(struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
        return ;
    }
    printf("Enter element after which value to be inserted : ");
    scanf("%d",&key);
    ptr=head;
    while(ptr!=NULL)
    {
        if(key==ptr->data)
        {
            new_node->next=ptr->next;
            ptr->next=new_node;
            return ;
        }
        ptr=ptr->next;
    }
    printf("Element not found");
}

void  insert_end()
{
    int data;
    new_node =(struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
        return ;
    }
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
}

void del_beg()
{
    if(head==NULL)
    {
        printf("No elements to delete");
        return ;
    }
    ptr=head;
    head=head->next;
    free(ptr);
    printf("Node deleted");
}

void del_mid()
{
    int value;
    printf("Enter element to be deleted : ");
    scanf("%d",&value);
    ptr=head;
    while(ptr->next!=NULL)
    {
        if(ptr->next->data==value)
        {
            new_node=ptr->next;
            ptr->next=new_node->next;
            free(new_node);
        }
        ptr=ptr->next;
    }
    printf("Node deleted");
}
void del_end()
{
    ptr=head;
    while(ptr->next->next!=NULL)
    {
        new_node=ptr->next;
        ptr->next=NULL;
    }
    free(new_node);
    printf("Node deleted");
}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        if(ptr->next!=NULL)
            printf("->");
        ptr=ptr->next;
    }
}

int main()
{
    int ch;
    do{
    printf("\n\n1. Insertion at beginning in linked list \n 2. Insertion in between in linked list \n 3. Insertion at end in linked list \n 4. Deletion from beginning in linked list \n 5. Deletion in between in linked list \n 6. Deletion at end in linked list \n 7. Display linked list \n 8. Exit");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insert_beg();
					 break;
			case 2 : insert_mid();
					 break;
			case 3 : insert_end();
					 break;
			case 4 : del_beg();
                    break;
            case 5 : del_mid();
                     break;
            case 6 : del_end();
                     break;
            case 7 : display();
                    break;
            case 8 : exit(0);
                    break;
			default : printf("Invalid choice");
					break;
		}
	}while(ch!=8);
	getch();
	return 0 ;
}

