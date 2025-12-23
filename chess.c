#include <stdint.h>
#include "chess.h"

PIECE_TYPE BOARD[8][8] = {0};
char utf8_lookup[13][8] = {"", "\u2659", "\u2658", "\u2657", "\u2656", "\u2655", "\u2654", "\u265F", "\u265E", "\u265D", "\u265C", "\u265B", "\u265A"};

void init_board()
{
    for (int i = 0; i < 8; i++)
    {
        BOARD[1][i] = WHITE_PAWN;
        BOARD[6][i] = BLACK_PAWN;
    }

    BOARD[0][0] = WHITE_ROOK;
    // BOARD[0][0].repr = "\u2656";
    BOARD[0][7] = WHITE_ROOK;
    // BOARD[0][7].repr = "\u2656";
    BOARD[0][1] = WHITE_KNIGHT;
    // BOARD[0][1].repr = "\u2658";
    BOARD[0][6] = WHITE_KNIGHT;
    // BOARD[0][6].repr = "\u2658";
    BOARD[0][2] = WHITE_BISHOP;
    // BOARD[0][2].repr = "\u2657";
    BOARD[0][5] = WHITE_BISHOP;
    // BOARD[0][5].repr = "\u2657";
    BOARD[0][3] = WHITE_QUEEN;
    // BOARD[0][3].repr = "\u2655";
    BOARD[0][4] = WHITE_KING;
    // BOARD[0][4].repr = "\u2654";

    BOARD[7][0] = BLACK_ROOK;
    // BOARD[7][0].repr = "\u265C";
    BOARD[7][7] = BLACK_ROOK;
    // BOARD[7][7].repr = "\u265C";
    BOARD[7][1] = BLACK_KNIGHT;
    // BOARD[7][1].repr = "\u265E";
    BOARD[7][6] = BLACK_KNIGHT;
    // BOARD[7][6].repr = "\u265E";
    BOARD[7][2] = BLACK_BISHOP;
    // BOARD[7][2].repr = "\u265D";
    BOARD[7][5] = BLACK_BISHOP;
    // BOARD[7][5].repr = "\u265D";
    BOARD[7][3] = BLACK_QUEEN;
    // BOARD[7][3].repr = "\u265B";
    BOARD[7][4] = BLACK_KING;
    // BOARD[7][4].repr = "\u265A";
}

void render_board(PIECE_TYPE board[8][8])
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (board[r][c])
            {
                printf(" %s", utf8_lookup[board[r][c]]);
            }
            else
            {
                printf("%s", ((r + c) % 2) ? "██" : "  ");
            }
        }
        printf("\n");
    }
}