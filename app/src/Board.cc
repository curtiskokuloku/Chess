#include "../lib/Board.h"

Board::Board() {
    // Create a new board.
    board.resize(8, std::vector<Piece*>(8, nullptr));
}

// Accessor Methods
Piece* Board::getPiece(int row, int col) const {
    return board[row][col];
}

void Board::setPiece(int row, int col, Piece* piece) {
    board[row][col] = piece;
}

// Movement helper functions
bool Board::verifySourceAndDestination(int startRow, int startCol, int endRow, int endCol, bool isBlack) {
    return startRow >= 0 && startCol >= 0 && endRow >= 0 && endCol >= 0 &&  // All values >= 0
            startRow < 8 && startCol < 8 && endRow < 8 && endCol < 8 && // All values < 8
            board[startRow][startCol] != nullptr && // Starting position must contain a piece
            board[startRow][startCol]->getIsBlack() == isBlack && // Starting piece must be the correct color
            (board[endRow][endCol] == nullptr || board[endRow][endCol]->getIsBlack() != isBlack); // Destination must be empty or opposite color
}

bool Board::verifyAdjacent(int startRow, int startCol, int endRow, int endCol) {
    return std::abs(endRow - startRow) <= 1 && std::abs(endCol - startCol) <= 1;
}

bool Board::verifyHorizontal(int startRow, int startCol, int endRow, int endCol) {
    if (startRow == endRow) {
        // Not a valid horizontal move if there is a piece between the source and destination.
        for (int i = std::min(startCol, endCol) + 1; i < std::max(startCol, endCol); i++) {
            if (board[startRow][i] != nullptr) {
                return false;
            }
        }
        // No pieces found between the source and destination (valid horizontal move).
        return true;
    }
    // Not a horizontal move.
    return false;
}

bool Board::verifyVertical(int startRow, int startCol, int endRow, int endCol) {
    if (startCol == endCol) {
        // Not a valid vertical move if there is a piece between the source and destination.
        for (int i = std::min(startRow, endRow) + 1; i < std::max(startRow, endRow); i++) {
            if (board[i][startCol] != nullptr) {
                return false;
            }
        }
        // No pieces found between the source and destination (valid vertical move).
        return true;
    }
    // Not a vertical move.
    return false;
}

bool Board::verifyDiagonal(int startRow, int startCol, int endRow, int endCol) {
    if (startRow + startCol == endRow + endCol) {
        // Not a valid diagonal move if there is a piece between the source and destination.
        for (int i = std::min(startRow, endRow) + 1; i < std::max(startRow, endRow); i++) {
            if (board[i][(startRow + startCol) - i] != nullptr) {
                return false;
            }
        }
        // No pieces found between the source and destination (valid diagonal move).
        return true;
    }
    else if (startRow - startCol == endRow - endCol) {
        // Not a valid diagonal move if there is a piece between the source and destination.
        for (int i = std::min(startRow, endRow) + 1; i < std::max(startRow, endRow); i++) {
            if (board[i][(startCol - startRow) + i] != nullptr) {
                return false;
            }
        }
        // No pieces found between the source and destination (valid diagonal move).
        return true;
    }
    // Not a diagonal move.
    return false;
}

// Game functionality methods
bool Board::movePiece(int startRow, int startCol, int endRow, int endCol) {
    if (board[startRow][startCol] != nullptr &&
        board[startRow][startCol]->isMoveLegal(this, endRow, endCol)) {
        board[endRow][endCol] = board[startRow][startCol];
        board[endRow][endCol]->setPosition(endRow, endCol);
        board[startRow][startCol] = nullptr;
        return true;
    }
    return false;
}

bool Board::isGameOver() {
    int counter = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != nullptr && (board[i][j]->getCharacter() == "\u2654" || board[i][j]->getCharacter() == "\u265a")) {
                counter++;
            }
        }
    }
    return counter != 2;
}

void Board::display() {
    std::cout << "\t\t\t";
    for (int i = 0; i < 8; i++) {
        std::cout << i << "\t\t";
    }
    std::cout << "\n";

    for (int i = 0; i < 8; i++) {
        std::cout << "\t" << i << "\t";
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == nullptr) {
                std::cout << "|\t\t";
            } else {
                std::cout << "|\t" << board[i][j]->toString() << "\t";
            }
        }
        std::cout << "|\n";
    }
}

void Board::clear() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete board[i][j];
        }
    }
}
