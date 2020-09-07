def knapsack(W,wt,val,n):
    cost = [[0 for i in range(W+1)] for i in range(n+1)]
    # print(cost)
    for i in range(n+1):
        for w in range(W+1):
            if i==0 or w==0:
                cost[i][w] = 0
            elif wt[i-1] <= w:
                cost[i][w] = max(cost[i-1][w],val[i-1]+cost[i-1][w-wt[i-1]])
            else:
                cost[i][w] = cost[i-1][w]
    print(cost)
    return cost[n][W]

val = [6,10,12]
wt = [1,2,3]
W = 5
n = len(val)
print(knapsack(W,wt,val,n))
