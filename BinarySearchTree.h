#include "iostream"

using namespace std;

template<typename T>
class BST{
private:
    struct Node{
        T data;
        Node* left;
        Node* right;

        Node(T value){
            this->data = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* head;

public:

    BST(){
        this->head = nullptr;
    }

    void insert(T value){
        insert(head,value);
    }

    bool find(T value){
        return find(head,value);
    }

    string getInOrder(){
        return getInOrder(head);

    }

    string getPreOrder(){
       return getPreOrder(head);
    }

    string getPostOrder(){
        return getPostOrder(head);
    }


    int height(){
        return height(head);
    }

    int size(){
        return size(head);
    }


private:
    int size(Node* node){
        if(node == nullptr){
            return 0;
        }

        return 1 + size(node->left) + size(node->right);
    }

    T minValue(Node* node){

        if(node->left == nullptr){
            return node->data;
        }

        return minValue(node->left);
    }

    T maxValue(Node* node){

        if(node->right == nullptr){
            return node->data;
        }

        return maxValue(node->right);
    }

    bool find(Node* node,T value){

        if(node == nullptr){
            return false;
        }

        if(node->data == value){
            return true;
        }

        if(value > node->data){
            return find(node->right,value);
        }

        if(value < node->data){
            return find(node->left,value);
        }

        return false;
    }

    int height(Node* node){


        if(node == nullptr){
            return -1;
        }

        return 1 + max(height(node->left),height(node->right));
    }

    void insert(Node* &node, T value){
        if(node == nullptr){
            node = new Node(value);
        }

        else if(value > node->data){
            insert(node->right,value);
        }

        else if(value < node->data){
            insert(node->left,value);
        }
    }

    string getInOrder(Node* node){

        if(node == nullptr){
            return "";
        }

        return getInOrder(node->left) + to_string(node->data) + " " + getInOrder(node->right);
    }

    string getPreOrder(Node* node){

        if(node == nullptr){
            return "";
        }

        return to_string(node->data) + " " + getPreOrder(node->left) + getPreOrder(node->right);
    }

    string getPostOrder(Node* node){

        if(node == nullptr){
            return "";
        }

        return getPostOrder(node->left) + getPostOrder(node->right) + to_string(node->data) + " ";
    }


};