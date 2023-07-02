namespace Example.Sort.Tree
{
    public class Node
    {
        private Otterop.Lang.Array<Node> children;
        public Node(Otterop.Lang.Array<Node> children)
        {
            this.children = children;
        }

        public Node Child(int i)
        {
            Otterop.Lang.Array<Node> children = this.children;
            return children.Get(i);
        }

        public Otterop.Lang.Array<Node> Children()
        {
            return this.children;
        }

    }

}
