#include <stdint.h>
#include "chess.h"

PIECE BOARD[8][8] = {0};

void init_board()
{
    for (int i = 0; i < 8; i++)
    {
        BOARD[1][i].type = PAWN;
        BOARD[1][i].color = WHITE;
        BOARD[6][i].type = PAWN;
        BOARD[6][i].color = BLACK;
    }

    BOARD[0][0].type = ROOK;
    BOARD[0][0].color = WHITE;
    BOARD[0][7].type = ROOK;
    BOARD[0][7].color = WHITE;
    BOARD[0][1].type = KNIGHT;
    BOARD[0][1].color = WHITE;
    BOARD[0][6].type = KNIGHT;
    BOARD[0][6].color = WHITE;
    BOARD[0][2].type = BISHOP;
    BOARD[0][2].color = WHITE;
    BOARD[0][5].type = BISHOP;
    BOARD[0][5].color = WHITE;
    BOARD[0][3].type = QUEEN;
    BOARD[0][3].color = WHITE;
    BOARD[0][4].type = KING;
    BOARD[0][3].color = WHITE;

    BOARD[7][0].type = ROOK;
    BOARD[7][0].color = WHITE;
    BOARD[7][7].type = ROOK;
    BOARD[7][7].color = WHITE;
    BOARD[7][1].type = KNIGHT;
    BOARD[7][1].color = WHITE;
    BOARD[7][6].type = KNIGHT;
    BOARD[7][6].color = WHITE;
    BOARD[7][2].type = BISHOP;
    BOARD[7][2].color = WHITE;
    BOARD[7][5].type = BISHOP;
    BOARD[7][5].color = WHITE;
    BOARD[7][3].type = QUEEN;
    BOARD[7][3].color = WHITE;
    BOARD[7][4].type = KING;
    BOARD[7][3].color = WHITE;
}