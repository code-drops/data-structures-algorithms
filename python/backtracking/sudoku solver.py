grid =[
        [3, 0, 6, 5, 0, 8, 4, 0, 0],
        [5, 2, 0, 0, 0, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 0, 3, 1],
        [0, 0, 3, 0, 1, 0, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [0, 0, 5, 2, 0, 6, 3, 0, 0]
    ]
n = 9
loc = [0,0]

def printboard():
    for i in range(n):
        if i%3==0 and i!=0:
            print('- '*11)
        for j in range(n):
            if j%3==0 and j!=0:
                print('|',end=' ')
            print(grid[i][j],end=' ')
        print()

def emptyLocation():
    for row in range(n):
        for col in range(n):
            if grid[row][col]==0:
                loc[0] = row
                loc[1] = col
                return True
    return False

def isSafe(row,col,num):
    # Check row
    for i in range(n):
        if grid[row][i] == num:
            return False

    # check column
    for i in range(n):
        if grid[i][col] == num:
            return False

    # check block
    row = (row//3)*3
    col = (col//3)*3
    for i in range(row,row+3):
        for j in range(col,col+3):
            if grid[i][j] == num:
                return False
    return True


def solve_sudoku():
    # If there is no empty location left
    if not emptyLocation():
        return True

    # empty location index
    row = loc[0]
    col = loc[1]

    for num in range(1,10):
        if isSafe(row,col,num):
            grid[row][col] = num
            if solve_sudoku():
                return True
            grid[row][col] = 0
    return False

if __name__ == '__main__':
    if solve_sudoku():
        printboard()
    else:
        print('No solution')
