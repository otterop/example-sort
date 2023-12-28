namespace Example.Sort.Inheritance
{
    public class Animal
    {
        private Otterop.Lang.String word;
        public Animal(Otterop.Lang.String word)
        {
            this.word = word;
        }

        public Otterop.Lang.String Act()
        {
            return this.word;
        }

        public Otterop.Lang.String Species()
        {
            return Otterop.Lang.String.Wrap("unknown");
        }

    }

}
