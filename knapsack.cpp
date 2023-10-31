/*

Jesus Ramirez Delgado 
Actividad 3.3 
Knapsack Problem

Time Complexity:

O(N * W) 
N = numero de elementos
W = Capacidad maxima de la knapsack

*/

#include <fstream> // Include the file stream library
#include <iostream>
#include <vector>

using namespace std;

// Función para resolver el problema de la mochila
vector<vector<int> > resolverMochila(int N, const vector<int>& beneficios, const vector<int>& pesos, int W) {
    vector<vector<int> > mochila(N + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= N; i++) {
        for(int w = 1; w <= W; w++) {
            if(pesos[i-1] <= w) {
                mochila[i][w] = max(mochila[i-1][w], beneficios[i-1] + mochila[i-1][w - pesos[i-1]]);
            } else {
                mochila[i][w] = mochila[i-1][w];
            }
        }
    }
    return mochila;
}

int main() {
    // Open the input file
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Failed to open input.txt" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    vector<int> beneficios(N);
    vector<int> pesos(N);

    for(int i = 0; i < N; i++) {
        inputFile >> beneficios[i];
    }

    for(int i = 0; i < N; i++) {
        inputFile >> pesos[i];
    }

    int W;
    inputFile >> W;

    // Close the input file
    inputFile.close();

    // Rest of your code remains the same
    vector<vector<int> > mochila = resolverMochila(N, beneficios, pesos, W);

    cout << "Beneficio óptimo: " << mochila[N][W] << endl;

    cout << "Matriz generada:" << endl;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= W; j++) {
            cout << mochila[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}