from otterop.lang.array import Array

class Node:
        
    def __init__(self, value, children):
        self._value = value
        self._children = children

    def value(self):
        return self._value

    def child(self, i):
        children = self._children
        return children.get(i)

    def children(self):
        return self._children
