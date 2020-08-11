class node:
    def __init__(self,x):
        self.data = x
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insertBeg(self,x):
        temp = node(x)
        temp.next = self.head
        self.head = temp

    def insertEnd(self,x):
        temp = self.head
        while temp.next!=None:
            temp = temp.next
        temp.next = node(x)

    def insertMid(self,x,pos):
        temp = self.head
        count = 0
        while count<pos-1:
            temp = temp.next
            count += 1
        temp2 = node(x)
        temp2.next = temp.next
        temp.next = temp2

    def deleteBeg(self):
        self.head = self.head.next

    def deleteEnd(self):
        temp =self.head
        while temp.next.next!=None:
            temp = temp.next
        temp.next = None

    def deleteMid(self,pos):
        temp = self.head
        count = 0
        while count<pos-1:
            temp = temp.next
            count += 1
        temp.next = temp.next.next

    def disp(self):
        temp = self.head
        while temp.next!=None:
            print(temp.data,'->',end=' ')
            temp = temp.next
        print(temp.data)

l = SinglyLinkedList()
l.insertBeg(10)
l.insertBeg(15)
l.insertEnd(13)
l.insertBeg(12)
l.insertMid(5,2)
l.deleteBeg()
l.deleteEnd()
l.deleteMid(2)
l.disp()
