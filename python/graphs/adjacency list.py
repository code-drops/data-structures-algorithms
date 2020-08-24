class node:
    def __init__(self,v):
        self.vertex = v
        self.next = None

class Graph:
    def __init__(self,size):
        self.size = size
        self.graph = [None for i in range(size)]

    def addEdge(self,src,dest):
        newnode = node(dest)
        if self.graph[src]==None:
            self.graph[src] = newnode
        else:
            temp = self.graph[src]
            while temp.next!=None:
                temp = temp.next
            temp.next = newnode

        newnode = node(src)
        if self.graph[dest]==None:
            self.graph[dest] = newnode
        else:
            temp = self.graph[dest]
            while temp.next!=None:
                temp = temp.next
            temp.next = newnode

    def printGraph(self):
        for i in range(self.size):
            print("Vertex " + str(i) + ":", end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next
            print(" \n")

g = Graph(3)
g.addEdge(0,2)
g.addEdge(1,1)
g.addEdge(0,1)
g.printGraph()