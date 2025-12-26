// THIS IS THE FRONT END. SDL2

#include "view.h"
#include "chess.h"

SDL_Texture *piece_tex[13] = {0};
SDL_Texture *board_tex[2] = {0};

static SDL_Texture *load_png(SDL_Renderer *r, const char *path)
{
    SDL_Surface *s = IMG_Load(path);
    if (!s)
    {
        printf("IMG_Load failed: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Texture *t = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    return t;
}

void view_load_piece_textures(SDL_Renderer *r)
{
    piece_tex[WHITE_PAWN] = load_png(r, "assets/wp.png");
    piece_tex[WHITE_KNIGHT] = load_png(r, "assets/wn.png");
    piece_tex[WHITE_BISHOP] = load_png(r, "assets/wb.png");
    piece_tex[WHITE_ROOK] = load_png(r, "assets/wr.png");
    piece_tex[WHITE_QUEEN] = load_png(r, "assets/wq.png");
    piece_tex[WHITE_KING] = load_png(r, "assets/wk.png");

    piece_tex[BLACK_PAWN] = load_png(r, "assets/bp.png");
    piece_tex[BLACK_KNIGHT] = load_png(r, "assets/bn.png");
    piece_tex[BLACK_BISHOP] = load_png(r, "assets/bb.png");
    piece_tex[BLACK_ROOK] = load_png(r, "assets/br.png");
    piece_tex[BLACK_QUEEN] = load_png(r, "assets/bq.png");
    piece_tex[BLACK_KING] = load_png(r, "assets/bk.png");

    board_tex[0] = load_png(r, "assets/board_light.png");
    board_tex[1] = load_png(r, "assets/board_dark.png");
}

void view_render_board(SDL_Renderer *r, PIECE_TYPE board[8][8])
{
    SDL_Rect sq = {0, 0, SQUARE_SIZE, SQUARE_SIZE};
    SDL_Rect dst;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            sq.x = col * SQUARE_SIZE;
            sq.y = row * SQUARE_SIZE;

            /* ---- draw square ---- */
            int dark = (row + col) & 1;
            SDL_RenderCopy(r, board_tex[dark], NULL, &sq);

            /* ---- draw piece (if any) ---- */
            PIECE_TYPE p = board[row][col];
            if (p)
            {
                SDL_Texture *tex = piece_tex[p];
                if (!tex)
                    continue;

                int w, h;
                SDL_QueryTexture(tex, NULL, NULL, &w, &h);

                dst.w = PIECE_SIZE;
                dst.h = PIECE_SIZE;
                dst.x = sq.x + (SQUARE_SIZE - PIECE_SIZE) / 2;
                dst.y = sq.y + (SQUARE_SIZE - PIECE_SIZE) / 2;

                SDL_RenderCopy(r, tex, NULL, &dst);
            }
        }
    }
}

void view_render_selection(SDL_Renderer *r, Selection sel)
{
    if (!sel.active)
        return;

    SDL_Rect rect = {
        sel.col * SQUARE_SIZE,
        sel.row * SQUARE_SIZE,
        SQUARE_SIZE,
        SQUARE_SIZE};

    SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(r, 0, 120, 255, 80);
    SDL_RenderFillRect(r, &rect);
}
