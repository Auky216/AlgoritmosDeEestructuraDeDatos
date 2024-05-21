#include "iostream"

using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Solution{
public:
    Solution(){}

    void push_front(Node* &node,int value){

        auto temp = new Node(value);
        temp->next = node;
        node = temp;
    }

    Node* sol(Node* node,int left,int right){
        auto temp = node;
        int cont = 1;

        Node* between = nullptr;
        Node* end= nullptr;

        while(temp != nullptr){
            if(cont >= left && cont <= right) {
                push_front(between, temp->data);
            }
            if(right == cont){
                end = temp->next;
            }

            temp = temp->next;
            cont++;
        }



        temp = node;
        cont = 1;


        while(temp != nullptr){
            if(cont == left-1){


                temp->next = between;

            }
            if(cont == right){
                temp->next = end;
            }

            temp = temp->next;

            cont++;
        }


        return node;




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


int main(){

    Solution s1;

    Node* lista = new Node(1);
    lista->next =new Node(2);
    lista->next->next = new Node(3);
    lista->next->next->next = new Node(4);
    lista->next->next->next->next = new Node(5);



    s1.print(lista);

    auto result = s1.sol(lista,2,4);

    s1.print(result);

}