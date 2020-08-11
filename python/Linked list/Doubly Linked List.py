class node:
    def __init__(self,x):
        self.data = x
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insertBeg(self,x):
        newnode = node(x)
        if self.head!=None:
            newnode.next = self.head
            self.head.prev = newnode
        self.head = newnode

    def insertEnd(self,x):
        newnode = node(x)
        if self.head==None:
            self.head = newnode
            return
        temp = self.head
        while temp.next!=None:
            temp = temp.next
        temp.next = newnode
        newnode.prev = temp

    def insertMid(self,x,pos):
        newnode = node(x)
        if self.head==None:
            self.head = newnode
            return
        temp = self.head
        count = 0
        while count<pos-1:
            temp = temp.next
            count += 1
        newnode.next = temp.next
        temp.next = newnode
        newnode.prev = temp
        newnode.next.prev = newnode

    def deleteBeg(self):
        temp = self.head
        self.head = self.head.next
        temp.next = None
        self.head.prev = None

    def deleteEnd(self):
        temp =self.head
        while temp.next.next!=None:
            temp = temp.next
        temp.next.prev = None
        temp.next = None

    def deleteMid(self,pos):
        temp = self.head
        count = 0
        while count<pos-1:
            temp = temp.next
            count += 1
        temp2 = temp.next
        temp3 = temp2.next
        temp.next = temp3
        temp3.prev = temp
        temp2.prev = temp2.next = None

    def disp(self):
        temp = self.head
        while temp.next!=None:
            print(temp.data,'->',end=' ')
            temp = temp.next
        print(temp.data)

    def revDisp(self):
        temp = self.head
        while temp.next != None:
            temp = temp.next
        while temp!=self.head:
            print(temp.data,'->',end=' ')
            temp = temp.prev
        print(temp.data)

l = DoublyLinkedList()
l.insertBeg(10)
l.insertBeg(15)
l.insertEnd(13)
l.insertBeg(12)
l.insertMid(5,2)
l.disp()
l.deleteBeg()
l.deleteEnd()
l.deleteMid(1)
l.disp()
l.revDisp()