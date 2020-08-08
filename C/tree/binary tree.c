#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};


void inorder(struct node *temp)
{
    if( temp != NULL)
    {
        inorder(temp->left);
        printf(" %d \t",temp->data);
        inorder(temp->right);
    }

}
void preorder(struct node *temp)
{
    if( temp != NULL)
    {
        printf(" %d \t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }

}
void postorder(struct node *temp)
{
    if( temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf(" %d \t",temp->data);
    }

}
struct node * insert()
{
    struct node *root=NULL;
	int x;
	printf("Enter data(0 for no data):");
	scanf("%d",&x);

	if(x==0)
		return NULL;

	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;

	printf("Enter left child of %d:\n",x);
	root->left=insert();

	printf("Enter right child of %d:\n",x);
	root->right=insert();

	return root;
}
void main()
{
    struct node *root;
    int ch;
    do
    {
        printf("\n1)Insert node\t2)inorder traversal\t3)preorder traversal\t4)postorder traversal\t5)exit\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : root=insert();
                    break;
            case 2 : inorder(root);
                    printf("\n");
                    break;
            case 3 : preorder(root);
                    printf("\n");
                    break;
            case 4 : postorder(root);
                    printf("\n");
                    break;
            case 5 : exit(0);
        }
    }while(ch!=5);
    getch();
}
