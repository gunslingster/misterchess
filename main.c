#include "chess.h"
#include "view.h"

extern PIECE_TYPE BOARD[8][8];
extern Selection sel;

static inline int mouse_to_row(int y) { return y / SQUARE_SIZE; }
static inline int mouse_to_col(int x) { return x / SQUARE_SIZE; }
static inline int same_color(PIECE_TYPE a, PIECE_TYPE b)
{
    if (!a || !b)
        return 0;
    return (a >= BLACK_PAWN) == (b >= BLACK_PAWN);
}

void main()
{
    init_board();
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window *win = SDL_CreateWindow(
        "Chess",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        8 * SQUARE_SIZE,
        8 * SQUARE_SIZE,
        SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer =
        SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    view_load_piece_textures(renderer);

    int running = 1;
    Uint32 frame_start;
    Uint32 frame_time;

    while (running)
    {
        frame_start = SDL_GetTicks();

        /* ---- events ---- */
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case (SDL_QUIT):
            {
                running = 0;
                break;
            }

            case SDL_MOUSEBUTTONDOWN:
            {
                if (e.button.button != SDL_BUTTON_LEFT)
                    break;

                int col = mouse_to_col(e.button.x);
                printf("button x: %d\n", e.button.x);
                printf("col: %d\n", col);
                int row = mouse_to_row(e.button.y);
                printf("button y: %d\n", e.button.y);
                printf("row: %d\n", row);

                if (row < 0 || row > 7 || col < 0 || col > 7)
                    break;

                PIECE_TYPE clicked = BOARD[row][col];

                /* ---- nothing selected yet ---- */
                if (!sel.active)
                {
                    if (clicked)
                    {
                        sel.active = 1;
                        sel.row = row;
                        sel.col = col;
                        sel.piece = clicked;
                    }
                    break;
                }

                /* ---- something already selected ---- */

                /* clicking same square → deselect */
                if (row == sel.row && col == sel.col)
                {
                    sel.active = 0;
                    break;
                }

                /* clicking another piece of same color → change selection */
                if (clicked && same_color(clicked, sel.piece))
                {
                    sel.row = row;
                    sel.col = col;
                    sel.piece = clicked;
                    break;
                }

                /* ---- attempt move ---- */
                // TODO: validate move via engine
                BOARD[sel.row][sel.col] = EMPTY;
                BOARD[row][col] = sel.piece;

                sel.active = 0;
                break;
            }
            }
        }

        /* ---- render ---- */
        SDL_RenderClear(renderer);
        view_render_board(renderer, BOARD);
        view_render_selection(renderer, sel);
        SDL_RenderPresent(renderer);

        /* ---- frame limiting ---- */
        frame_time = SDL_GetTicks() - frame_start;

        if (frame_time < FRAME_TIME_MS)
            SDL_Delay(FRAME_TIME_MS - frame_time);
    }
}