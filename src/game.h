#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#ifndef _CMP_GAME
//#include <grb.h>

typedef struct CMP_Obj CMP_Obj;
typedef struct CMP_SDL_Sprite CMP_SDL_Sprite;
typedef struct CMP_Game CMP_Game;

/*
// Proposed Alternative

struct CMP_SDL_Animation{
  int empty;
  SDL_Rect ** animations;
  int n_animations;
  int max_animations;
};

// One animation per texture
struct CMP_SDL_Sprite{
  int empty;
  int n_textures;
  char ** texture_names;
  SDL_Texture ** textures;  
  CMP_SDL_Animation ** animations;
  int n_animations;
  int max_animations;
};


 */
struct CMP_SDL_Sprite{
  int empty;
  SDL_Texture * texture;  
  SDL_Rect ** animations;
  int * l_animations;
  int n_animations;
  int max_animations;
};

struct CMP_Obj{
  double location[2];
  int state; // One state for each animation
             // Can make this more complex later
  int step;
  CMP_SDL_Sprite sprite;
  int rendering;
  void (* render)(SDL_Renderer *, CMP_Obj *);
};

struct CMP_Game{
  int quit;
  CMP_Obj ** objects;  
  int n_objects;
  int max_objects; //before having to realloc objects
};

CMP_Game * cmp_make_game(SDL_Renderer * renderer, void (*init_fun)(SDL_Renderer *,CMP_Game *));

void cmp_game_add_obj(CMP_Game * game,CMP_Obj *obj);

void cmp_game_render_objs(CMP_Game * game,SDL_Renderer * renderer);

void cmp_destroy_game(CMP_Game * game);

CMP_Obj * cmp_make_obj(void (* render)(SDL_Renderer *, CMP_Obj *));

void cmp_obj_add_render_function(CMP_Obj * obj,void (* render)(SDL_Renderer *, CMP_Obj *));

void cmp_destroy_obj(CMP_Obj * obj);

CMP_SDL_Sprite  cmp_make_sdl_sprite(SDL_Renderer * renderer,const char * image);

void cmp_sprite_add_animation(CMP_SDL_Sprite * sprite, SDL_Rect * animation,int l_animation);

SDL_Rect cmp_sprite_get_rect(CMP_SDL_Sprite * sprite,int state, int step);

void cmp_destroy_sdl_sprite(CMP_SDL_Sprite * sprite);

#define _CMP_GAME
#endif
