#include "../lib/King.h"
#include "../lib/Board.h"

King::King(int row, int col, bool isBlack)
    : row(row), col(col), isBlack(isBlack) {}

bool King::isMoveLegal(Board* board, int endRow, int endCol) const {
    return board->verifySourceAndDestination(this->row, this->col, endRow, endCol, this->isBlack)
        && Board::verifyAdjacent(this->row, this->col, endRow, endCol);
}