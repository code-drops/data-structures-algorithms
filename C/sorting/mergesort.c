#include <stdio.h>
#include<conio.h>
void partition(int a[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(a, low, mid);
        partition(a, mid + 1, high);
        mergeSort(a, low, mid, high);
    }
}
void mergeSort(int a[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[50];
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (a[lo] <= a[mi])
        {
            temp[i] = a[lo];
            lo++;
        }
        else
        {
            temp[i] = a[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = a[k];
             i++;
        }
    }
    for (k = low; k <= high; k++)
    {
        a[k] = temp[k];
    }
}
int main()
{
    int a[50];
    int i, n;
    printf("Enter number of elements in array :");
    scanf("%d",&n);
    printf("Enter elements of array :\n");
    for(i = 0; i < n; i++)
    {
        printf("a[%d] : ",(i+1));
        scanf("%d",&a[i]);
    }
    partition(a, 0, n - 1);
    printf("\n\nSorted array :  ");
    for(i = 0;i < n; i++)
    {
         printf("%d   ",a[i]);
    }
    getch();
    return 0;
}
