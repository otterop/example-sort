namespace Example.Sort.Tree.Pure
{
    public class Node
    {
        private Example.Sort.Tree.Node otterop;

        private Node(Example.Sort.Tree.Node wrapped)
        {
            this.otterop = wrapped;
        }
        public Node(int value, Example.Sort.Tree.Pure.Node[] children)
        {
            var _childrenArray = new Example.Sort.Tree.Node[children.Count()];
            for (var i = 0; i < children.Count(); i++)
            {
                _childrenArray[i] = children[i].unwrap();
            }
            var _children = Otterop.Lang.Array.Wrap(_childrenArray);
            this.otterop = new Example.Sort.Tree.Node(value, _children);
        }

        public int Value()
        {
            var retOtterop = otterop.Value();
            var ret = retOtterop;
            return ret;
        }

        public Example.Sort.Tree.Pure.Node Child(int i)
        {
            var retOtterop = otterop.Child(i);
            if (retOtterop == this.otterop) return this;
            var ret = Example.Sort.Tree.Pure.Node.wrap(retOtterop);
            return ret;
        }

        public Example.Sort.Tree.Pure.Node[] Children()
        {
            var retOtterop = otterop.Children();
            var ret = new Example.Sort.Tree.Pure.Node[retOtterop.Size()];
            for (var i = 0; i < retOtterop.Size(); i++)
            {
                var retI = retOtterop.Get(i);
                if (retI == this.otterop)
                {
                    ret[i] = this;
                    continue;
                }
                ret[i] = Example.Sort.Tree.Pure.Node.wrap(retI);
            }
            return ret;
        }

        public Example.Sort.Tree.Node unwrap()
        {
            return this.otterop;
        }

        public static Example.Sort.Tree.Pure.Node wrap(Example.Sort.Tree.Node wrapped)
        {
            return new Example.Sort.Tree.Pure.Node(wrapped);
        }
    }

}
