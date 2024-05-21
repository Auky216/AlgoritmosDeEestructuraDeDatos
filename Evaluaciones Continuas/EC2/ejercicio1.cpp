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

    void reverse(Node *&node){
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



    Node* sol(Node* node,int num){
        auto result = node;
        reverse(result);

        auto temp = result;
        int cont = 1;

        while(temp != nullptr){
            if(cont == num-1){
                temp->next = temp->next->next;
                break;
            }

            cont ++;
            temp = temp->next;
        }

        reverse(result);



        return result;





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

    auto result = s1.sol(lista,2);

    s1.print(result);

}