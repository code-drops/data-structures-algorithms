#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct link
{
    int coeff;
    int pow;
    struct link *next;
};
struct link *poly1=NULL,*poly2=NULL,*result=NULL;

void create(struct link *node)
{
    char ch;
    label:
    printf("Enter coefficient of term : ");
    scanf("%d",&node->coeff);
    printf("Enter power of term : ");
    scanf("%d",&node->pow);
    printf("Want to add another term (y/n) : ");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='n' || ch=='N')
    {
        node->next=NULL;
        return ;
    }
    node->next=(struct link *)malloc(sizeof(struct link));
    node=node->next;
    goto label;

}
void show(struct link *node)
{
    label:
    printf("%dx^%d",node->coeff,node->pow);
        if(node->next==NULL)
        {
            return ;
        }
        node=node->next;
        printf("+");
        goto label;
}

void add(struct link *poly1,struct link *poly2,struct link *result)
{
    fflush(stdin);
    while((poly1->next!=NULL) &&  (poly2->next!=NULL))
     {
      if(poly1->pow > poly2->pow)
      {
       result->pow = poly1->pow;
       result->coeff = poly1->coeff;
       poly1 = poly1->next;
       }
      else if(poly1->pow<poly2->pow)
      {
       result->pow=poly2->pow;
       result->coeff=poly2->coeff;
       poly2=poly2->next;
       }
      else
      {
       result->pow=poly1->pow;
       result->coeff=poly1->coeff+poly2->coeff;
       poly1=poly1->next;
       poly2=poly2->next;
       }
      result->next=(struct link *)malloc(sizeof(struct link));
      result=result->next;
      result->next=NULL;
     }
     while((poly1->next!=NULL) ||  (poly2->next!=NULL))
     {
      if(poly1->next)
      {
       result->pow=poly1->pow;
       result->coeff=poly1->coeff;
       poly1=poly1->next;
       }
      if(poly2->next)
      {
       result->pow=poly2->pow;
       result->coeff=poly2->coeff;
       poly2=poly2->next;
       }
       result->next=(struct link *)malloc(sizeof(struct link));
       result=result->next;
       result->next=NULL;
       }
}

void main()
{
    poly1=(struct link *)malloc(sizeof(struct link));
    poly2=(struct link *)malloc(sizeof(struct link));
    result=(struct link *)malloc(sizeof(struct link));
    printf("Enter 1st polynomial : \n");
    create(poly1);
    printf("\nPolynomial expression 1 : ");
    show(poly1);
    printf("\n\nEnter 2nd polynomial : \n");
    create(poly2);
    printf("\nPolynomial expression 2 : ");
    show(poly2);
    add(poly1,poly2,result);
    printf("\n\n Result : ");
    fflush(stdin);
    show(result);
    getch();
    return 0;
}
