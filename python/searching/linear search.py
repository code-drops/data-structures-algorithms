def linearsearch(arr,k):
    for i in range(len(arr)):
        if arr[i]==k:
            print(f"{k} found at {i} index")
            return
    print(f"{k} not found in list")

arr = list(map(int,input().strip().split()))
k = int(input())
linearsearch(arr,k)