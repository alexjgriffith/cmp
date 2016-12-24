#include "grb.h"

void grb_game_init(SDL_Renderer * renderer,CMP_Game * game_state){
  grb_add_sprite(renderer,"/Users/agriffith/Dropbox/game/Universal-LPC-spritesheet/body/male/light.png", game_state, &grb_render_temp);
  
  grb_add_sprite(renderer,"/Users/agriffith/Dropbox/game/Universal-LPC-spritesheet/body/male/eyes/brown.png", game_state, &grb_render_temp);
  
  grb_add_sprite(renderer,"/Users/agriffith/Dropbox/game/Universal-LPC-spritesheet/torso/leather/chest_male.png", game_state, &grb_render_temp);  
  return;
}

void grb_add_sprite(SDL_Renderer * renderer, const char * filename, CMP_Game * game_state,void (* render)(SDL_Renderer *, CMP_Obj *)){
  CMP_Obj *obj = cmp_make_obj(render);
  obj->state=0;
  obj->sprite = cmp_make_sdl_sprite(renderer,filename);  
  cmp_game_add_obj(game_state,obj);
}

void grb_render_temp(SDL_Renderer * renderer,CMP_Obj * obj){
  SDL_Rect source,dest;
  //static int i=0,j=0;
  int i=obj->step , j=obj->state;
  int shift = 4*2+3;
  if(j==0)
    j=shift;
  if(obj->state<0)
    return;
  source.x=64*i;
  source.y=64*j;
  source.w=64;
  source.h=64;  

  dest.x=64*3;
  dest.y=64*3;
  dest.w=64;
  dest.h=64;
  SDL_RenderCopy(renderer,obj->sprite.texture,&source,&dest);
  if(i<8){
    i++;
  }
  else if(j<3+shift){
    //j++;
    i=1;
  }
  else{
    j=shift;
    i=1;
  }
  obj->step=i;
  obj->state=j;
}

/*
void grb_add_sprite_sheet(SDL_Renderer *renderer, CMP_Game * game, const char * image){
  SDL_Surface* loadedSurface = IMG_Load(image);
  if(loadedSurface==NULL){
    perror("ERROR IMG_Load failed to load");
    exit(1);
  }
  game->temp = SDL_CreateTextureFromSurface( renderer, loadedSurface );
  SDL_FreeSurface(loadedSurface);
}
*/
