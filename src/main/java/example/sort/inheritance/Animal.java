package example.sort.inheritance;

import example.sort.tree.Node;
import otterop.lang.String;

public class Animal {
    private String word;

    public Animal(String word) {
        this.word = word;
    }

    public String act() {
        return this.word;
    }

    public String species() {
        return String.wrap("unknown");
    }
}
