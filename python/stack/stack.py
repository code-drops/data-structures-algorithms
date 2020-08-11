class stack:
    def __init__(self):
        self.stack = []
    def push(self,x):
        if len(self.stack)>100:
            print('Stack overflow')
            return
        self.stack.append(x)
    def pop(self):
        if len(self.stack)==0:
            print('Stack underflow')
            return
        self.stack.pop()
    def peep(self):
        print(self.stack)

s = stack()
s.pop()
s.push(12)
s.push(52)
s.peep()
s.pop()
s.peep()