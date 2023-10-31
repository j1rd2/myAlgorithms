/*

Implementacion Backtracking / ramificacion y poda

Tecnica: Se utiliza Backtracking y podemos determinar esto a que:
> De forma recursiva recorre todos los caminos posibles
> Si llega a un punto sin salida, deshace el paso anterior y prueba otra ruta

Movilidad: Se mueve solo hacia derecha y abajo.

Complejidad: O(m x n)

*/

#include <iostream>
#include <vector>
using namespace std;

bool findPath(vector<vector<int>>& arr, int x, int y) {
    int m = arr.size();
    int n = arr[0].size();
    
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return false;
    }
    
    if (x == m - 1 && y == n - 1) {
        arr[x][y] = 2;
        return true;
    }
    
    if (arr[x][y] == 1) {
        arr[x][y] = 2;

        if (findPath(arr, x, y + 1)) {
            return true;
        }
        if (findPath(arr, x + 1, y)) {
            return true;
        }
        
        arr[x][y] = 1;  // Backtrack
    }
    
    return false;
}

void printMaze(const vector<vector<int>>& arr, int testCase) {
    cout << "Test Case " << testCase << ":" << endl;
    for (const auto& row : arr) {
        for (int cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

int main() {
    
    vector<vector<vector<int>>> testCases = {
        {
            {1, 0, 1, 1, 1},
            {1, 1, 1, 0, 1},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 0, 1}
        },
        {
            {1, 0, 0, 1},
            {1, 1, 1, 0},
            {0, 1, 1, 1},
            {1, 0, 0, 1}
        },
        {
            {1,1,1},
            {1,0,0},
            {1,1,1},
            {1,0,1}
        },
        {
            {1,1,0,1,1,1,1,1,0},
            {0,1,1,1,0,0,0,1,1},
            {1,1,0,1,1,1,1,1,0},
            {1,0,0,0,1,1,0,1,1},
            {1,1,0,1,1,0,0,0,1},
            {0,1,0,1,0,1,0,0,1},
            {1,1,1,1,0,1,1,0,1}
        },
    };
    
    for (int i = 0; i < testCases.size(); ++i) {
        findPath(testCases[i], 0, 0);
        printMaze(testCases[i], i + 1);
    }

    return 0;
}