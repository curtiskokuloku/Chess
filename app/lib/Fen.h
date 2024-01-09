
#ifndef FEN_H
#define FEN_H

#include <iostream>
#include <string>
#include <unordered_map>

class Board;
class Piece;

class Fen {
public:
    /**
     * Method for populating a Board object with chess
     * pieces based on the FEN src passed in.
     *
     * @param fen A FEN src string. Must not include
     *            move commands or erroneous characters
     * @param b A Board object to load with chess
     *             position
     */
    static void populate(const std::string& fen, Board& b);
};

#endif //FEN_H
