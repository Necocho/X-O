#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "TicTacToe.cpp"
#include <string>
/**
 * Основная функция для запуска игры в крестики-нолики.
 * Запрашивает у пользователя имя и проводит с ним игру против компьютера.
 */
int main() {

    srand(static_cast<unsigned>(time(0)));

    // Запрос имени у пользователя
    std::cout << "Write your name: ";

    // Чтение имени из консоли в переменную name типа string
    std::string name;
    std::getline(std::cin, name);

    TicTacToe game;
    int currentPlayer = rand() % 2; // X - Человек || O - Компьютер \\

    while (true) {
        game.drawBoard();

        if (currentPlayer == 0) {
            // Ход ИГРОКА
            int cellNumber;
            std::cout << name + " (X), write position (1-9): ";
            std::cin >> cellNumber;

            if (game.makeMove(cellNumber, Cell::State::X)) {
                if (game.checkWin(Cell::State::X)) {
                    game.drawBoard();
                    std::cout << name + " (X) Win!" << std::endl;
                    break;
                }
                if (game.isBoardFull()) {
                    game.drawBoard();
                    std::cout << "Draw!" << std::endl;
                    break;
                }
                currentPlayer = 1;
            }
        }
        else {
            // Ход ИИ
            int cellNumber;
            do {
                cellNumber = rand() % 9 + 1;
            } while (!game.makeMove(cellNumber, Cell::State::O));

            if (game.checkWin(Cell::State::O)) {
                game.drawBoard();
                std::cout << "AI (O) Win!" << std::endl;
                break;
            }
            if (game.isBoardFull()) {
                game.drawBoard();
                std::cout << "Draw!" << std::endl;

                break;
            }
            currentPlayer = 0;
        }
    }
    system("pause");
    return 0;
}
