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

    Node* insertion_sort(Node* node){
        Node* result = nullptr;
        auto temp = node;

        while(temp != nullptr){
            auto next = temp->next;

            if(result == nullptr || result->data >= temp->data){
                temp->next = result;
                result = temp;
            }else{
                auto current = result;

                while(current->next != nullptr && current->next->data < temp->data){
                    current = current->next;
                }

                temp->next = current->next;
                current->next = temp;
            }

            temp = next;
        }

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

    Node* lista = new Node(4);
    lista->next =new Node(2);
    lista->next->next = new Node(1);
    lista->next->next->next = new Node(3);



    s1.print(lista);

    auto result = s1.insertion_sort(lista);

    s1.print(result);

}