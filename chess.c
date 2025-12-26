// THIS IS THE CHESS ENGINE

#include <stdint.h>
#include "chess.h"

PIECE_TYPE BOARD[8][8] = {0};
Selection sel = {0};

void init_board()
{
    for (int i = 0; i < 8; i++)
    {
        BOARD[1][i] = WHITE_PAWN;
        BOARD[6][i] = BLACK_PAWN;
    }

    BOARD[0][0] = WHITE_ROOK;
    BOARD[0][7] = WHITE_ROOK;
    BOARD[0][1] = WHITE_KNIGHT;
    BOARD[0][6] = WHITE_KNIGHT;
    BOARD[0][2] = WHITE_BISHOP;
    BOARD[0][5] = WHITE_BISHOP;
    BOARD[0][4] = WHITE_QUEEN;
    BOARD[0][3] = WHITE_KING;

    BOARD[7][0] = BLACK_ROOK;
    BOARD[7][7] = BLACK_ROOK;
    BOARD[7][1] = BLACK_KNIGHT;
    BOARD[7][6] = BLACK_KNIGHT;
    BOARD[7][2] = BLACK_BISHOP;
    BOARD[7][5] = BLACK_BISHOP;
    BOARD[7][4] = BLACK_QUEEN;
    BOARD[7][3] = BLACK_KING;
}

static inline int is_black_piece(PIECE_TYPE p)
{
    return p >= BLACK_PAWN;
}