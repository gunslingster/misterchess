#include "chess.h"

extern PIECE_TYPE BOARD[8][8];

void main()
{
    init_board();
    render_board(BOARD);
}