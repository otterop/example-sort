package dog

import (
    string "github.com/otterop/otterop/go/lang/string"
    "github.com/otterop/example-sort/go/example/sort/inheritance/animal"
)

type Dog struct {
    *animal.Animal
    dogWord *string.String
}




func NewDog() *Dog {
    this := new(Dog)
    this.Animal = animal.NewAnimal(string.Wrap(string.Literal("I don't know")))
    this.dogWord = string.Wrap(string.Literal("bark"))
    return this
}

func (this *Dog) Act() *string.String {
    this.Animal.Act()
    return this.dogWord
}