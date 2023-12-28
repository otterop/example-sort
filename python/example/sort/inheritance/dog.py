from otterop.lang.string import String
from example.sort.inheritance.animal import Animal

class Dog(Animal):
    
    def __init__(self):
        super().__init__(String.wrap("I don't know"))
        self.dog_word = String.wrap("bark")

    def act(self):
        super().act()
        return self.dog_word
