template <typename T>
class BinaryTree {
  public:
    BinaryNode<T> *root;

    BinaryTree() {root = nullptr;}
    BinaryTree(const T &d, BinaryTree<T> &lt, BinaryTree &rt) :
    {
        root = new BinaryNode<T>(d, lt.root, rt.root);
    }

    bool is_empty() const {return (!root);}
    make_tree(const T &d, BinaryTree<T> &lt, BinaryTree &rt) :
    {
        root = new BinaryNode<T>(d, lt.root, rt.root);
    }
    break_tree(T &d, BinaryTree<T> &lt, BinaryTree<T> &rt) {
        d = root.data;
        lt.root = root.left;
        rt.root = root.right;
        delete root;
        root = nullptr;
    }

  private:
    struct BinaryNode {
        T data;
        BinaryNode<T> *left;
        BinaryNode<T> *right;

        BinaryNode(T &d, BinaryNode<T> *lt = nullptr,
                   BinaryNode<T> *rt = nullptr) :
            data{d}, left{lt}, right{rt}
        {}
        BinaryNode(T &&d, BinaryNode<T> *lt = nullptr,
                   BinaryNode<T> *rt = nullptr) :
            data{std::move(d)}, left{lt}, right{rt}
        {}
    };


};

