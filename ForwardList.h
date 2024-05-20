#include <iostream>

using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;

    Node(T value){
        this->data = value;
        this->next = nullptr;
    }
};

template<typename T>
class ForwardListIterator{
private:

    Node<T>* current_node;

public:

    ForwardListIterator(Node<T>* node) : current_node(node) {}

    ForwardListIterator& operator++(){
        if (current_node != nullptr)
            current_node = current_node->next;
        return *this;
    }

    bool operator!=(const ForwardListIterator& other) const {
        return current_node != other.current_node;
    }

    T operator*() const {
        return current_node->data;
    }

};

template<typename T>
class ForwardList{
private:

    Node<T>* head;


public:

    ForwardList(){
        this->head = nullptr;
    }

    T front(){ // O(1)
        return head->data;
    }

    T back(){ // O(n)
        auto temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        return temp->data;
    }

    bool empty(){
        return head == nullptr;
    }

    void push_front(T value){
        Node<T>* newNode = new Node<T>(value);

        newNode->next = head;
        head = newNode;
    }

    void push_back(T value){ // O(n)
        Node<T>* newNode = new Node<T>(value);

        if(head == nullptr){
            head = newNode;
        }else{
            auto temp = head;

            while(temp->next != nullptr){
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    T pop_front(T value){ //O(1)
        if(empty()){
            throw "The list is empty";
        }else{
            auto temp = head;
            T popValue = head->data;
            head = head->next;
            delete temp;

            return popValue;
        }
    }

    T pop_back(T value){ // O(n)
        if(empty()){
            throw "The list is empty";
        }
        else if(head->next == nullptr){
            T popValue = head->data;
            delete head;
            head = nullptr;
            return popValue;
        }
        else{
            auto temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            T popValue = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
            return popValue;
        }
    }

    T operator[](T index){ //O(n)
        auto temp = head;
        int cont = 0;

        while(temp != nullptr){
            if(index == cont){
                return temp->data;
            }

            temp = temp->next;
        }
    }

    int size(){ //O(n)
        auto temp = head;
        int cont = 0;

        while(temp != nullptr){
            temp = temp->next;
            cont++;
        }

        return cont;
    }

    void clear(){ //O(n)
        while(head != nullptr){
            auto temp = head;
            head = head->next;
            delete temp;
        }
    }

    void reverse(){ //O(n)
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void print(){ //O(n)
        auto temp = head;

        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }

public:
    typedef ForwardListIterator<T> iterator;

    iterator begin(){
        return iterator(head);
    }

    iterator end(){
        return iterator(nullptr);
    }

};

