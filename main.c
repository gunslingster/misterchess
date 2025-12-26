#include "chess.h"
#include "view.h"

extern PIECE_TYPE BOARD[8][8];

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
            if (e.type == SDL_QUIT)
                running = 0;
        }

        /* ---- update (game logic) ---- */
        // For chess, this can be empty or input-driven

        /* ---- render ---- */
        SDL_RenderClear(renderer);
        view_render_board(renderer, BOARD);
        SDL_RenderPresent(renderer);

        /* ---- frame limiting ---- */
        frame_time = SDL_GetTicks() - frame_start;

        if (frame_time < FRAME_TIME_MS)
            SDL_Delay(FRAME_TIME_MS - frame_time);
    }
}