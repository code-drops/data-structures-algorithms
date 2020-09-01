import sys
def MatrixChainOrder(d,n):
    m = [[0 for i in range(n)] for i in range(n)]

    for i in range(1,n):
        m[i][i] = 0

    for L in range(2,n):
        for i in range(1,n-L+1):
            j = i+L-1
            m[i][j] = sys.maxsize
            for k in range(i,j):
                q = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j]
                if q < m[i][j]:
                    m[i][j] = q
    return m[1][n-1]

arr = [1, 2, 3, 4]
size = len(arr)
print(MatrixChainOrder(arr, size))
