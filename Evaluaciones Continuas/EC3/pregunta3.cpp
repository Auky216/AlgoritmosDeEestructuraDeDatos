#include "iostream"

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = nullptr;
    }
};

class Solution{
public:

    Solution(){}

    void print(Node* node){
        auto temp = node;

        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void push_front(Node* &node,int value){
        Node* newNode = new Node(value);
        newNode->next = node;
        node = newNode;
    }

    void revese(Node* &node){

        Node* prev = nullptr;
        Node* current = node;
        Node* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        node = prev;
    }


    Node* sol(Node* node1,Node* node2){
        revese(node1);
        revese(node2);
        Node* result = nullptr;

        auto temp1 = node1;
        auto temp2 = node2;

        while(temp1 != nullptr){
            push_front(result,temp1->data);
            temp1 = temp1->next;
        }

        auto tempResult = result;
        int sum = 0;

        while(temp2 != nullptr){
            sum = result->data + temp2->data;

            if(sum > 9){
                result->data = sum % 10;
                if(result->next != nullptr){
                    result->next->data ++;
                }else{
                    result->next = new Node(1);
                }
            }

            temp2 = temp2->next;
        }

        return  result;


    }
};


int main(){

    Node* lista1 = new Node(7);
    lista1->next = new Node(2);
    lista1->next->next = new Node(4);
    lista1->next->next->next = new Node(3);

    Node* lista2 = new Node(5);
    lista2->next = new Node(6);
    lista2->next->next = new Node(4);

    Solution s1;
    auto result = s1.sol(lista1,lista2);

    s1.print(result);


}

// falta implementar