/*

Jesus Ramirez Delgado 

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <sstream>
#include <cmath>
#include <cfloat>

using namespace std;

const int MAX = 100;
int n; // Número de nodos (colonias)
int graph[MAX][MAX]; // Matriz de adyacencia para distancias
int capacity[MAX][MAX]; // Matriz de capacidad para flujos
vector<pair<int, int>> centralLocations; // Ubicaciones de las centrales
pair<int, int> newCentral; // Ubicación de la nueva central


// Función para leer el archivo de entrada
void readInputFile(const string& filename) {
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        // Leer el número de nodos
        file >> n;
        getline(file, line); // Ignorar el resto de la línea

        // Leer la matriz de adyacencia
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file >> graph[i][j];
            }
            getline(file, line); // Ignorar el resto de la línea
        }

        // Leer la matriz de capacidad
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file >> capacity[i][j];
            }
            getline(file, line); // Ignorar el resto de la línea
        }
      centralLocations.resize(n);
          for (int i = 0; i < n; i++) {
              getline(file, line);
              sscanf(line.c_str(), "(%d,%d)", &centralLocations[i].first, &centralLocations[i].second);
          }

          // Leer ubicación de la nueva central
          getline(file, line);
          sscanf(line.c_str(), "(%d,%d)", &newCentral.first, &newCentral.second);
      } else {
          cerr << "No se pudo abrir el archivo" << endl;
      }
}

// -------- PARTE 1 ---------
// Implementación del algoritmo de Dijkstra
vector<int> dijkstra(int src) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v])
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
        }
    }
    return dist;
}

// ------- PARTE 2 ----------
// Función para imprimir la ruta y el costo del TSP
vector<int> tspNearestNeighbor() {
    vector<bool> visited(n, false);
    vector<int> path;
    int current = 0;
    path.push_back(current);
    visited[current] = true;

    for (int i = 1; i < n; ++i) {
        int next = -1;
        int minDist = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && graph[current][j] < minDist) {
                minDist = graph[current][j];
                next = j;
            }
        }
        current = next;
        visited[current] = true;
        path.push_back(current);
    }
    path.push_back(path.front()); // Regresar al punto de inicio
    return path;
}

void printTSPRoute(const vector<int>& path) {
    int totalCost = 0;
    cout << "El recorrido:\n";
    for (size_t i = 0; i < path.size() - 1; ++i) {
        cout << path[i] + 1 << " -> "; // +1 para ajustar el índice a la nomenclatura de la colonia
        totalCost += graph[path[i]][path[i + 1]];
    }
    cout << path.front() + 1 << endl; // Mostrar el retorno al inicio
    cout << "El costo: " << totalCost << endl;
}

// --------- PARTE 3 ---------
// Función para BFS utilizada en Ford-Fulkerson 
bool bfs(int rGraph[MAX][MAX], int s, int t, int parent[]) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

// Implementación del algoritmo de Ford-Fulkerson
int fordFulkerson(int s, int t) {
    int u, v;
    int rGraph[MAX][MAX]; // Residual graph

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = capacity[u][v];

    int parent[n]; // Array to store path
    int max_flow = 0; // Initially no flow

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

// -------- PARTE 4 ------------
double calculateDistance(const pair<int, int>& a, const pair<int, int>& b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// Función para encontrar la central más cercana
void findClosestCentral() {
    double minDistance = DBL_MAX;
    pair<int, int> closestCentral;

    cout << "Centrales y sus ubicaciones:" << endl;
    for (const auto& central : centralLocations) {
        cout << "[" << central.first << ", " << central.second << "]" << endl;
        double distance = calculateDistance(central, newCentral);
        cout << "Distancia a [" << newCentral.first << ", " << newCentral.second << "]: " << distance << endl;
        if (distance < minDistance) {
            minDistance = distance;
            closestCentral = central;
        }
    }

    cout << "La central más cercana a [" << newCentral.first << ", " << newCentral.second
         << "] es [" << closestCentral.first << ", " << closestCentral.second
         << "] con una distancia de " << minDistance << "." << endl;
}


int main() {
    string filename = "E3.txt"; // Asegúrate de tener el archivo con el nombre correcto
    readInputFile(filename);

    // Ejemplo de uso de Dijkstra
  for (int src = 0; src < n; src++) { // Iterar sobre cada colonia como fuente
      vector<int> distances = dijkstra(src);
      cout << "Distancias desde la colonia " << src + 1 << ":" << endl;
      for (int i = 0; i < distances.size(); i++)
          cout << "Distancia de la colonia " << src + 1 << " a la colonia " << i + 1 << ": " << distances[i] << " km" << endl;
  }

  vector<int> tspPath = tspNearestNeighbor();
  printTSPRoute(tspPath);

    // Ejemplo de uso de Ford-Fulkerson
    int max_flow = fordFulkerson(0, n - 1); // Asumiendo que el nodo inicial es 0 y el final es n-1
    cout << "Flujo máximo: " << max_flow << endl;
  
  findClosestCentral();
  
    return 0;
}