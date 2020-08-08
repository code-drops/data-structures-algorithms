def partition(arr,beg,end):
    j = beg - 1
    pivot = arr[end]
    for i in range(beg,end):
        if arr[i]<=pivot:
            j += 1
            arr[i],arr[j] = arr[j],arr[i]
    arr[j+1],arr[end] = arr[end],arr[j+1]
    return j+1

def quicksort(arr,beg,end):
    if beg<end:
        pivot = partition(arr,beg,end)
        quicksort(arr,beg,pivot-1)
        quicksort(arr,pivot+1,end)

arr = list(map(int,input().strip().split()))
quicksort(arr, 0, len(arr)-1)
print(arr)