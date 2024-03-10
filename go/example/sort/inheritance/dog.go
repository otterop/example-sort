package inheritance

import (
    lang "github.com/otterop/otterop/go/lang"
)


type Dog struct {
    *Animal
    dogWord *lang.String
}




func DogNew() *Dog {
    this := new(Dog)
    this.Animal = AnimalNew(lang.StringWrap(lang.StringLiteral("I don't know")))
    this.dogWord = lang.StringWrap(lang.StringLiteral("bark"))
    return this
}

func (this *Dog) Act() *lang.String {
    this.Animal.Act()
    return this.dogWord
}