class priorityQueue:
    def __init__(self):
        self.max = 10
        self.queue = [None]*self.max
        self.front = 0
        self.rear = -1

    def enqueue(self,x):
        if self.rear == self.max-1:
            print('Overflow')
            return
        self.rear += 1
        self.queue[self.rear] = x
        for i in range(self.rear-1,self.front-1,-1):
            if self.queue[i]>=self.queue[i+1]:
                self.queue[i],self.queue[i+1] = self.queue[i+1],self.queue[i]
        self.display()

    def dequeue(self):
        if self.rear==-1 and (self.rear>self.front):
            print('Underflow')
            return
        self.front += 1
        self.display()

    def display(self):
        for i in range(self.front,self.rear+1):
            print(self.queue[i],end=' ')
        print()

q = priorityQueue()
q.enqueue(5)
q.enqueue(1)
q.enqueue(6)
q.enqueue(2)
q.dequeue()
