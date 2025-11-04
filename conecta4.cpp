// conecta4_vB_part3.cpp
// Versión B - Parte 3
// Añade métodos para comprobar victoria horizontal y vertical, y flujo de juego simple.

#include <iostream>
#include <array>

class Connect4 {
public:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::array<std::array<char, COLS>, ROWS> board;

    Connect4() { reset(); }

    void reset() {
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

    bool colocar(int columna, char ficha) {
        int col = columna - 1;
        if (col < 0 || col >= COLS) return false;
        for (int r = ROWS - 1; r >= 0; --r) {
            if (board[r][col] == '.') {
                board[r][col] = ficha;
                return true;
            }
        }
        return false;
    }

    bool hay4Horizontal(char ficha) const {
        for (int r = 0; r < ROWS; ++r) {
            int cnt = 0;
            for (int c = 0; c < COLS; ++c) {
                cnt = (board[r][c] == ficha) ? cnt + 1 : 0;
                if (cnt >= 4) return true;
            }
        }
        return false;
    }

    bool hay4Vertical(char ficha) const {
        for (int c = 0; c < COLS; ++c) {
            int cnt = 0;
            for (int r = 0; r < ROWS; ++r) {
                cnt = (board[r][c] == ficha) ? cnt + 1 : 0;
                if (cnt >= 4) return true;
            }
        }
        return false;
    }

    bool tableroLleno() const {
        for (int c = 0; c < COLS; ++c) if (board[0][c] == '.') return false;
        return true;
    }
};

int main() {
    std::cout << "Conecta 4 \n";
    Connect4 juego;
    int turno = 0;
    char simbolos[2] = {'X','O'};

    while (true) {
        juego.dibujar();
        std::cout << "Turno jugador " << (turno+1) << " (" << simbolos[turno] << "). Columna (1-7): ";
        int col; std::cin >> col;
        if (!juego.colocar(col, simbolos[turno])) {
            std::cout << "Columna invalida o llena.\n";
            continue;
        }

        // Comprueba horizontal y vertical
        if (juego.hay4Horizontal(simbolos[turno]) || juego.hay4Vertical(simbolos[turno])) {
            juego.dibujar();
            std::cout << "Jugador " << (turno+1) << " gana!\n";
            break;
        }

        if (juego.tableroLleno()) {
            juego.dibujar();
            std::cout << "Empate.\n";
            break;
        }

        turno = 1 - turno;
    }

    return 0;
}
