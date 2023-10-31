#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Función para construir el Suffix Array
std::vector<int> constructSuffixArray(const std::string& str) {
    int n = str.size();
    std::vector<int> suffixArray(n);
    // inicializar suffixArray con las posiciones 0, 1, 2, ..., n-1
    for(int i = 0; i < n; ++i) suffixArray[i] = i;
    
    // Ordenar el array basándose en los sufijos
    sort(suffixArray.begin(), suffixArray.end(), [&str](int a, int b) -> bool {
        return str.substr(a) < str.substr(b);
    });
    return suffixArray;
}

int main() {
    // 4 casos de prueba
    std::vector<std::string> testStrings = {
        "queretaro",
        "TECDEMONTERREY",
        "coding",
        "banana",
    };
    
    for(const auto& str : testStrings) {
        // Construir el Suffix Array para cada string de prueba
        std::vector<int> suffixArray = constructSuffixArray(str);
        
        int caso;
        caso = 1 + caso++;
        cout << "Caso: " << caso << endl;
        // Mostrar todos los substrings ordenados alfabéticamente para cada string de prueba
        cout << "Para el string \"" << str << "\", los substrings ordenados alfabeticamente son:\n";
        for(const int& i : suffixArray) {
            cout << str.substr(i) << '\n';
        }
        cout << "-----------------------------\n";
    }
    
    return 0;
}

