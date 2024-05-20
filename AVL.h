#include "iostream"

using namespace std;

template<typename T>
class AVL{
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

    AVL(){
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

    T succesor(T value){
        return succesor(head,value);
    }

    T predecessor(T value){
        return predecessor(head,value);
    }

    void remove(T value){
        remove(head,value);
    }


private:

    int heightNode(Node* node){
        if(node == nullptr){
            return -1;
        }
        return 1 + max(height(node->left), height((node->right)));
    }

    int hb(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return heightNode(node->left) - heightNode(node->right);

    }

    void R_Left(Node* &node){
        auto temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
    }

    void R_Right(Node* &node){
        auto temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
    }

    void R_Left_Right(Node* &node){
        R_Left(node->left);
        R_Right(node);
    }

    void R_Right_Left(Node* &node){
        R_Right(node->right);
        R_Left(node);
    }

    void balancer(Node* &node){
        if(hb(node) >= 2){
            if(hb(node->left) <= -1){
                R_Left_Right(node);
            }
            else{
                R_Right(node);
            }
        }
        else if(hb(node) <= -2){
            if(hb(node->right) >= -1){
                R_Right_Left(node);
            }
            else{
                R_Left(node);
            }
        }
    }

    Node* maxNode(Node* node){
        if(node->right == nullptr) {
            return node;
        }

        return maxNode(node->right);
    }
    Node* predecessorNode(Node* node, T value){
        if(node == nullptr){
            return nullptr;
        }

        if(value == node->data){
            if(node->left != nullptr){
                return maxNode(node->left);
            }
        }

        if(value > node->data){
            return predecessorNode(node->right,value);
        }

        if(value < node->data){
            return predecessorNode(node->left,value);
        }
    }

    void remove(Node* &node,T value){

        if(node == nullptr){
            return;
        }

        if(value > node->data){
            remove(node->right,value);
        }

        if(value < node->data){
            remove(node->left,value);
        }

        if(value == node->data){
            if(node->left == nullptr && node->right == nullptr){
                delete node;
                node = nullptr;
            }

            else if(node->left == nullptr){
                Node* temp = node;
                node = node->right;
                delete temp;
            }

            else if(node->right == nullptr){
                Node* temp = node;
                node = node->left;
                delete temp;
            }

            else{
                Node* temp = maxNode(node->left);
                node->data = temp->data;
                remove(node->left,temp->data);
            }
            balancer(node);
        }




    }

    T succesor(Node* node, T value){
        if(node == nullptr){
            return -1;
        }

        if(node->data == value){
            if(node->right != nullptr){
                return minValue(node->right);
            }
        }

        if(value > node->data){
            return succesor(node->right,value);
        }

        if(value < node->data){
            return succesor(node->left,value);
        }

        return -1;
    }

    T predecessor(Node* node,T value){
        if(node == nullptr){
            return -1;
        }

        if(node->data == value){
            if(node->left != nullptr){
                return maxValue(node->left);
            }
        }

        if(value > node->data){
            return predecessor(node->right,value);
        }

        if(value < node->data){
            return predecessor(node->left,value);
        }

        return -1;
    }


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

        balancer(node);
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