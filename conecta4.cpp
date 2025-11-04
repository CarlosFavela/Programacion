// conecta4_vB_part2.cpp
// Versión B - Parte 2
// Se añade método para colocar ficha con caída y validación.

#include <iostream>
#include <array>

class Connect4 {
public:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::array<std::array<char, COLS>, ROWS> board;

    Connect4() {
        for (int r = 0; r < ROWS; ++r)
            for (int c = 0; c < COLS; ++c)
                board[r][c] = '.';
    }

    void dibujar() const {
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                std::cout << board[r][c] << ' ';
            }
            std::cout << '\n';
        }
        for (int c = 1; c <= COLS; ++c) std::cout << c << ' ';
        std::cout << "\n\n";
    }

    // Coloca ficha en la columna (1..7). Devuelve true si la colocacion fue exitosa.
    bool colocar(int columna, char ficha) {
        int col = columna - 1;
        if (col < 0 || col >= COLS) return false;
        for (int r = ROWS - 1; r >= 0; --r) {
            if (board[r][col] == '.') {
                board[r][col] = ficha;
                return true;
            }
        }
        return false; // columna llena
    }
};

int main() {
    std::cout << "Conecta 4 \n";
    Connect4 juego;
    juego.dibujar();

    int col;
    std::cout << "Ingresa columna para colocar X: ";
    std::cin >> col;
    if (juego.colocar(col, 'X')) {
        std::cout << "Ficha colocada.\n";
    } else {
        std::cout << "No se pudo colocar ficha (columna inválida o llena).\n";
    }
    juego.dibujar();

    return 0;
}
