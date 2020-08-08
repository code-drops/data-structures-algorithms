#include <stdio.h>

 
void heapify(int arr[], int n, int i)
{
    int temp;
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // if largest is not root
    if (largest != i)
    {
        temp=arr[i];
      arr[i]=arr[largest];
      arr[largest]=temp;
 
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int temp;
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // one by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // move current root to end
        temp=arr[0];
      arr[0]=arr[i];
      arr[i]=temp;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int i,n, arr[100];
   printf("Enter number of elements to be sorted : ");
   scanf("%d",&n);

   printf("Enter elements in array : \n");
   for(i=0;i<n;i++)
   {
       printf("Enter a[%d] : ",(i));
       scanf("%d",&arr[i]);
   }
    heapSort(arr, n);
    printf("\n\nSorted array: ");
   for(i=0;i<n;i++)
      printf(" %d \t",arr[i]);
 
   return 0;
}
