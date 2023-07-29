namespace Example.Sort.Tree
{
    public class Node
    {
        private Otterop.Lang.Array<Node> _children;
        private int _value;
        public Node(int value, Otterop.Lang.Array<Node> children)
        {
            this._value = value;
            this._children = children;
        }

        public int Value()
        {
            return this._value;
        }

        public Node Child(int i)
        {
            Otterop.Lang.Array<Node> children = this._children;
            return children.Get(i);
        }

        public Otterop.Lang.Array<Node> Children()
        {
            return this._children;
        }

    }

}
