#include "main.h"

int main(void){
  SDL_Window * window;
  SDL_Renderer * renderer;
  CMP_Game *game_state;
  init_sdl_window(&window,&renderer);
  game_state = cmp_make_game(renderer, &grb_game_init);
  cmp_init_game_loop(&renderer, game_state);
  cmp_destroy_game(game_state);
  return 0;
}
