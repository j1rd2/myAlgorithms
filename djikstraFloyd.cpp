/*

Actividad 3.2b
Algoritmos Djikstra Floyd
Sebastian Jimenez Bauer
Jesus Ramirez Delgado
Equipo 10

*/

#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int N = 4; // Tamaño del grafo

int findMinVertex(int distance[], bool visited[]) {
    int minVertex = -1;
    for(int i = 0; i < N; i++) {
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int matrix[N][N]) {
    int distance[N];
    bool visited[N];

    for(int source = 0; source < N; source++) {
        for(int i = 0; i < N; i++) {
            distance[i] = INF;
            visited[i] = false;
        }
        distance[source] = 0;

        for(int i = 0; i < N-1; i++) {
            int minVertex = findMinVertex(distance, visited);
            visited[minVertex] = true;

            for(int j = 0; j < N; j++) {
                if(matrix[minVertex][j] != -1 && !visited[j] && distance[minVertex] != INF && distance[minVertex] + matrix[minVertex][j] < distance[j]) {
                    distance[j] = distance[minVertex] + matrix[minVertex][j];
                }
            }
        }

        for(int i = 0; i < N; i++) {
            if(source != i && distance[i] != INF) {
                cout << "node " << source+1 << " to node " << i+1 << ": " << distance[i] << endl;
            }
        }
    }
}

void floydWarshall(int matrix[N][N]) {
    int dist[N][N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) {
                dist[i][j] = 0;
            } else if(matrix[i][j] == -1) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = matrix[i][j];
            }
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "\nFloyd-Warshall:" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(dist[i][j] != INF) {
                cout << dist[i][j] << " ";
            } else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }
}

int main() {
    int matrix[N][N] = {
        {0, 2, -1, 3},
        {-1, 0, 1, 5},
        {2, 3, 0, -1},
        {3, -1, 4, 0}
    };

    cout << "Dijkstra:" << endl;
    dijkstra(matrix);

    floydWarshall(matrix);

    return 0;
}
