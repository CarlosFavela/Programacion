// conecta4_vB_part1.cpp
// Versión B - Parte 1
// Clase Connect4 básica con función para dibujar tablero.

#include <iostream>
#include <array>

class Connect4 {
public:
    static const int ROWS = 6;
    static const int COLS = 7;
    // Usamos std::array para tamaño fijo
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
};

int main() {
    std::cout << "Conecta 4 \n";
    Connect4 juego;
    juego.dibujar();
    
    return 0;
}
