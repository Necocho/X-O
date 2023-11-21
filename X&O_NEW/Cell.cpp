#include <iostream>

class Cell {
public:
    enum class State { Empty, X, O };

    Cell() : state(State::Empty) {}

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

    void markX() {
        state = State::X;
    }

    void markO() {
        state = State::O;
    }

    bool isMarked() const {
        return state != State::Empty;
    }

    State getState() const {
        return state;
    }

private:
    State state;
};