#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *head=NULL;
struct node *ptr=NULL;
struct node *temp=NULL;

void insert_beg()
{
    int data;
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(head==NULL)
    {
        head=temp;
        return ;
    }
    temp->right=head;
    head->left=temp;
    head=temp;
}

void insert_mid()
{
    int data,value;
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(head==NULL)
    {
        head=temp;
        return ;
    }
    printf("Enter element after which node is to be inserted : ");
    scanf("%d",&value);
    ptr=head;
    while(ptr->right!=NULL)
    {
        if(ptr->data==value)
        {
            temp->right=ptr->right;
            ptr->right->left=temp;
            ptr->right=temp;
            temp->left=ptr;
            return ;
        }
        ptr=ptr->right;
    }
}

void insert_end()
{
    int data;
    printf("Enter element to be inserted : ");
    scanf("%d",&data);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(head==NULL)
    {
        head=temp;
        return ;
    }
    ptr=head;
    while(ptr->right!=NULL)
    {
        ptr=ptr->right;
    }
    ptr->right=temp;
    temp->left=ptr;
}

void del_beg()
{
    if(head==NULL)
    {
        printf("No node to delete ");
        return;
    }
    ptr=head;
    head=head->right;
    head->left=NULL;
    free(ptr);
}

void del_mid()
{
    int data;
    printf("Enter value to be deleted : ");
    scanf("%d",&data);
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==data)
        {
            ptr->left->right=ptr->right;
            ptr->right->left=ptr->left;
            return ;
        }
        ptr=ptr->right;
    }
}

void del_end()
{
    ptr=head;
    while(ptr->right->right!=NULL)
    {
        ptr=ptr->right;
    }
    temp=ptr->right;
    ptr->right=NULL;
    free(temp);
}

void display()
{
    ptr=head;
    printf("Linked list : ");
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        if(ptr->right!=NULL)
            printf(" -> ");
        ptr=ptr->right;
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

