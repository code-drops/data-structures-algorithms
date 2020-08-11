def countingsort(arr):
    freq = [0]*(max(arr)+1)
    output = [0]*len(arr)
    for i in range(len(arr)):
        freq[arr[i]] += 1
    for i in range(1,len(freq)):
        freq[i] += freq[i-1]
    for i in range(len(arr)):
        output[freq[arr[i]]-1] = arr[i]
        freq[arr[i]] -= 1
    for i in range(len(arr)):
        arr[i] = output[i]
    print(arr)

arr = list(map(int,input().strip().split()))
countingsort(arr)