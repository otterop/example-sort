package example.sort.inheritance;

import otterop.lang.String;

public class Dog extends Animal {
    private String dogWord;

    public Dog() {
        super(String.wrap("I don't know"));
        this.dogWord = String.wrap("bark");
    }

    public String act() {
        super.act();
        return this.dogWord;
    }
}
