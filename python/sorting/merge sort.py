def merge(arr,beg,mid,end):
    i = beg
    j = mid+1
    temp = []
    while i<=mid and j<=end:
        if arr[i]<arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1
    while i<=mid:
        temp.append(arr[i])
        i += 1
    while j<=end:
        temp.append(arr[j])
        j += 1
    for i in range(len(temp)):
        arr[beg] = temp[i]
        beg += 1

def mergesort(arr,beg,end):
    if beg<end:
        mid = (beg+end)//2
        mergesort(arr,beg,mid)
        mergesort(arr,mid+1,end)
        merge(arr,beg,mid,end)

arr = list(map(int,input().strip().split()))
mergesort(arr, 0, len(arr)-1)
print(arr)