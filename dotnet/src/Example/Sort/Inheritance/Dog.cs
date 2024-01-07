namespace Example.Sort.Inheritance
{
    public class Dog : Animal
    {
        private Otterop.Lang.String dogWord;
        public Dog() : base(Otterop.Lang.String.Wrap("I don't know"))
        {
            this.dogWord = Otterop.Lang.String.Wrap("bark");
        }

        public new Otterop.Lang.String Act()
        {
            base.Act();
            return this.dogWord;
        }

    }

}
