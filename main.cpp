#include "DisjointSet.h"

int main() {
    int n = 10; // Número de elementos en el conjunto disjunto
    DisjoinSet ds(n);

    // Unimos algunos elementos
    ds.Union(1, 2);
    ds.Union(3, 4);
    ds.Union(2, 3);

    // Imprimimos el representante de cada conjunto
    for (int i = 0; i < n; ++i) {
        std::cout << "Elemento: " << i << ", Conjunto Representativo: " << ds.Find(i) << std::endl;
    }

    return 0;
}