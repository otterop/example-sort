package inheritance

import (
    lang "github.com/otterop/otterop/go/lang"
)


type Animal struct {
    word *lang.String
}




func AnimalNew(word *lang.String) *Animal {
    this := new(Animal)
    this.word = word
    return this
}

func (this *Animal) Act() *lang.String {
    return this.word
}

func (this *Animal) Species() *lang.String {
    return lang.StringWrap(lang.StringLiteral("unknown"))
}