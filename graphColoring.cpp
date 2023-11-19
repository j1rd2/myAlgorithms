/*

Graph Coloring
Jesus Ramirez Delgado
Complejidad: 0(n^2)

*/

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Número de vértices
    vector<vector<int>> adj; // Matriz de adyacencia

public:
    Graph(const vector<vector<int>>& matrix) {
        V = matrix.size();
        adj = matrix;
    }

    void greedyColoring();
};

void Graph::greedyColoring() {
    vector<int> result(V, -1); // Almacena el color asignado a cada vértice
    result[0] = 0; // Asigna el primer color al primer vértice

    vector<bool> available(V); // Array de booleanos para verificar si un color está disponible

    for (int i = 1; i < V; i++) {
        fill(available.begin(), available.end(), false);

        // Marcar colores ya asignados a los vértices adyacentes como no disponibles
        for (int j = 0; j < V; j++) {
            if (adj[i][j] && result[j] != -1) {
                available[result[j]] = true;
            }
        }

        // Encuentra el primer color disponible
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (!available[cr]) break;
        }

        result[i] = cr; // Asigna el color encontrado
    }

    // Imprime los resultados
    for (int i = 0; i < V; i++)
        cout << "Vértice " << i << " ---> Color " << result[i] << endl;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    Graph g(matrix);

    cout << "Coloración del grafo \n";
    g.greedyColoring();

    return 0;
}