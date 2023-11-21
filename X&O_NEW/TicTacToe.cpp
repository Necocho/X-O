#include <iostream>
#include "Cell.cpp"
#include <vector>

class TicTacToe {
    
public:
    TicTacToe() {
        
        for (int i = 0; i < 9; ++i) {
            cells.push_back(Cell());
        }
    }

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