typedef enum
{
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} PIECE_TYPE;

typedef enum
{
    BLACK,
    WHITE
} PIECE_COLOR;

typedef struct
{
    PIECE_TYPE type;
    PIECE_COLOR color;
} PIECE;

void init_board();