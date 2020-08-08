#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node* insert(struct node* root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d \t", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    int ch,k;
    do
    {
        printf("\n1)Insert node\t2)inorder traversal\t3)exit\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :printf("Enter value to be entered : ");
                    scanf("%d",&k);
                    root=insert(root,k);
                    break;
            case 2 : inorder(root);
                    printf("\n");
                    break;
            case 3 : exit(0);
        }
    }while(ch!=3);
    getch();
    return 0;
}
