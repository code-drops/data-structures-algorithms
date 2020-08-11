def shellsort(arr):
    interval = len(arr) // 2
    print(arr)
    while interval>0:
        for i in range(interval, len(arr)):
            temp = arr[i]
            j = i
            while j>=interval and arr[j-interval]>arr[j]:
                arr[j] = arr[j-interval]
                j = j - interval
            arr[j] = temp
            print(arr)
        interval = interval//2
    print(arr)

c
shellsort(arr)