#include "iostream"
#include "vector"

using namespace std;

class DisjoinSet{
private:
    vector<int> parent;
    vector<int> rank;

public:

    DisjoinSet(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int Find(int x){
        if(parent[x] == x){
            return x;
        }else{
            return Find(parent[x]);
        }
    }

    void Union(int x,int y){
        int xRoot = Find(x);
        int yRoot = Find(y);

        if(xRoot == yRoot){
            return;
        }

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

};