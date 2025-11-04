// conecta4_vB_part4.cpp
// Versión B - Parte 4
// Añade detección diagonal y método general de ganador.

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

    bool hay4DiagDesc(char ficha) const { // \ diagonal descendente
        for (int r = 0; r <= ROWS - 4; ++r) {
            for (int c = 0; c <= COLS - 4; ++c) {
                bool ok = true;
                for (int k = 0; k < 4; ++k)
                    if (board[r+k][c+k] != ficha) { ok = false; break; }
                if (ok) return true;
            }
        }
        return false;
    }

    bool hay4DiagAsc(char ficha) const { // / diagonal ascendente
        for (int r = 3; r < ROWS; ++r) {
            for (int c = 0; c <= COLS - 4; ++c) {
                bool ok = true;
                for (int k = 0; k < 4; ++k)
                    if (board[r-k][c+k] != ficha) { ok = false; break; }
                if (ok) return true;
            }
        }
        return false;
    }

    bool hayGanador(char ficha) const {
        return hay4Horizontal(ficha) || hay4Vertical(ficha) ||
               hay4DiagDesc(ficha) || hay4DiagAsc(ficha);
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

        if (juego.hayGanador(simbolos[turno])) {
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
