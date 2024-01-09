#include "../lib/Rook.h"
#include "../lib/Board.h"

Rook::Rook(int row, int col, bool isBlack)
    : row(row), col(col), isBlack(isBlack) {}

bool Rook::isMoveLegal(Board* board, int endRow, int endCol) const {
    return board->verifySourceAndDestination(this->row, this->col, endRow, endCol, this->isBlack)
        && (board->verifyHorizontal(this->row, this->col, endRow, endCol)
        ||  board->verifyVertical(this->row, this->col, endRow, endCol));
}