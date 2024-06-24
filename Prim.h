#include "iostream"
#include "vector"
#include <queue>
using namespace std;

typedef pair<int, int> Edge; 

vector<Edge> Prim(vector<vector<Edge>> graph, int start){
    int n = graph.size(); //numeros de vertices
    vector<bool> visited(n,false); //vertices visittados

    vector<Edge> result; //vector donde ira el recorrido
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap; //Almacena en tipo Edge / lo contiene en un vector , y lo compara en un Edge

    visited[start] = true; //el primer nodo visitado
    for (const auto& edge : graph[start]) {
        minHeap.push(edge); //Agrega las aritas en el minHeap
    }

    while(!minHeap.empty() && result.size() < n-1){
        Edge minEdge = minHeap.top();
        minHeap.pop();
        int weight = minEdge.first;
        int u = minEdge.second;


        if(!visited[u]){
            visited[u] = true;
            result.push_back(minEdge);

            for(auto edge : graph[u]){
                if(!visited[edge.second]){
                    minHeap.push(edge);
                }
            }
        }

    }

    return result;


}

