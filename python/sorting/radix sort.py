def countingsort(arr,place):
    freq = [0]*(max(arr)+1)
    output = [0]*len(arr)
    for i in range(len(arr)):
        index = int(arr[i]//place)%10
        freq[index] += 1
    for i in range(1,len(freq)):
        freq[i] += freq[i-1]
    for i in range(len(arr)):
        index = int(arr[i] // place) % 10
        output[freq[index]-1] = arr[i]
        freq[arr[i]] -= 1
    for i in range(len(arr)):
        arr[i] = output[i]

def radixsort(arr):
    place = 1
    while max(arr)//place>0:
        countingsort(arr,place)
        place = place*10
    print(arr)

arr = list(map(int,input().strip().split()))
radixsort(arr)