def bucketsort(arr):
    bucket = [[] for i in range(10)]
    for i in arr:
        bucket[int(10 * i)].append(i)
    for i in range(len(bucket)):
        bucket[i] = sorted(bucket[i])
    k = 0
    for i in range(len(bucket)):
        for j in range(len(bucket[i])):
            arr[k] = bucket[i][j]
            k += 1
    print(arr)

arr = list(map(float,input().strip().split()))
bucketsort(arr)