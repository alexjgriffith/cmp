#include "game.h"

CMP_Game * cmp_make_game(SDL_Renderer * renderer, void (*init_fun)(SDL_Renderer *,CMP_Game *)){
  CMP_Game * game = malloc(sizeof(game));
  game->quit=0;
  game->n_objects=0;
  game->max_objects=100;
  game->objects = malloc(sizeof(CMP_Obj *)*game->max_objects);
  init_fun(renderer,game);
  return game;
};

void cmp_game_add_obj(CMP_Game * game,CMP_Obj *obj){
  if(game->n_objects>=game->max_objects){
    perror("ERROR cmp_game_add_obj object length is greater than alloced");
    exit(1);
  }
  game->objects[game->n_objects]=obj;
  game->n_objects+=1;
}

void cmp_game_render_objs(CMP_Game * game,SDL_Renderer * renderer){
  int i;
  for(i=0;i<game->n_objects;i++)
    if(game->objects[i]->rendering)
      game->objects[i]->render(renderer,game->objects[i]);
}

void cmp_destroy_game(CMP_Game * game){
  int i;
  for(i=0;i<game->n_objects;i++)
    cmp_destroy_obj(game->objects[i]);
  free(game->objects);
  free(game);
}

CMP_Obj * cmp_make_obj(void (* render)(SDL_Renderer *, CMP_Obj *)){
  CMP_Obj * obj  = malloc(sizeof(CMP_Obj));
  obj->state=-1; // NULL State
  obj->step=0;
  obj->sprite.empty = 1;
  if(render == NULL){
    obj->rendering=0;
    obj->render=NULL;
  }
  else{
    obj->rendering=1;
    obj->render=render;
  }
  return obj;
}

void cmp_obj_add_render_function(CMP_Obj * obj,
				 void (* render)(SDL_Renderer *, CMP_Obj *)){
  if(render == NULL){
    perror("ERROR cmp_obj_add_render_function was passed NULL");
    exit(0);
  }
    obj->rendering=1;
    obj->render=render;
    return;
}

void cmp_destroy_obj(CMP_Obj * obj){
  free(obj);
}

CMP_SDL_Sprite  cmp_make_sdl_sprite(SDL_Renderer * renderer,const char * image){
  CMP_SDL_Sprite  sprite;
  SDL_Surface* loadedSurface = IMG_Load(image);
  if(loadedSurface==NULL){
    perror("ERROR IMG_Load failed to load");
    exit(1);
  }
  sprite.max_animations=100;
  sprite.animations=malloc(sizeof(SDL_Rect *)*sprite.max_animations);
  sprite.l_animations=malloc(sizeof(int)*sprite.max_animations);
  sprite.empty=1;
  sprite.texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
  sprite.n_animations=0;
  SDL_FreeSurface(loadedSurface);
  return sprite;
}

void cmp_sprite_add_animation(CMP_SDL_Sprite * sprite, SDL_Rect * animation,int l_animation){
  int i;
  int n=sprite->n_animations+1;
  if(sprite->n_animations>=sprite->max_animations){
    perror("ERROR cmp_sprite_add_animation too many animations");
    exit(1);
  }
  sprite->animations[n]=malloc(sizeof(SDL_Rect)*l_animation);
  for(i=0;i<l_animation;i++){
    sprite->animations[n][i].x=animation[i].x;
    sprite->animations[n][i].y=animation[i].y;
    sprite->animations[n][i].w=animation[i].w;
    sprite->animations[n][i].h=animation[i].h;
  }
  sprite->n_animations+=1;
  return;
}

SDL_Rect cmp_sprite_get_rect(CMP_SDL_Sprite * sprite,int state, int step){
  return sprite->animations[state][step];
}

// last key step
//void cmp_destroy_sdl_sprite(CMP_SDL_Sprite * sprite);
