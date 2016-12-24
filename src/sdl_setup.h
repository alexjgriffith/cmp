#include "SDL.h"
#include "window-details.h"
#include "game.h"

void init_sdl_window(SDL_Window ** window,
		     SDL_Renderer **  renderer);


void cmp_game_read(SDL_Event * event,CMP_Game * game_state);

void cmp_game_render(SDL_Renderer **  renderer,CMP_Game * game_state);

void cmp_game_eval(CMP_Game * game_state);

void cmp_init_game_loop(SDL_Renderer ** renderer,CMP_Game * game_state);

void cmp_mouse_input(SDL_Event * event,CMP_Game * game_state);

void cmp_keyboard_input(SDL_Event * event,CMP_Game * game_state);
