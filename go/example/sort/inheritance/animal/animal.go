package animal

import (
    string "github.com/otterop/otterop/go/lang/string"
)


type Animal struct {
    word *string.String
}




func NewAnimal(word *string.String) *Animal {
    this := new(Animal)
    this.word = word
    return this
}

func (this *Animal) Act() *string.String {
    return this.word
}

func (this *Animal) Species() *string.String {
    return string.Wrap(string.Literal("unknown"))
}