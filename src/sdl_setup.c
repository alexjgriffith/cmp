#include "sdl_setup.h"

void init_sdl_window(SDL_Window ** window,
		     SDL_Renderer **  renderer){
  // Initialize the SDL enviromnet
  if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
    perror("broken");
    exit(1);
  }
  * window = SDL_CreateWindow("SDL Tutorial",
			      SDL_WINDOWPOS_UNDEFINED,
			      SDL_WINDOWPOS_UNDEFINED,
			      WIDTH,
			      HEIGHT,
			      SDL_WINDOW_SHOWN
			      );
  // Generate the renderer, arg 1 argument -1 will select
  // the first renderer that matches arg 2
  *renderer = SDL_CreateRenderer(*window, -1,
				 SDL_RENDERER_ACCELERATED |
				 SDL_RENDERER_PRESENTVSYNC);
  // Set the default draw colour
  SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
}

void cmp_mouse_input(SDL_Event * event,CMP_Game * game_state){
  return;
}

void cmp_keyboard_input(SDL_Event * event,CMP_Game * game_state){
  return;
}

void cmp_game_read(SDL_Event * event,CMP_Game * game_state){
  while(SDL_PollEvent( event ) != 0){
    switch(event->type){
    case SDL_MOUSEBUTTONDOWN:	
    case SDL_MOUSEBUTTONUP:
      cmp_mouse_input(event,game_state);
      break;
    case SDL_KEYDOWN:
    case SDL_KEYUP:
      cmp_keyboard_input(event,game_state);
      break;
    case SDL_QUIT:
      game_state->quit=1;
      break;
    default:
      break;      
    }
  }
  return;
}

void cmp_game_render(SDL_Renderer **  renderer,CMP_Game *game_state){
  SDL_SetRenderDrawColor( *renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderFillRect(*renderer,NULL);
  cmp_game_render_objs(game_state,*renderer);
  // grb_render_temp(renderer,game_state);
  //printf("rendering\n");
  SDL_RenderPresent(*renderer);
  return;
}

void cmp_game_eval(CMP_Game * game_state){
  
  return;
}

void cmp_init_game_loop(SDL_Renderer ** renderer,CMP_Game * game_state){
  SDL_Event event;
  game_state->quit=0;
  while(! game_state->quit){
    cmp_game_render(renderer,game_state);
    cmp_game_read(&event,game_state);
    cmp_game_eval(game_state);
    SDL_Delay(200);
  }
}
