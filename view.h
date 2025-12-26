#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "chess.h"

#define SQUARE_SIZE 64
#define PIECE_SIZE 64
#define TARGET_FPS 60
#define FRAME_TIME_MS (1000 / TARGET_FPS)


void view_load_piece_textures(SDL_Renderer *r);
void view_render_board(SDL_Renderer *r, PIECE_TYPE board[8][8]);
void view_render_selection(SDL_Renderer *r, Selection sel);

#endif // VIEW_H