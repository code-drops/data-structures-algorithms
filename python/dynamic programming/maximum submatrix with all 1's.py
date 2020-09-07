a = [[0, 1, 1, 0, 1],
    [1, 1, 0, 1, 0], 
    [0, 1, 1, 1, 0], 
    [1, 1, 1, 1, 0], 
    [1, 1, 1, 1, 1], 
    [0, 0, 0, 0, 0]]

rows = len(a)
cols = len(a[0])
s = [[0 for i in range(cols)] for i in range(rows)]
# print(s)

# 1st row
for i in range(cols):
    s[0][i] = a[0][i]

# 1st col
for i in range(rows):
    s[i][0] = a[i][0]

for i in range(1,rows):
    for j in range(1,cols):
        if a[i][j] == 1:
            s[i][j] = min(s[i-1][j],s[i][j-1],s[i-1][j-1]) + 1
        else:
            s[i][j] = 0
print(f'Auxiliary matrix : ')
print(s)
maximum = 0
imax = 0
jmax = 0
for i in range(rows):
    for j in range(cols):
        if s[i][j] > maximum:
            maximum = s[i][j]
            imax = i
            jmax = j

print(f'Index ({imax-maximum+1},{jmax-maximum+1}) to ({imax},{jmax})')
for i in range(imax,imax-maximum,-1):
    for j in range(jmax,jmax-maximum,-1):
        print(a[i][j],end=' ')
    print()
