#include "iostream"

using namespace std;

struct Node{
    string data;
    int cont;
    Node* next;
    Node* prev;

    Node(string value){
        this->data = value;
        this->cont = 1;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class AllOne {
private:
    Node* head;
    Node* tail;
public :
    AllOne () {
    this->head = nullptr;
    this->tail = nullptr;
    }
    void inc ( string key ) {
        Node* newNode = new Node(key);
        if(head == nullptr){
            head = newNode;
            tail = newNode;

        }else{
            auto temp = head;
            bool find = false;
            while(temp != nullptr){
                if(key == temp->data){
                    temp->cont ++;
                    find = true;
                    break;

                }
                temp = temp->next;


            }

            if(!find){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

        }



    }
    void dec ( string key ) {
        if(head == nullptr){
            head = new Node(key);
            tail = new Node(key);
        }else{

            bool exist = false;

            if(head->next == nullptr){
                if(head->data == key){
                    delete head;
                    delete tail;
                    exist = true;
                }
            }else{
                auto temp = head;
                cout<<"aaaaaaa"<<endl;
                while(temp->next->next != nullptr){
                    cout<<temp->data<<endl;
                    if(temp->next->data == key){
                        cout<<"Adrian 2"<<endl;
                        if(temp->next->cont == 0){
                            auto deleteNode = temp->next;
                            temp->next->next->prev = temp;
                            temp->next = temp->next->next;
                            delete deleteNode;
                        }else{
                            temp->next->cont -= 1;
                            cout<<"Adrian"<<endl;
                        }
                        exist = true;
                        break;
                    }

                    temp = temp->next;
                }
            }




        }
    }
    string getMaxKey () {
        auto temp = head;
        Node* max = head;

        if(head == nullptr){
            return "";
        }

        while(temp != nullptr){
            if(max->cont < temp->cont){
                max = temp;
            }
            temp = temp->next;
        }

        return max->data;
    }
    string getMinKey () {
        auto temp = head;
        Node* min = head;

        if(head == nullptr){
            return "";
        }

        while(temp != nullptr){
            if(min->cont > temp->cont){
                min = temp;
            }
            temp = temp->next;
        }

        return min->data;
    }

    void print(){
        auto temp = head;

        while(temp != nullptr){
            cout<<"string: "<<temp->data<<" count: "<<temp->cont<<" -> ";
            temp = temp->next;
        }

        cout<<endl;
    }
};

int main(){

    AllOne lista;

    lista.inc("hola");
    lista.inc("hola");
    lista.inc("adios");
    lista.inc("perra");
    lista.inc("perra");
    lista.inc("perra");
    lista.inc("perra");


    lista.print();
    cout<<lista.getMaxKey()<<endl;
    cout<<lista.getMinKey()<<endl;

    lista.dec("hola");

    lista.print();

}

//falta el mec - eliminar