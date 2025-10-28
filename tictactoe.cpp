#include <iostream>  // Librería para entrada y salida estándar
using namespace std;

// Se crea una matriz de 3x3 para representar el tablero
char tablero[3][3];

// Función para inicializar el tablero con números del 1 al 9
void inicializarTablero() {
    int contador = 1;  // Variable para numerar las posiciones
    for (int i = 0; i < 3; i++) {      // Recorre filas
        for (int j = 0; j < 3; j++) {  // Recorre columnas
            tablero[i][j] = '0' + contador;  // Convierte el número a carácter
            contador++;                       // Avanza al siguiente número
        }
    }
}

// Función para mostrar el tablero actual
void mostrarTablero() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {           // Recorre filas
        for (int j = 0; j < 3; j++) {       // Recorre columnas
            cout << " " << tablero[i][j] << " ";  // Muestra el valor
            if (j < 2) cout << "|";               // Coloca separador vertical
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";      // Línea separadora entre filas
    }
    cout << "\n";
}

// Función principal de prueba
int main() {
    inicializarTablero();  // Llama a la función para llenar el tablero
    mostrarTablero();      // Muestra el tablero inicial
    return 0;              // Fin del programa
}
