#include <iostream>
#include <string>
#include <sstream>

#include "lib/Bishop.h"
#include "lib/Board.h"
#include "lib/Fen.h"
#include "lib/King.h"
#include "lib/Knight.h"
#include "lib/Pawn.h"
#include "lib/Piece.h"
#include "lib/Queen.h"
#include "lib/Rook.h"

int main() {
    // Create a board
    Board board;

    // Testing purposes, loading the board with FEN notation.
    // Fen::populate("8/3P3/8/8/8/8/3p3/8", board);

    // Starting position:
     Fen::populate("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", board);

    bool isBlackTurn = false;
    std::string input;

    // Welcome the user to the game.
    std::cout << "Welcome to Chess!\n\nEnter 'exit' to quit.\n";

    // Continue playing while the game is not over.
    while (!board.isGameOver()) {
        // Display the board.
        std::cout << "\nBoard:\n";
        board.display();

        // Inform the user whose turn it is.
        if (!isBlackTurn) {
            std::cout << "\nIt is currently white's turn to play.\n";
        } else {
            std::cout << "\nIt is currently black's turn to play.\n";
        }

        // Gather move information from the user.
        std::cout << "What is your move? (format: [start row] [start col] [end row] [end col])\n";
        std::getline(std::cin, input);
        if (input == "exit") break;

        std::istringstream iss(input);

        int startRow, startCol, endRow, endCol;
        if (iss >> startRow >> startCol >> endRow >> endCol) {
            // Continue gathering input if the user input is invalid.
            while (!(board.getPiece(startRow, startCol) != nullptr &&
                     board.getPiece(startRow, startCol)->getIsBlack() == isBlackTurn &&
                     board.movePiece(startRow, startCol, endRow, endCol))) {
                std::cout << "\nInvalid Move! Try again!\n";
                std::cout << "What is your move? (format: [start row] [start col] [end row] [end col])\n";
                std::getline(std::cin, input);
                if (input == "exit") break;
                std::istringstream newIss(input);
                newIss >> startRow >> startCol >> endRow >> endCol;
            }
        } else {
            std::cout << "Invalid input format. Please try again.\n";
        }

        // Switch players at the end of the turn.
        isBlackTurn = !isBlackTurn;
    }

    return 0;
}