cmake_minimum_required(VERSION 3.26)
project(app)

set(CMAKE_CXX_STANDARD 17)

add_executable(app main.cpp
        lib/Fen.h
        lib/Board.h
        lib/Bishop.h
        lib/King.h
        lib/Knight.h
        lib/Pawn.h
        lib/Piece.h
        lib/Queen.h
        lib/Rook.h
        src/Bishop.cpp
        src/Board.cc
        src/Fen.cc
        src/King.cc
        src/Knight.cc
        src/Pawn.cc
        src/Piece.cc
        src/Queen.cc
        src/Rook.cc
)
