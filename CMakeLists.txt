cmake_minimum_required(VERSION 3.25)
project(Algoritmos)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algoritmos
        main.cpp ForwardList.h DoublyLinkedList.h CircularDoublyLinkedList.h HashTable.h BinarySearchTree.h AVL.h)
