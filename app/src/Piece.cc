#include <utility>

#include "../lib/Piece.h"
#include "../lib/Board.h"
#include "../lib/Pawn.h"
#include "../lib/Rook.h"
#include "../lib/Knight.h"
#include "../lib/Bishop.h"
#include "../lib/Queen.h"
#include "../lib/King.h"

Piece::Piece(std::string character, int row, int col, bool isBlack)
    : character(std::move(character)), row(row), col(col), isBlack(isBlack) {}

bool Piece::isMoveLegal(Board* board, int endRow, int endCol) const {
    bool result = false;

    if (this->character == "\u2659" or this->character == "\u265f") { // Pawn
        auto pawn = std::make_unique<Pawn>(this->row, this->col, this->isBlack);
        result = pawn->isMoveLegal(board, endRow, endCol);
    }
    else if (this->character == "\u2656" or this->character == "\u265c") { // Rook
        auto rook = std::make_unique<Rook>(this->row, this->col, this->isBlack);
        result = rook->isMoveLegal(board, endRow, endCol);
    }
    else if(this->character == "\u265e" or this->character == "\u2658") { // Knight
        auto knight = std::make_unique<Knight>(this->row, this->col, this->isBlack);
        result = knight->isMoveLegal(board, endRow, endCol);
    }
    else if (this->character == "\u265d" or this->character == "\u2657") { // Bishop
        auto bishop = std::make_unique<Bishop>(this->row, this->col, this->isBlack);
        result = bishop->isMoveLegal(board, endRow, endCol);
    }
    else if (this->character == "\u265b" or this->character == "\u2655") { // Queen
        auto queen = std::make_unique<Queen>(this->row, this->col, this->isBlack);
        result = queen->isMoveLegal(board, endRow, endCol);
    }
    else if (this->character == "\u265a" or this->character == "\u2654") { // King
        auto king = std::make_unique<King>(this->row, this->col, this->isBlack);
        result = king->isMoveLegal(board, endRow, endCol);
    }
    return result;
}

void Piece::setPosition(int r, int c) {
    this->row = r;
    this->col = c;
    if (this->character == "\u2659" || this->character == "\u265f") {
        promotePawn(row, this->isBlack);
    }
}

void Piece::promotePawn(int row, bool isBlack) {
    if ((isBlack && row == 7) || (!isBlack && row == 0)) {
        std::cout << "Your pawn has braved the battlefield!\n"
                     "Honor them with a promotion: [r]ook, [b]ishop, [k]night, [q]ueen" << std::endl;

        char choice;
        do {
            std::cin >> choice;

            if (choice == 'r') {
                character = isBlack ? "\u265c" : "\u2656";
                return;
            } else if (choice == 'b') {
                this->character = isBlack ? "\u265d" : "\u2657";
                return;
            } else if (choice == 'k') {
                this->character = isBlack ? "\u265e" : "\u2658";
                return;
            }
            else if (choice == 'q') {
                this->character = isBlack ? "\u265b" : "\u2655";
                return;
            } else {
                std::cout << "Invalid choice. Please choose [r], [b], [k], or [q]." << std::endl;
            }
        } while (true);  // This loop will continue until a valid choice is made
    }
}

std::string Piece::getCharacter() const {
    return this->character;
}

bool Piece::getIsBlack() const {
    return this->isBlack;
}

std::string Piece::toString() const {
    return "" + this->character;
}
