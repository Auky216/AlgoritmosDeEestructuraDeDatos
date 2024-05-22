#include "iostream"

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int value){
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
        this->child = nullptr;
    }
};

class Solution{
public:

    Solution(){}

    Node* sol(Node* head){
        auto temp = head;
        auto temp2 = head;

        while(temp != nullptr){
            if(temp->child != nullptr){
                temp2->next = temp->child;
                temp = temp2->next;
            }
            temp2 = temp2->next;
            temp = temp->next;
        }

        return head;
    }

    void print(Node* node){
        auto temp = node;

        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<endl;
    }
};

int main() {
    Node *lista1 = new Node(1);
    lista1->next = new Node(2);
    lista1->next->next = new Node(3); // child
    lista1->next->next->next = new Node(4);
    lista1->next->next->next->next = new Node(5);
    lista1->next->next->next->next->next = new Node(6);

    Node *lista2 = new Node(7);
    lista2->next = new Node(8); // child
    lista2->next->next = new Node(9);
    lista2->next->next->next = new Node(10);

    Node* lista3 = new Node(11);
    lista3->next = new Node(12);

    lista1->next->next->child = lista2;
    lista2->next = lista3;

    Solution s1;

    auto result = s1.sol(lista1);
    s1.print(result);
}