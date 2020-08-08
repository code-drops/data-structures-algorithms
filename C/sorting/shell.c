#include <stdio.h>
#include<conio.h>

void shellsort(int arr[], int num)
{
    int i,j,k,tmp;
    for (i=num/2;i>0;i=i/2)
    {
        for (j=i;j<num;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if(arr[k+i]>=arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}
int main()
{
    int arr[30];
    int i,num;
    printf("Enter total no. of elements : ");
    scanf("%d", &num);
    printf("Enter elements in array : \n");
    for (i=0;i<num;i++)
    {
        printf("Enter a[%d] : ",(i+1));
        scanf("%d",&arr[i]);
    }
    shellsort(arr, num);
    printf("\n\nSorted array: ");
    for (i=0;i<num;i++)
        printf("%d  ",arr[i]);
    getch();
    return 0;
}
