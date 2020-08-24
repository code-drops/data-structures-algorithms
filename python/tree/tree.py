class node:
    def __init__(self,x):
        self.left = None
        self.data = x
        self.right = None
class tree:
    def __init__(self):
        self.root = None
    def insert(self,x):
        newnode = node(x)
        if self.root==None:
            self.root = newnode
            return
        else:
            temp = self.root
            while True:
                if x<=temp.data:
                    if temp.left==None:
                        temp.left = newnode
                        return
                    else:
                        temp = temp.left
                else:
                    if temp.right == None:
                        temp.right = newnode
                        return
                    else:
                        temp = temp.right
    def preorder(self,root):
        if root!=None:
            print(root.data,end=' ')
            self.preorder(root.left)
            self.preorder(root.right)
    def inorder(self,root):
        if root!=None:
            self.inorder(root.left)
            print(root.data,end=' ')
            self.inorder(root.right)
    def postorder(self,root):
        if root!=None:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.data,end=' ')
    def search(self,x):
        temp = self.root
        while True:
            if temp == None:
                print('Not exists')
                return
            if temp.data == x:
                print('exists')
                return
            else:
                if temp.data > x:
                    temp = temp.left
                else:
                    temp = temp.right
    def minimum(self):
        if self.root==None:
            print('No root node')
            return
        else:
            temp = self.root
            while True:
                if temp.left == None:
                    print(f'Minimum : {temp.data}')
                    return
                else:
                    temp = temp.left
    def maximum(self):
        temp = self.root
        if temp==None:
            print('No root node')
            return
        else:
            while True:
                if temp.right==None:
                    print(f'Maximum : {temp.data}')
                    return
                else:
                    temp = temp.right
    def levelorder(self):
        queue = []
        temp = self.root
        queue.append(temp)
        while len(queue)!=0:
            current = queue.pop(0)
            print(f'{current.data}',end=' ')
            if current.left!=None:
                queue.append(current.left)
            if current.right!=None:
                queue.append(current.right)
    def iterative_Preorder(self):
        temp = self.root
        if temp==None:
            print('no root node')
            return
        else:
            stack = []
            stack.append(temp)
            while len(stack) != 0:
                temp = stack.pop()
                print(temp.data,end=' ')
                if temp.right!=None:
                    stack.append(temp.right)
                if temp.left != None:
                    stack.append(temp.left)
    def iterative_inorder(self):
        temp = self.root
        stack = []
        while True:
            while temp!=None:
                stack.append(temp)
                temp = temp.left
            if len(stack) == 0:
                break
            temp = stack.pop()
            print(f'{temp.data}',end=' ')
            temp = temp.right
    def deleteNode(self,root,x):
        if root==None:
            return root
        if root.data > x:
            root.left = self.deleteNode(root.left,x)
        elif root.data < x:
            root.right = self.deleteNode(root.right,x)
        else:
            if root.left == root.right == None:
                return None
            elif root.left == None:
                return root.right
            elif root.right == None:
                return root.left
            else:
                temp = root.right
                while temp.left!=None:
                    temp = temp.left
                root.data = temp.data
                root.right = self.deleteNode(root.right,temp.data)
        return root
    def size(self,root):
        if root==None:
            return 0
        else:
            return self.size(root.left)+self.size(root.right) + 1
    def height(self,root):
        if root==None:
            return -1
        else:
            return max(self.height(root.left),self.height(root.right))+1
    def maximumelement(self,root):
        if root==None:
            return 0
        else:
            return max(self.maximumelement(root.left),self.maximumelement(root.right),root.data)
    def identical(self,root1,root2):
        if root1 == root2 == None:
            return True
        else:
            if (root1==None and root2!=None) or (root1!=None and root2==None):
                return False
            else:
                return self.identical(root1.left,root2.left) and self.identical(root1.right,root2.right)
    def symmetric(self,root1,root2):
        if root1 == root2 == None:
            return True
        else:
            if root1==None or root2==None:
                return False
            else:
                return self.symmetric(root1.left,root1.right)

    def diameter(self,root):
        if root==None:
            return 0
        else:
            return max(self.height(root.left)+self.height(root.right)+1,self.diameter(root.left),self.diameter(root.right))
t = tree()
for i in [5,1,2,9,6,3]:
    t.insert(i)
t.preorder(t.root)
print()
t.inorder(t.root)
print()
t.postorder(t.root)
print()
t.search(10)
t.search(5)
t.minimum()
t.maximum()
t.levelorder()
t.iterative_Preorder()
t.iterative_inorder()
t.deleteNode(t.root,3)
print()
t.inorder(t.root)
print()
print(t.size(t.root))
print(t.height(t.root))
print(t.maximumelement(t.root))

t2 = tree()
for i in [5,1,2,6,3]:
    t2.insert(i)
print(t.identical(t.root,t2.root))
print(t.symmetric(t.root.left,t.root.right))
print(t.diameter(t.root))
