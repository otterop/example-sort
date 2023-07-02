from otterop.lang.array import Array

class Node:
    
    def __init__(self, children):
        self.children = children

    def child(self, i):
        children = self.children
        return children.get(i)

    def children(self):
        return self.children
