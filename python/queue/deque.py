class Deque():
    def __init__(self):
        self.max = 100
        self.queue = [0]*self.max
        self.front = 0
        self.rear = -1

    def addRear(self,x):
        if self.rear==self.max:
            print('No more elements can be added')
            return
        self.rear += 1
        self.queue[self.rear] = x
        print(f'Element {x} got inserted at rear')

    def addFront(self,x):
        if self.rear==self.max:
            print('No more elements can be added')
            return
        self.front -= 1
        self.queue[self.front] = x
        print(f'Element {x} got inserted at front')

    def removeFront(self):
        if self.rear==-1 or self.front>self.rear:
            print('No element to be remove')
            return
        print(f'Element {self.queue[self.front]} removed from front')
        self.front += 1

    def removeRear(self):
        if self.rear==-1 or self.front>self.rear:
            print('No element to be remove')
            return
        print(f'Element {self.queue[self.rear]} removed from rear')
        self.rear -= 1

    def display(self):
        for i in range(self.front,self.rear+1):
            print(self.queue[i],end=' ')
        print()

d = Deque()
d.addRear(8)
d.addRear(5)
d.addFront(7)
d.addFront(10)
d.addRear(11)
d.display()
d.removeRear()
d.removeFront()
d.display()
d.addFront(55)
d.addRear(45)
d.display()