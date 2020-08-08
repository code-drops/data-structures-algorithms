#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j,a[100][100];
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter 1 if both vertices are adjacent , otherwise 0\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d -> %d : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n\nAdjacency matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\nLinked list : \n");
    for(i=1;i<=n;i++)
    {
        printf("%d",i);
        for(j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                printf("-> %d",j);
            }
        }
        printf("\n");
    }
    getch();
    return 0;
}
