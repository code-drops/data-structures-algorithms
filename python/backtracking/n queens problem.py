n=4
board = [
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]

# to know wheather it is safe to keep the queen at specified (row,col)
def safe(row,col):
    
    # for row
    for i in range(col):
        if board[row][i] == 1 :
            return False
    
    # for upper diagonal elements
    for i,j in zip(range(row,-1,-1),range(col,-1,-1)):
        if board[i][j]==1:
            return False
    
    # for lower diagonal elements
    for i,j in zip(range(row,n,1),range(col,-1,-1)):
        if board[i][j] == 1:
            return False
        
    return True


def solve(col):
    
    # if all the queens are placed
    if col>=n:
        return True
    
    for i in range(n):
        if safe(i,col)==True:       # if it is safe to keep the queen at this place
            board[i][col] = 1
            if solve(col+1) == True:        # calls for next column
                return True
            board[i][col] = 0
    return False                    # if there is no solution

if solve(0)==True:
    for i in board:
        print(i)
else:
    print('No solution')
