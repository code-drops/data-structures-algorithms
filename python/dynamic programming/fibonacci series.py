def fib(n):
    a = [0 for i in range(n+1)]
    
    a[0] = 0
    a[1] = 1
    
    for i in range(2, len(a)):
        a[i] = a[i-1] + a[i-2]

    return a[-1]

n = int(input("Enter nth value to find out : "))
print(fib(n))
