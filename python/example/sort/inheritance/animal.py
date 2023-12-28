from example.sort.tree.node import Node
from otterop.lang.string import String

class Animal:
    
    def __init__(self, word):
        self.word = word

    def act(self):
        return self.word

    def species(self):
        return String.wrap("unknown")
