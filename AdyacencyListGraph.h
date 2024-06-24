#include <iostream>
using namespace std;

template<typename T>
class AdjacencyListGraph {
private:
    struct Node {
        T dest;
        Node* next;
        Node(T dest,Node* next){
            this->dest = dest;
            this->next = next;
        }
    };

    int V;
    Node** adjList; 

public:
    AdjacencyListGraph(int V) {
        this->V = V;
        adjList = new Node*[V]; 
        for (int i = 0; i < V; i++) {
            adjList[i] = nullptr;
        }
    }

    void addEdge(T start, T dest) {
        Node* newNode = new Node(dest, adjList[start]);
        adjList[start] = newNode;

        newNode = new Node(start, adjList[dest]);
        adjList[dest] = newNode;
    }

    void displayGraph() {
        cout << "Lista de Adyacencia" << endl;
        for (int i = 0; i < V; i++) {
            Node* temp = adjList[i];
            cout << "Vertex " << i + 1 << ":";
            while (temp) {
                cout << " -> " << temp->dest + 1;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~AdjacencyListGraph() { 
        
        for (int i = 0; i < V; i++) {
            Node* temp = adjList[i];
            while (temp) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjList;
    }
};