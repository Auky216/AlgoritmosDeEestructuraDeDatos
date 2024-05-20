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
class IteratorDoublyLinkedList{
private:
    Node<T>* current;
public:
    IteratorDoublyLinkedList(Node<T>* node){
        this->current = node;
    }

    IteratorDoublyLinkedList& operator++(){
        if(current != nullptr){
            current = current->next;
        }
        return *this;
    }

    IteratorDoublyLinkedList& operator--(){
        if(current != nullptr){
            current = current->prev;
        }

        return *this;

    }

    bool operator!=(IteratorDoublyLinkedList other){
        return this->current != other.current;
    }


    T operator*(){
        return current->data;
    }

};

template<typename T>
class DoublyLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;

public:

    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    T front(){ // O(1)
        return head->data;
    }

    T back(){ // O(1)
        return tail->data;
    }

    bool empty(){ // O(1)
        return head == nullptr;
    }

    void push_front(T value){ // O(1)
        Node<T>* newNode = new Node<T>(value);

        if(empty()){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T value){ // O(1)

        Node<T>* newNode = new Node<T>(value);

        if(empty()){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }


    }

    T pop_front(){ // O(1)
        if(empty()){
            throw "The list is empty";
        }else{
            auto temp = head;
            T popElement = head->data;
            head = head->next;
            head->prev = nullptr;
            delete temp;

            return popElement;
        }
    }

    T pop_back(){ // O(1)
        if(empty()){
            throw "The listt is empty";
        }else{
            auto temp = tail;
            T popElement = tail->data;
            tail = tail->prev;
            tail->next = nullptr;
            delete tail;

            return popElement;
        }
    }

    void insert(T value,int index){ // O(n)
        auto temp = head;
        int count = 0;

        while(temp != nullptr){
            if(index == count){
                Node<T>* newNode = new Node<T>(value);
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->next->prev = newNode;
                break;
            }
            temp = temp->next;
            count++;
        }
    }

    T remove(int index){ // O(n)
        auto temp = head;
        auto count = 0;

        while(temp != nullptr){
            if(count == index){
                auto temp2 = temp;
                temp-> prev->next = temp->next;
                temp->next->prev = temp->prev;
                T removeElement = temp->data;
                delete temp2;
            }
            temp = temp->next;
            count++;
        }
    }

    T operator[](int index){ // O(n)
        auto temp = head;
        int count = 0;

        while (temp != nullptr){
            if(count == index){
                return temp->data;
            }
            temp = temp->next;
            count++;
        }
    }

    int size(){ // O(n)
        auto temp = head;
        int count = 0;

        while(temp != nullptr){
            count++;
            temp = temp->next;
        }

        return count;
    }

    void clear(){ // O(n)

        while(head != nullptr){
            auto temp = head;
            head = head->next;
            delete temp;
        }

    }

    void reverse(){ // O(n)
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void print(){ // O(n)
        auto temp = head;

        while(temp != nullptr){
            cout<<temp->data<<"<=>";
            temp = temp->next;
        }

        cout<<endl;
    }

public:

    typedef IteratorDoublyLinkedList<T> iterator;
    iterator begin(){
        return iterator(head);
    }
    iterator end(){
        return iterator(nullptr);
    }


};


