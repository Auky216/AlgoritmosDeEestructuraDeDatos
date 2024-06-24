#include <iostream>
using namespace std;

template<typename T>
class AdyacencyMatrixGraph {
private:
    int V;
    T** adjMatrix; 
public:
    AdyacencyMatrixGraph(int V) {
        this->V = V;
        adjMatrix = new T*[V]; 
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new T[V]; 
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0; 
            }
        }
    }

    void addEdge(T start, T dest) {
        adjMatrix[start][dest] = 1;
        adjMatrix[dest][start] = 1;
    }

    void displayGraph() {
        cout << "Matriz de Adyacencia" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~AdyacencyMatrixGraph() {
        for (int i = 0; i < V; i++) {
            delete[] adjMatrix[i]; 
        }
        delete[] adjMatrix; 
    }
};

