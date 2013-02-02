#include <iostream>
#include <queue>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(NULL) {
}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::destroy(Node *node) {
    if (node == NULL) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void BinarySearchTree::remove(Node *node, Node *parent) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL && node->right != NULL) {
        // 2 children - get the left most value from the right child's side
        Node *leftMostParent = node;
        Node *leftMost = node->right;
        while (leftMost->left != NULL) {
            leftMostParent = leftMost;
            leftMost = leftMost->left;
        }
        node->value = leftMost->value;
        remove(leftMost, leftMostParent);
        return;
    }
    // no children or 1 child
    Node *temp = node->left;
    if (node->right != NULL) {
        temp = node->right;
    }
    if (parent == NULL) {
        root = temp;
    } else if (parent->left == node) {
        parent->left = temp;
    } else {
        parent->right = temp;
    }
    delete node;
}

bool BinarySearchTree::isEmpty() const {
    return (root == NULL);
}

bool BinarySearchTree::hasValue(int value) const {
    Node *node = root;
    while (node != NULL) {
        if (value == node->value) {
            return true;
        }
        if (value < node->value) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

void BinarySearchTree::insert(int value) {
    if (isEmpty()) {
        root = new Node(value);
        return;
    }
    Node *parent = NULL;
    Node *node = root;
    while (node != NULL) {
        if (value == node->value) {
            return;
        }
        parent = node;
        if (value < node->value) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    Node *newNode = new Node(value);
    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void BinarySearchTree::remove(int value) {
    if (isEmpty()) {
        return;
    }
    Node *parent = NULL;
    Node *node = root;
    while (node != NULL) {
        if (value == node->value) {
            break;
        }
        parent = node;
        if (value < node->value) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    remove(node, parent);
}

void BinarySearchTree::printInorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    print(node);
    printInorder(node->right);
}

void BinarySearchTree::printPreorder(Node *node) {
    if (node == NULL) {
        return;
    }
    print(node);
    printPreorder(node->left);
    printPreorder(node->right);
}

void BinarySearchTree::printPostorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    print(node);
}

void BinarySearchTree::print(Node *node) {
    if (node == NULL) {
        return;
    }
    std::cout << node->value << " ";
}

void BinarySearchTree::print(const std::string &s) {
    std::cout << s;
}

void BinarySearchTree::println() {
    std::cout << std::endl;
}

void BinarySearchTree::printInorder() const {
    print("In-order     : ");
    printInorder(root);
    println();
}

void BinarySearchTree::printPreorder() const {
    print("Pre-order    : ");
    printPreorder(root);
    println();
}

void BinarySearchTree::printPostorder() const {
    print("Post-order   : ");
    printPostorder(root);
    println();
}

void BinarySearchTree::printBreadthFirst() const {
    print("Breadth-first: ");
    if (isEmpty()) {
        println();
        return;
    }
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
        print(node);
    }
    println();
}
