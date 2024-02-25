from otterop.lang.array import Array

class Node:
        
    def __init__(self, value, children):
        self.__value = value
        self.__children = children

    def value(self):
        return self.__value

    def child(self, i):
        children = self.__children
        return children.get(i)

    def children(self):
        return self.__children
