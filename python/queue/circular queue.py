class CircularQueue:
    def __init__(self):
        self.max = 100
        self.queue = [0]*self.max
        self.rear = -1
        self.front = -1

    def enqueue(self,x):
        if (self.front==0 and self.rear==self.max-1) or (self.front==self.rear+1):
            print('Overflow')
            return
        if self.front==-1:
            self.front = 0
        self.rear = (self.rear+1)%self.max
        self.queue[self.rear] = x
        print('Element inserted')

    def dequeue(self):
        if (self.rear == -1):
            print('Underflow')
            return
        if self.front==self.rear:
            self.rear = self.front = -1
        elif self.front == self.max -1:
            self.front = 0
        else:
            self.front += 1
        print('Element removed')

    def display(self):
        if (self.rear == -1):
            print('Underflow')
            return
        if self.front < self.rear:
            for i in range(self.front,self.rear+1):
                print(i,end=' ')
        else:
            for i in range(self.front,self.max):
                print(i,end=' ')
            for i in range(0,self.rear+1):
                print(i,end=' ')
        print()

q = CircularQueue()
q.enqueue(1)
q.enqueue(2)
q.display()
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)
q.display()
q.dequeue()
q.display()