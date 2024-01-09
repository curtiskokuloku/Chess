
#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <string>

class Board;
class Pawn;
class Rook;
class Knight;
class Bishop;
class Queen;
class King;


class Piece {
public:
    /**
     * Constructor.
     * @param character     The character representing the piece.
     * @param row           The row on the board the piece occupies.
     * @param col           The column on the board the piece occupies.
     * @param isBlack       The color of the piece.
     */
    Piece(std::string character, int row, int col, bool isBlack);

    /**
     * Determines if moving this piece is legal.
     * @param board     The current state of the board.
     * @param endRow    The destination row of the move.
     * @param endCol    The destination column of the move.
     * @return If the piece can legally move to the provided destination on the board.
     */
    bool isMoveLegal(Board* board, int endRow, int endCol) const;

    /**
     * Sets the position of the piece.
     * @param row   The row to move the piece to.
     * @param col   The column to move the piece to.
     */
    void setPosition(int row, int col);

    /**
     * Handle promotion of a pawn.
     * @param row Current current_row of the pawn
     * @param isBlack Color of the pawn
     */
    void promotePawn(int row, bool isBlack);

    /**
     * Returns the current chess unicode character.
     * @return Unicode character.
     */
    [[nodiscard]] std::string getCharacter() const;


    /**
     * Return the color of the piece.
     * @return  The color of the piece.
     */
    [[nodiscard]] bool getIsBlack() const;

    /**
     * Returns a string representation of the piece.
     * @return  A string representation of the piece.
     */
    [[nodiscard]] std::string toString() const;

private:
    /**
     * Character (fen code) of current piece
     */
    std::string character;

    /**
     * Current row on the board of the current piece
     */
    int row;

    /**
     * Current column on the board of the current piece
     */
    int col;

    /**
     * Boolean to determine if the current piece is a black or white piece
     */
    bool isBlack;
};

#endif //PIECE_H
