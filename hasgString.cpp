/*

Sebastian Jimenez Bauer
Jesus Ramirez Delgado
Actividad 2.3
Implementacion Hash string

*/

#include <iostream>  
#include <fstream>   
#include <string>
#include <sstream> 

using namespace std;  

int main() {
    string archivo;  // Variable para almacenar el nombre del archivo
    int n;  // Variable para almacenar el valor de n

    // Pedir al usuario el nombre del archivo
    cout << "Por favor, ingrese el nombre del archivo: ";
    cin >> archivo;

    // Loop para verificar el valor de n
    while (true) {
        cout << "Por favor ingrese el valor de n: " << endl;
        cin >> n;

        // Validar el valor de n
        if (n % 4 != 0 || n < 16 || n > 64) {
            cout << "El valor de n debe ser un múltiplo de 4 y estar en el rango de 16-64." << endl;
            cout << "Ingrese de nuevo" << endl;
        } else {
            break;  // Salir del loop si n es válido
        }
    }

    char* texto = new char[1024];  // Crear un arreglo dinámico para almacenar el texto

    // Abrir el archivo para lectura
    ifstream f(archivo);
    if (!f.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        delete[] texto;
        return 1;
    }

    int i = 0;  // Índice para recorrer el texto
    // Leer el archivo y almacenar su contenido en el arreglo
    while (f.get(texto[i])) {
        i++;
        if (i == 1024) {
            f.close();
            cout << "El archivo es demasiado grande" << endl;
            delete[] texto;
            return 1;
        }
    }
    f.close();  // Cerrar el archivo

    int a[n];  // Crear un arreglo para almacenar los valores de hash
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }

    int j;
    // Calcular el valor de hash
    for (i = 0; i < n; i++) {
        int suma = 0;  // Variable para almacenar la suma de los códigos ASCII
        for (j = 0; j < n; j++) {
            suma += (int)texto[i * n + j];
        }
        a[i] = suma % 256;
    }

    // Imprimir la tabla generada
    cout << "Tabla generada:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << texto[i * n + j];
        }
        cout << endl;
    }

    // Imprimir el arreglo de hash
    cout << "Arreglo a:" << endl;
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Imprimir el valor hash final
    cout << "Hash: " << endl;
    string hash = "";
    for (i = 0; i < n; i++) {
        stringstream ss;  // Crear un stringstream para cada numero
        ss << hex << a[i];  // Convertir el numero a hexadecimal
        hash += ss.str();  // Agregar el numero hexadecimal al string de hash
    }

    cout << hash << endl;  // Imprimir el hash en hexadecimal

    delete[] texto;  // Liberar memoria dinamica
    return 0;

    cout << hash << endl;

    delete[] texto;  // Liberar memoria dinamica
    return 0;
}