#include "AVL.h"

int main(){
    AVL<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);

    cout<<tree.getPostOrder()<<endl;
    cout<<tree.height()<<endl;

    tree.remove(6);
    cout<<tree.height()<<endl;



}