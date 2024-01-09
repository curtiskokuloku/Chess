
#ifndef PAWN_H
#define PAWN_H

// Forward declaration of Board class
class Board;

class Pawn {
public:
    /**
     * Constructor.
     * @param row       The current row of the pawn.
     * @param col       The current column of the pawn.
     * @param isBlack   The color of the pawn.
     */
    Pawn(int row, int col, bool isBlack);

    /**
     * Checks if a move to a destination square is legal.
     * @param board     The game board.
     * @param endRow    The row of the destination square.
     * @param endCol    The column of the destination square.
     * @return True if the move to the destination square is legal, false otherwise.
     */
    bool isMoveLegal(Board* board, int endRow, int endCol);

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

#endif //PAWN_H
