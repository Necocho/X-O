#include <iostream>

class Cell {
public:
    /**
     * ������������ ��� ������������� ��������� ������.
     * ��������� ��������: Empty (�����), X, O.
     */
    enum class State { Empty, X, O };

    /**
     * ����������� �� ���������, ������������� ��������� ������ ��� �����.
     */
    Cell() : state(State::Empty) {}

    /**
    * ����� ��������� �������� ��������� ������.
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
    // ������������
    Cell(State initialState) : state(initialState) {}
    Cell(const Cell& other) : state(other.state) {}
    Cell(State initialState, bool marked) : state(initialState) {}

    // ����� �����������
    void copyFrom(const Cell& other) {
        state = other.state;
    }

    // ����� ���������
    bool isEqual(const Cell& other) const {
        return state == other.state;
    }

    // ����� �����
    void input() {
        char symbol;
        std::cout << "������� ������ (X, O, ��� ������): ";
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
            std::cerr << "������������ ������. ����������� X, O ��� ������." << std::endl;
            break;
        }

    }

    /**
     * ������������� ��������� ������ ��� X.
     */
    void markX() {
        state = State::X;
    }

    /**
     * ������������� ��������� ������ ��� O.
     */
    void markO() {
        state = State::O;
    }

    /**
     * ���������, �������� �� ������ (�� �����).
     * @return true, ���� ������ ��������, ����� false.
     */
    bool isMarked() const {
        return state != State::Empty;
    }

    /**
     * ���������� ������� ��������� ������.
     * @return ������� ��������� ������.
     */
    State getState() const {
        return state;
    }

private:
    State state;
};