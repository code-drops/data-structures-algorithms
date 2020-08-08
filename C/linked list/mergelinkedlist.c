#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;
struct node *ptr =  NULL;
struct node *ptr1 =  NULL;
struct node *ptr2 = NULL;
struct node *new_node =  NULL;
void  insert(struct node *head)
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
void display(struct node *head)
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
void merge()
{
    head3=(struct node *)malloc(sizeof(struct node));
    ptr=head3;
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data<=ptr2->data)
        {
            ptr->data=ptr1->data;
            ptr1=ptr1->next;
        }
        else
        {
            ptr->data=ptr2->data;
            ptr2=ptr2->next;
        }
        ptr->next=(struct node *)malloc(sizeof(struct node));
        ptr=ptr->next;
    }
    if(ptr1==NULL)
    {
        ptr->data=ptr2->data;
        ptr->next=ptr2->next;
    }
    else
    {
        ptr->data=ptr1->data;
        ptr->next=ptr1->next;
    }
}
int main()
{
    char ch;
    printf(" ---- 1st linked list ----  \n");
    do
    {
        insert(head1);
        fflush(stdin);
        printf("Press y to enter new element(otherwise n) : ");
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    fflush(stdin);
    printf("\n ---- 2nd linked list ----  \n");
    do
    {
        insert(head2);
        fflush(stdin);
        printf("Press y to enter new element(otherwise n) : ");
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    fflush(stdin);
    merge();
    display(head3);
    getch();
    return 0;
}
