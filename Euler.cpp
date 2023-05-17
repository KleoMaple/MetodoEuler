#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// Define la ecuación diferencial a resolver
double f(double t, double y) {
    return -20*y + 7*exp(-0.5*t);
}

// Implementa el método de Euler
void euler(double t0, double tf, double y0, double h, std::vector<double>& t, std::vector<double>& y) {
    int n = round((tf - t0) / h);  // Calcula el número de pasos
    t.resize(n + 1);  // Reserva memoria para el vector de tiempos
    y.resize(n + 1);  // Reserva memoria para el vector de soluciones
    t[0] = t0;  // Establece X inicial
    y[0] = y0;  // Establece la solución inicial
    for (int i = 0; i < n; i++) {
        t[i + 1] = t[i] + h;  // Calcula el tiempo en el siguiente paso
        y[i + 1] = y[i] + h * f(t[i], y[i]);  // Calcula la solución en el siguiente paso
    }
}

// Imprime una tabla con los resultados
void imprimir_resultados(const vector<double>& t, const vector<double>& y) {
    cout << "t\ty\n";
    for (int i = 0; i < t.size(); i++) {
        cout << t[i] << "\t" << y[i] << "\n";
    }
}

int main() {
    double t0, tf, y0, h;
    // Solicita los valores de los parámetros al usuario
    cout << "Ingrese el t o x inicial: ";
    cin >> t0;
    cout << "Ingrese el t o x final: ";
    cin >> tf;
    cout << "Ingrese la solucion inicial: ";
    cin >> y0;
    do {
        cout << "Ingrese el tamano de paso: ";
        cin >> h;
    } while (h <= 0);  // Valida la entrada de h
    vector<double> t, y;  // Vectores para almacenar los tiempos y las soluciones
    euler(t0, tf, y0, h, t, y);  // Calcula las soluciones con el método de Euler
    imprimir_resultados(t, y);  // Imprime los resultados en una tabla
    return 0;
}

