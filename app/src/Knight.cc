#include "../lib/Knight.h"
#include "../lib/Board.h"

Knight::Knight(int row, int col, bool isBlack)
    : row(row), col(col), isBlack(isBlack) {}

bool Knight::isMoveLegal(Board* board, int endRow, int endCol) const {
    return board->verifySourceAndDestination(this->row, this->col, endRow, endCol, this->isBlack)
        && ((std::abs(endRow - this->row) == 2 && std::abs(endCol - this->col) == 1)
        || (std::abs(endRow - this->row) == 1 && std::abs(endCol - this->col) == 2));
}
