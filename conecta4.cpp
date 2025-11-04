// conecta4_vB_part5.cpp
// Versión B - Parte 5 (final)
// Juego completo en clase: reinicio, opción de jugar otra vez y comentarios.

#include <iostream>
#include <array>

class Connect4 {
public:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::array<std::array<char, COLS>, ROWS> board;

    Connect4() { reset(); }

    // Inicializa tablero con '.'
    void reset() {
        for (int r = 0; r < ROWS; ++r)
            for (int c = 0; c < COLS; ++c)
                board[r][c] = '.';
    }

    // Muestra el tablero por consola
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

    // Coloca una ficha en la columna (1..7). Retorna true si se colocó.
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

    bool hay4DiagDesc(char ficha) const {
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

    bool hay4DiagAsc(char ficha) const {
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
    std::cout << "Conecta4  (Final)\n";

    bool jugarOtra = true;
    while (jugarOtra) {
        Connect4 juego;
        int turno = 0;
        char simbolos[2] = {'X','O'};
        bool terminado = false;

        while (!terminado) {
            juego.dibujar();
            std::cout << "Turno jugador " << (turno+1) << " (" << simbolos[turno] << "). Columna (1-7): ";
            int col; std::cin >> col;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Entrada invalida. Intenta de nuevo.\n";
                continue;
            }
            if (!juego.colocar(col, simbolos[turno])) {
                std::cout << "Columna invalida o llena. Intenta otra.\n";
                continue;
            }

            if (juego.hayGanador(simbolos[turno])) {
                juego.dibujar();
                std::cout << "Jugador " << (turno+1) << " (" << simbolos[turno] << ") gana!\n";
                terminado = true;
                continue;
            }

            if (juego.tableroLleno()) {
                juego.dibujar();
                std::cout << "Empate. Tablero lleno.\n";
                terminado = true;
                continue;
            }

            turno = 1 - turno;
        }

        std::cout << "Jugar otra vez (s/n): ";
        char resp; std::cin >> resp;
        if (resp != 's' && resp != 'S') jugarOtra = false;
    }

    std::cout << "Gracias por jugar. Hasta luego!\n";
    return 0;
}
