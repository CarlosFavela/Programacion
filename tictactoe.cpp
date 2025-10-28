#include <iostream>  
using namespace std;

// Se crea una matriz de 3x3 para representar el tablero
char tablero[3][3];

// Función para inicializar el tablero con números del 1 al 9
void inicializarTablero() {
    int contador = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = '0' + contador;
            contador++;
        }
    }
}

// Función para mostrar el tablero actual
void mostrarTablero() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Función que verifica si un jugador ha ganado
bool hayGanador(char jugador) {
    // Revisa filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
    }
    // Revisa columnas
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador)
            return true;
    }
    // Revisa diagonales
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;

    return false;  // Si no cumple ninguna condición, no hay ganador
}

// Función que valida si una casilla está disponible
bool jugadaValida(int posicion) {
    int fila = (posicion - 1) / 3;      // Calcula fila según posición
    int columna = (posicion - 1) % 3;   // Calcula columna
    return tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O';
}

// Función para realizar una jugada válida
void realizarJugada(char jugador) {
    int posicion;
    bool valido = false;

    while (!valido) {  // Se repite hasta que el jugador elija bien
        cout << "Jugador " << jugador << ", elige una posicion (1-9): ";
        cin >> posicion;

        if (posicion >= 1 && posicion <= 9 && jugadaValida(posicion)) {
            int fila = (posicion - 1) / 3;
            int columna = (posicion - 1) % 3;
            tablero[fila][columna] = jugador;  // Marca la jugada
            valido = true;
        } else {
            cout << "Posicion invalida, intenta de nuevo.\n";
        }
    }
}

// Función principal de prueba
int main() {
    inicializarTablero();
    mostrarTablero();
    realizarJugada('X');  // Simula una jugada
    mostrarTablero();
    return 0;
}