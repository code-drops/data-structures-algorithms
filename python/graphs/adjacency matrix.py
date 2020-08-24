class Graph:
    def __init__(self,size):
        self.matrix = []
        for i in range(size):
            self.matrix.append([0 for i in range(size)])
        self.size = size

    def add_edge(self,v1,v2):
        self.matrix[v1][v2] = 1

    def remove_edge(self,v1,v2):
        self.matrix[v1][v2] = 0

    def printGraph(self,matrix):
        for row in matrix:
            for col in range(len(row)):
                print(row[col],end=' ')
            print()

g = Graph(3)
g.add_edge(0,1)
g.add_edge(1,0)
g.add_edge(2,1)
g.add_edge(0,0)
g.printGraph(g.matrix)