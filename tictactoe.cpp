#include <iostream>  
using namespace std;

// Se crea una matriz de 3x3 para representar el tablero
char tablero[3][3];

// Inicializa el tablero con números del 1 al 9
void inicializarTablero() {
    int contador = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = '0' + contador;
            contador++;
        }
    }
}

// Muestra el tablero actual
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

// Verifica si un jugador ganó
bool hayGanador(char jugador) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
    }
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador)
            return true;
    }
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;
    return false;
}

// Valida si una casilla está disponible
bool jugadaValida(int posicion) {
    int fila = (posicion - 1) / 3;
    int columna = (posicion - 1) % 3;
    return tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O';
}

// Permite que el jugador realice una jugada válida
void realizarJugada(char jugador) {
    int posicion;
    bool valido = false;
    while (!valido) {
        cout << "Jugador " << jugador << ", elige una posicion (1-9): ";
        cin >> posicion;
        if (posicion >= 1 && posicion <= 9 && jugadaValida(posicion)) {
            int fila = (posicion - 1) / 3;
            int columna = (posicion - 1) % 3;
            tablero[fila][columna] = jugador;
            valido = true;
        } else {
            cout << "Posicion invalida, intenta de nuevo.\n";
        }
    }
}

// Función principal
int main() {
    char jugador = 'X';   // Jugador que inicia
    int turnos = 0;       // Contador de turnos
    bool jugando = true;  // Controla si se sigue jugando
    char opcion;          // Opción para reiniciar o salir

    do {
        inicializarTablero();  // Prepara el tablero nuevo
        turnos = 0;            // Reinicia contador
        jugador = 'X';         // Reinicia jugador inicial

        while (true) {         // Bucle del juego
            mostrarTablero();
            realizarJugada(jugador);
            turnos++;

            // Verifica si el jugador actual ganó
            if (hayGanador(jugador)) {
                mostrarTablero();
                cout << "¡El jugador " << jugador << " ha ganado!\n";
                break;
            }

            // Si se completaron 9 turnos sin ganador, es empate
            if (turnos == 9) {
                mostrarTablero();
                cout << "Empate. No hay ganador.\n";
                break;
            }

            // Alterna entre jugador X y O
            jugador = (jugador == 'X') ? 'O' : 'X';
        }

        // Menú para reiniciar o salir
        cout << "\n¿Deseas jugar otra vez? (s/n): ";
        cin >> opcion;
        if (opcion == 'n' || opcion == 'N')
            jugando = false;

    } while (jugando);

    cout << "Gracias por jugar Tic Tac Toe :)\n";
    return 0;
}
