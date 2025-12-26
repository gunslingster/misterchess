#ifndef CHESS_H
#define CHESS_H

#include <stdio.h>

typedef enum
{
    EMPTY,
    WHITE_PAWN,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_ROOK,
    WHITE_QUEEN,
    WHITE_KING,
    BLACK_PAWN,
    BLACK_KNIGHT,
    BLACK_BISHOP,
    BLACK_ROOK,
    BLACK_QUEEN,
    BLACK_KING,
} PIECE_TYPE;

typedef struct
{
    int active;
    int row, col;
    PIECE_TYPE piece;
} Selection;

void init_board();

#endif // CHESS_H