#include "BinarySearchTree.h"

int main(){
    BST<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(35);
    tree.insert(42);

    cout<<tree.getPostOrder()<<endl;
    cout<<tree.height()<<endl;
    cout<<tree.size()<<endl;
}