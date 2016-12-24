#ifndef _CMP_GRB
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "game.h"

void grb_render_temp(SDL_Renderer * renderer,CMP_Obj * obj);

void grb_add_sprite_sheet(SDL_Renderer *renderer, CMP_Game * game, const char * image);

void grb_add_sprite(SDL_Renderer * renderer, const char * filename, CMP_Game * game_state,void (* render)(SDL_Renderer *, CMP_Obj *));
  
void grb_game_init(SDL_Renderer * renderer,CMP_Game * game_state);
#define _CMP_GRB
#endif
