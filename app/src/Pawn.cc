#include "../lib/Pawn.h"
#include "../lib/Board.h"

Pawn::Pawn(int row, int col, bool isBlack)
    : row(row), col(col), isBlack(isBlack) {}

bool Pawn::isMoveLegal(Board* board, int endRow, int endCol) {
    if (board->verifyVertical(this->row, this->col, endRow, endCol) && board->getPiece(endRow, endCol) == nullptr) {
        // Case 1: Forward movement to empty square.
        // Determine if the distance being moved is valid.
        if (this->isBlack) {
            return (endRow == this->row + 1) || ((endRow == this->row + 2) && (this->row == 1));
        } else {
            return (endRow == this->row - 1) || ((endRow == this->row - 2) && (this->row == 6));
        }
    } else if (this->col == endCol + 1 || this->col == endCol - 1) {
        // Case 2: Capturing a piece.
        if (board->getPiece(endRow, endCol) != nullptr && board->getPiece(endRow, endCol)->getIsBlack() != this->isBlack) {
            if (this->isBlack) {
                return (endRow == this->row + 1);
            } else {
                return (endRow == this->row - 1);
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
