
#ifndef ROOK_H
#define ROOK_H

// Forward declaration of Board class
class Board;

class Rook {
public:
    /**
     * Constructor.
     * @param row       The current row of the rook.
     * @param col       The current column of the rook.
     * @param isBlack   The color of the rook.
     */
    Rook(int row, int col, bool isBlack);

    /**
     * Checks if a move to a destination square is legal.
     * @param board     The game board.
     * @param endRow    The row of the destination square.
     * @param endCol    The column of the destination square.
     * @return True if the move to the destination square is legal, false otherwise.
     */
    bool isMoveLegal(Board* board, int endRow, int endCol) const;

private:
    /**
     * Current row on the board
     */
    int row;

    /**
     * Current column on the board
     */
    int col;

    /**
     * Determines if the Pawn is black or white
     */
    bool isBlack;
};

#endif //ROOK_H
