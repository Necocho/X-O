#include <iostream>
#include "Cell.cpp"
#include <vector>

/**
 * Класс представляет собой игру в крестики-нолики.
 * Включает в себя игровое поле и логику для хода человека и компьютера.
 */
class TicTacToe {
    
public:
    /**
     * Конструктор по умолчанию. Инициализирует игровое поле ячейками.
     */
    TicTacToe() {
        
        for (int i = 0; i < 9; ++i) {
            cells.push_back(Cell());
        }
    }

    /**
     * Метод отрисовки текущего состояния игрового поля.
     */
    void drawBoard() const {
        std::cout << "-------------" << std::endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << "| ";
                cells[i * 3 + j].draw();
                std::cout << " ";
            }
            std::cout << "|" << std::endl;
            std::cout << "-------------" << std::endl;
        }
    }

    /**
    * Выполняет ход игрока (человека или компьютера) в указанную ячейку.
    * @param cellNumber Номер ячейки (1-9), куда будет выполнен ход.
    * @param player Состояние игрока (X или O).
    * @return true, если ход выполнен успешно, иначе false.
    */
    bool makeMove(int cellNumber, Cell::State player) {
        if (cellNumber < 1 || cellNumber > 9) {
            std::cout << "Incorrect number. Try again." << std::endl;
            return false;
        }

        Cell& selectedCell = cells[cellNumber - 1];
        if (selectedCell.isMarked()) {
            std::cout << "Position occupied. Try again." << std::endl;
            return false;
        }

        if (player == Cell::State::X) {
            selectedCell.markX();
        }
        else {
            selectedCell.markO();
        }

        return true;
    }

    /**
     * Проверяет, достигнута ли победа для указанного игрока.
     * @param player Состояние игрока (X или O).
     * @return true, если игрок выиграл, иначе false.
     */
    bool checkWin(Cell::State player) const {

        for (int i = 0; i < 3; ++i) {
            if (cells[i * 3].isMarked() && cells[i * 3].getState() == player &&
                cells[i * 3].getState() == cells[i * 3 + 1].getState() &&
                cells[i * 3].getState() == cells[i * 3 + 2].getState()) {
                return true;
            }
            if (cells[i].isMarked() && cells[i].getState() == player &&
                cells[i].getState() == cells[i + 3].getState() &&
                cells[i].getState() == cells[i + 6].getState()) {
                return true;
            }
        }
        if (cells[0].isMarked() && cells[0].getState() == player &&
            cells[0].getState() == cells[4].getState() &&
            cells[0].getState() == cells[8].getState()) {
            return true;
        }
        if (cells[2].isMarked() && cells[2].getState() == player &&
            cells[2].getState() == cells[4].getState() &&
            cells[2].getState() == cells[6].getState()) {
            return true;
        }

        return false;
    }

    /**
     * Проверяет, заполнено ли игровое поле.
     * @return true, если игровое поле заполнено, иначе false.
     */
    bool isBoardFull() const {
        for (const auto& cell : cells) {
            if (!cell.isMarked()) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<Cell> cells;
};