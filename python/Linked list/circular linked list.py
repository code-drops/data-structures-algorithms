class node:
    def __init__(self,x):
        self.data = x
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insertBeg(self,x):
        newnode = node(x)
        if self.head == None:
            self.head = newnode
            self.head.next = self.head
            return
        temp = self.head
        while temp.next!=self.head:
            temp = temp.next
        newnode.next = self.head
        self.head = newnode
        temp.next = self.head

    def insertEnd(self,x):
        newnode = node(x)
        if self.head == None:
            self.head = newnode
            self.head.next = self.head
            return
        temp = self.head
        while temp.next != self.head:
            temp = temp.next
        temp.next = newnode
        newnode.next = self.head

    def insertMid(self,x,pos):
        newnode = node(x)
        if self.head == None:
            self.head = newnode
            self.head.next = self.head
            return
        count = 0
        temp = self.head
        while count < pos - 1:
            temp = temp.next
            count += 1
        newnode.next = temp.next
        temp.next = newnode

    def deleteBeg(self):
        temp = self.head
        while temp.next != self.head:
            temp = temp.next
        self.head = self.head.next
        temp.next = self.head

    def deleteEnd(self):
        temp = self.head
        while temp.next.next!= self.head:
            temp = temp.next
        temp.next = self.head

    def deleteMid(self,pos):
        temp = self.head
        count = 0
        while count < pos - 1:
            temp = temp.next
            count += 1
        temp.next = temp.next.next

    def disp(self):
        temp = self.head
        while temp.next!=self.head:
            print(temp.data,'->',end=' ')
            temp = temp.next
        print(temp.data)

l = CircularLinkedList()
l.insertBeg(10)
l.disp()
l.insertBeg(15)
l.disp()
l.insertEnd(13)
l.disp()
l.insertBeg(12)
l.disp()
l.insertMid(5,2)
l.disp()
l.deleteBeg()
l.disp()
l.deleteEnd()
l.disp()
l.deleteMid(1)
l.disp()