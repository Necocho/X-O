#include <iostream>

class Cell {
public:
    /**
     * Перечисление для представления состояния ячейки.
     * Возможные значения: Empty (пусто), X, O.
     */
    enum class State { Empty, X, O };

    /**
     * Конструктор по умолчанию, устанавливает состояние ячейки как пусто.
     */
    Cell() : state(State::Empty) {}

    /**
    * Метод отрисовки текущего состояния ячейки.
    */
    void draw() const {
        switch (state) {
        case State::Empty:
            std::cout << " ";
            break;
        case State::X:
            std::cout << "X";
            break;
        case State::O:
            std::cout << "O";
            break;
        }
    }
    // Конструкторы
    Cell(State initialState) : state(initialState) {}
    Cell(const Cell& other) : state(other.state) {}
    Cell(State initialState, bool marked) : state(initialState) {}

    // Метод копирования
    void copyFrom(const Cell& other) {
        state = other.state;
    }

    // Метод сравнения
    bool isEqual(const Cell& other) const {
        return state == other.state;
    }

    // Метод ввода
    void input() {
        char symbol;
        std::cout << "Введите символ (X, O, или пробел): ";
        std::cin >> symbol;

        switch (symbol) {
        case 'X':
            state = State::X;
            break;
        case 'O':
            state = State::O;
            break;
        case ' ':
            state = State::Empty;
            break;
        default:
            std::cerr << "Некорректный символ. Используйте X, O или пробел." << std::endl;
            break;
        }

    }

    /**
     * Устанавливает состояние ячейки как X.
     */
    void markX() {
        state = State::X;
    }

    /**
     * Устанавливает состояние ячейки как O.
     */
    void markO() {
        state = State::O;
    }

    /**
     * Проверяет, помечена ли ячейка (не пуста).
     * @return true, если ячейка помечена, иначе false.
     */
    bool isMarked() const {
        return state != State::Empty;
    }

    /**
     * Возвращает текущее состояние ячейки.
     * @return Текущее состояние ячейки.
     */
    State getState() const {
        return state;
    }

private:
    State state;
};