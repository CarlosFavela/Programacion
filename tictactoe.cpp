#include <iostream>  // Librería para entrada y salida estándar
using namespace std;

// Se crea una matriz de 3x3 para representar el tablero
char tablero[3][3];

// Función para inicializar el tablero con números del 1 al 9
void inicializarTablero() {
    int contador = 1;
    // Se recorren las filas
    for (int i = 0; i < 3; i++) {
        // Se recorren las columnas
        for (int j = 0; j < 3; j++) {
            // Se asigna el número correspondiente como carácter
            tablero[i][j] = '0' + contador;
            contador++;
        }
    }
}

// Función para mostrar el tablero actual
void mostrarTablero() {
    cout << "\n";
    // Recorre cada fila
    for (int i = 0; i < 3; i++) {
        // Recorre cada columna
        for (int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";  // Muestra el valor
            if (j < 2) cout << "|";              // Separa las columnas con |
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";      // Separa las filas con líneas
    }
    cout << "\n";
}
