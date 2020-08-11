class Queue():
    def __init__(self):
        self.max = 100
        self.queue = [0]*self.max
        self.front = 0
        self.rear = -1

    def enqueue(self,x):
        if self.rear==self.max:
            print('No more elements can be added')
            return
        self.rear += 1
        self.queue[self.rear] = x
        print(f'Element {x} got inserted')

    def dequeue(self):
        if self.rear==-1 or self.front>self.rear:
            print('No element to be remove')
            return
        print(f'Element {self.queue[self.front]} removed')
        self.front += 1
    def display(self):
        for i in range(self.front,self.rear+1):
            print(self.queue[i],end=' ')
        print()

q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)
q.display()
q.dequeue()
q.display()