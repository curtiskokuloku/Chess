
#ifndef FEN_H
#define FEN_H

#include <iostream>
#include <string>
#include <unordered_map>

class Board;
class Piece;

class Fen {
/**
 * The Fen class was designed to load an object of type
 * Board with any chess board state given a proper
 * Forsyth-Edwards Notation code.
 *
 * Example FEN codes:
 * empty board: "8/8/8/8/8/8/8/8"
 * starting pos: "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"
 * smiley: "8/8/2K2K2/8/2Q2Q2/2Q2Q2/3QQ3/8"
 * "The Immortal Game" ending pos: "r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1"
 */
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
