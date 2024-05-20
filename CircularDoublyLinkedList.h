#include "iostream"

using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T value){
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template<typename T>
class CircularDoublyLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
public:

    CircularDoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;

    }

    T front(){
        return head->next->data;
    }

    T back(){
        return head->prev->data;
    }

    bool empty(){
        return head == nullptr;
    }

    void push_front(T value){
        Node<T>* newNode = new Node<T>(value);


        if(empty()){
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }else{
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            newNode->prev = head;
        }
    }

    void push_back(T value){
        Node<T>* newNode = new Node<T>(value);

        if(empty()){
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }else{
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void print(){
       auto temp = head->next;

       while(temp != head){
           cout<<temp->data<<"<=>";
           temp = temp->next;
       }
       cout<<endl;
    }

    T pop_front(){
        if(empty()){
            throw "The list is empty";
        }else{

            auto temp = head->next;
            T popElement = head->next->data;
            head->next = head->next->next;
            head->next->prev = head;
            delete temp;

            return popElement;
        }
    }

    T pop_back(){
        if(empty()){
            throw "The list is empty";
        }else{
            auto temp = head->prev;
            T popElement = head->data;
            head->prev = head->prev->prev;
            head->prev->next = head;
            return popElement;
        }
    }

    void insert(T value,int index){
        auto temp = head->next;
        int count = 0;

        while( temp != head){
            if(count == index){
                Node<T>* newNode = new Node<T>(value);
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev->next = newNode;
                temp->prev = newNode;
                break;
            }

            temp=temp->next;
            count++;
        }


    }

    void remove(T value){

    }

    T operator[](int index){
        auto temp = head->next;
        int count = 0;

        while(temp != head){
            if(count == index){
                return temp->data;
            }
            temp = temp->next;
            count++;
        }
    }




};
