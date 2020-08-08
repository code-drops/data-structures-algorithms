#include<stdio.h>
#include<conio.h>

int main()
{
    int a[100],i,k,n,beg,end,mid;
    printf("Enter number of elements in array : ");
    scanf("%d",&n);
    printf("Enter array : \n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter value to be searched : ");
    scanf("%d",&k);
    beg=0;
    end=n-1;
    mid=(beg+end)/2;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(k>a[mid])
            beg=mid+1;
        else if(k<a[mid])
            end=mid-1;
        else
        {
            printf("%d found at %d index ",k,mid+1);
            return 0;
        }
    }
    printf("Element not found.");
    getch();
    return 0;
}
