#include <cerrno>
#include <cstdlib>
#include <string>
#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, char *argv[]) {
    BinarySearchTree bst;
    if (argc > 1) {
        // insert values from command line
        char *p;
        for (int i = 1; i < argc; i++) {
            int value = strtol(argv[i], &p, 0);
            if (*p != '\0' || errno != 0) {
                std::cerr << "Bad input value: " << argv[i] << std::endl;
                return 1;
            }
            bst.insert(value);
        }
    } else {
        // no command line values, insert some predefined values
        int values[] = { 99, 84, 87, 78, 16, 94, 36, 87, 93, 50, 22, 40 };
        int size = sizeof(values) / sizeof(int);
        for (int i = 0; i < size; i++) {
            bst.insert(values[i]);
        }
        bst.printInorder();
        bst.printPreorder();
        bst.printPostorder();
        bst.printBreadthFirst();
        bst.remove(99);
        bst.remove(16);
        bst.remove(40);
    }
    bst.printInorder();
    bst.printPreorder();
    bst.printPostorder();
    bst.printBreadthFirst();
    return 0;
}
