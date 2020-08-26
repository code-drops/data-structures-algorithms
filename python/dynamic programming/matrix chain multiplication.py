import sys

def matrixMul(a,n):

    # creating an array of n*n elements to store the scalar multiplication
    m = [[0 for i in range(n)] for i in range(n)]

    # assign 0 for A1*A1
    for i in range(1,n):
        m[i][i] = 0

    for L in range(2,n):                                    # L defines the number of matrix consider
        for i in range(1,n-L+1):                            # for every pair of matrices of length L
            j = i+L-1
            m[i][j] = sys.maxsize                           # keeping the size to max
            for k in range(i,j):
                q = m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j]
                if q < m[i][j]:
                    m[i][j] = q
    for i in m:
        print(i)
    return m[1][n-1]


a = [1,2,3,4]
print(matrixMul(a, len(a)-1))
