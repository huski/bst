#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

class BinarySearchTree {
public:
    struct Node {
        int value;
        Node *left;
        Node *right;

        Node(int value) {
            this->value = value;
            left = NULL;
            right = NULL;
        }
    };

private:
    Node *root;

private:
    void destroy(Node *node);
    void remove(Node *node, Node *parent);
    static void printInorder(Node *node);
    static void printPreorder(Node *node);
    static void printPostorder(Node *node);
    static void print(Node *node);
    static void print(const std::string &s);
    static void println();

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    bool isEmpty() const;
    bool hasValue(int value) const;
    void insert(int value);
    void remove(int value);
    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;
    void printBreadthFirst() const;
};

#endif /* BINARYSEARCHTREE_H_ */
