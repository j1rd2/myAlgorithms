/*

Jesus Ramirez Delgado
Sebastian Jimenez Bauer
Equipo 10
Actividad 1.1
Ejercicio 2

*/

#include <iostream>
#include <cmath>

using namespace std;

double volumen (double radio, double altura) {
    double res;
    res = M_PI * (radio * radio) * altura;
    return res;
}

int main(){
    
// Ejercicio 1

// Caso de prueba 1

int productLine1_C1 = 100;
int productLine2_C1 = 200;

int averageProductionPerDay1 = (productLine1_C1 + productLine2_C1) / 2;

int productionAmountWanted1 = 400;

int DayAproxNeeded1 = productionAmountWanted1 / averageProductionPerDay1;

cout << "With an average of " << averageProductionPerDay1 << " products a day, it will take aprox: " << DayAproxNeeded1 << " days to make the production required." << endl;

// Caso de prueba 2

int productLine1_C2 = 400;
int productLine2_C2 = 382;

int averageProductionPerDay2 = (productLine1_C2 + productLine2_C2) / 2;

int productionAmountWanted2 = 400;

int DayAproxNeeded2 = productionAmountWanted2 / averageProductionPerDay2;

cout << "With an average of " << averageProductionPerDay2 << " products a day, it will take aprox: " << DayAproxNeeded2 << " days to make the production required." << endl;

// Caso de prueba 3

int productLine1_C3 = 50;
int productLine2_C3 = 10;

int averageProductionPerDay3 = (productLine1_C3 + productLine2_C3) / 2;

int productionAmountWanted3 = 400;

int DayAproxNeeded3 = productionAmountWanted3 / averageProductionPerDay3;

cout << "With an average of " << averageProductionPerDay3 << " products a day, it will take aprox: " << DayAproxNeeded3 << " days to make the production required." << endl;

// Caso de prueba 4

int productLine1_C4 = 2000;
int productLine2_C4 = 3200;

int averageProductionPerDay4 = (productLine1_C4 + productLine2_C4) / 2;

int productionAmountWanted4 = 400;

int DayAproxNeeded4 = productionAmountWanted4 / averageProductionPerDay4;

cout << "With an average of " << averageProductionPerDay4 << " products a day, it will take aprox: " << DayAproxNeeded4 << " days to make the production required." << endl;

// Ejercicio 2

// Caso de prueba 1
    double radio1 = 2.5;
    double altura1 = 1.8;
    double botella1 = 500;
    double volumenBotella1 = botella1 / 1000;
    double volumenCont1 = volumen(radio1, altura1);
    double resultado1 = volumenCont1 / volumenBotella1;
    cout << "Caso 1: Tu contenedor puede llenar hasta " << resultado1 << " botellas antes de vaciarse." << endl;

    // Caso de prueba 2
    double radio2 = 1.0;
    double altura2 = 0.5;
    double botella2 = 750;
    double volumenBotella2 = botella2 / 1000;
    double volumenCont2 = volumen(radio2, altura2);
    double resultado2 = volumenCont2 / volumenBotella2;
    cout << "Caso 2: Tu contenedor puede llenar hasta " << resultado2 << " botellas antes de vaciarse." << endl;

    // Caso de prueba 3
    double radio3 = 3.2;
    double altura3 = 2.7;
    double botella3 = 1000;
    double volumenBotella3 = botella3 / 1000;
    double volumenCont3 = volumen(radio3, altura3);
    double resultado3 = volumenCont3 / volumenBotella3;
    cout << "Caso 3: Tu contenedor puede llenar hasta " << resultado3 << " botellas antes de vaciarse." << endl;

    // Caso de prueba 4
    double radio4 = 0.5;
    double altura4 = 1.0;
    double botella4 = 200;
    double volumenBotella4 = botella4 / 1000;
    double volumenCont4 = volumen(radio4, altura4);
    double resultado4 = volumenCont4 / volumenBotella4;
    cout << "Caso 4: Tu contenedor puede llenar hasta " << resultado4 << " botellas antes de vaciarse." << endl;


    return 0;
}