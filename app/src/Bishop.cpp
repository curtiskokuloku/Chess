#include "../lib/Bishop.h"
#include "../lib/Board.h"

Bishop::Bishop(int row, int col, bool isBlack)
        : row(row), col(col), isBlack(isBlack) {}

bool Bishop::isMoveLegal(Board* board, int endRow, int endCol) const {
    return board->verifySourceAndDestination(this->row, this->col, endRow, endCol, this->isBlack)
           && board->verifyDiagonal(this->row, this->col, endRow, endCol);
}
