def binarysearch(arr,beg,end,k):
    mid = (beg+end)//2
    # print(mid)
    if arr[mid]==k:
        print(f"{k} is found at index {mid}")
        return
    if k < arr[mid]:
        binarysearch(arr,beg,mid-1,k)
    else:
        binarysearch(arr,mid+1,end,k)

arr = list(map(int,input().strip().split()))
k = int(input())
binarysearch(sorted(arr), 0, len(arr)-1, k)