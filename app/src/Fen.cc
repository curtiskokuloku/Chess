#include "../lib/Fen.h"
#include "../lib/Board.h"
#include "../lib/Piece.h"

void Fen::populate(const std::string& fen, Board& b) {
        int rank = 0;   // Rank or row of the board
        int square = 0; // Square in 'rank'

        // Create an unordered map (similar to hash map)
        std::unordered_map<char, std::string> pieceMapping = {
            {'p', "\u265f"}, {'P', "\u2659"}, {'r', "\u265c"}, {'R', "\u2656"},
            {'n', "\u265e"}, {'N', "\u2658"}, {'b', "\u265d"}, {'B', "\u2657"},
            {'q', "\u265b"}, {'Q', "\u2655"}, {'k', "\u265a"}, {'K', "\u2654"}
        };
        // Iterate over FEN code chars, updating Board object accordingly
        for (char query : fen) {
            // If a '/': proceed to next row
            if (query == '/') {
                rank++;
                square = 0;
            }
            // If a digit, n: proceed n squares forward
            else if (isdigit(query)) {
                square += query - '0'; // Convert char to int
            }
            else { // Consult the map
                auto iter = pieceMapping.find(query);
                if (iter != pieceMapping.end()) {
                    b.setPiece(rank, square, new Piece(iter->second, rank, square, !isupper(query)));
                    square++; // Increment square after placing the piece
                }
            }
        }
    }