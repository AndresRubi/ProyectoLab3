#include "Mago.h"

Mago::Mago(SDL_Renderer*renderer)
{
    //ctor
    this-> renderer=renderer;
    textura2= IMG_LoadTexture(renderer, "resources/jugadores/player1/mago/right2.png");
    textura = IMG_LoadTexture(renderer, "resources/jugadores/player1/mago/right1.png");
    globTextura=textura;
    SDL_QueryTexture(globTextura, NULL, NULL, &rectangulo.w, &rectangulo.h);
    rectangulo.w=92;
    rectangulo.h=92;
    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;

}

Mago::~Mago()
{
    //dtor
}
void Mago::dibujar()
{

    SDL_RenderCopy(renderer, globTextura, NULL, &rectangulo);

}

void Mago::mover(int pos1,int pos2)
{

    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;
    SDL_RenderCopy(renderer, textura, NULL, &rectangulo);


}
