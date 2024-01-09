
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <cmath>

#include "../lib/Piece.h"

class Board {
public:
    /**
     * Default Constructor
     */
    Board();

    // Accessor Methods

    /**
     * Gets the piece at a particular row and column of the board.
     * @param row       The row of the piece to be accessed.
     * @param col       The column of the piece to be accessed.
     * @return          The piece at the specified row and column of the board.
     */
    [[nodiscard]] Piece* getPiece(int row, int col) const;

    /**
     * Sets the piece at a particular row and column of the board.
     * @param row       The row to place the piece at.
     * @param col       The column to place the piece at.
     * @param piece     The piece to place at the specified row and column.
     */
    void setPiece(int row, int col, Piece* piece);

    // Movement helper functions

    /**
     * Verifies that the source and destination of a move are valid by performing the following checks:
     *  1. All rows and columns provided must be >= 0.
     *  2. All rows and columns provided must be < 8.
     *  3. The start position of the move must contain a piece.
     *  4. The piece at the starting position must be the correct color.
     *  5. The destination must be empty OR must contain a piece of the opposite color.
     * @param startRow  The starting row of the move.
     * @param startCol  The starting column of the move.
     * @param endRow    The ending row of the move.
     * @param endCol    The ending column of the move.
     * @param isBlack   The expected color of the starting piece.
     * @return True if the above conditions are met, false otherwise.
     */
    bool verifySourceAndDestination(int startRow, int startCol, int endRow, int endCol, bool isBlack);

    /**
     * Verifies that the source and destination of a move are adjacent squares (within 1 square of each other)
     * @param startRow  The starting row of the move.
     * @param startCol  The starting column of the move.
     * @param endRow    The ending row of the move.
     * @param endCol    The ending column of the move.
     * @return True if the source and destination squares are adjacent, false otherwise.
     */
    static bool verifyAdjacent(int startRow, int startCol, int endRow, int endCol);

    /**
     * Verifies that a source and destination are in the same row and that there are no pieces on squares
     * between the source and the destination.
     * @param startRow  The starting row of the move.
     * @param startCol  The starting column of the move.
     * @param endRow    The ending row of the move.
     * @param endCol    The ending column of the move.
     * @return True if source and destination are in same row with no pieces between them, false otherwise.
     */
    bool verifyHorizontal(int startRow, int startCol, int endRow, int endCol);

    /**
     * Verifies that a source and destination are in the same column and that there are no pieces on squares
     * between the source and the destination.
     * @param startRow  The starting row of the move.
     * @param startCol  The starting column of the move.
     * @param endRow    The ending row of the move.
     * @param endCol    The ending column of the move.
     * @return True if source and destination are in same column with no pieces between them, false otherwise.
     */
    bool verifyVertical(int startRow, int startCol, int endRow, int endCol);

    /**
     * Verifies that a source and destination are on the same diagonal and that there are no pieces on squares
     * between the source and the destination.
     * @param startRow  The starting row of the move.
     * @param startCol  The starting column of the move.
     * @param endRow    The ending row of the move.
     * @param endCol    The ending column of the move.
     * @return True if source and destination are on the same diagonal with no pieces between them, false otherwise.
     */
    bool verifyDiagonal(int startRow, int startCol, int endRow, int endCol);

    // Game functionality methods

    /**
     * Moves the piece from startRow, startCol to endRow, endCol if it is legal to do so.
     * @param startRow  The starting row of the move.
     * @param startCol  The starting column of the move.
     * @param endRow    The ending row of the move.
     * @param endCol    The ending column of the move.
     * @return Whether the move was successfully completed or not. (Moves are not completed if they are not legal.)
     */
    bool movePiece(int startRow, int startCol, int endRow, int endCol);

    /**
     * Returns if the game is currently over.
     * @return      If the game is in a game over state.
     */
    bool isGameOver();

    /**
     * Prints out a string representation of the board to the terminal.
     */
    void display();

    /**
     * Removes every piece from the board.
     */
    void clear();

private:
    /**
     * 2D vector to represent the board
     */
    std::vector<std::vector<Piece*>> board;
};

#endif //BOARD_H
