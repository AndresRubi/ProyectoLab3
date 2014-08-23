#include "Caballero.h"

Caballero::Caballero(SDL_Renderer*renderer)
{
    //ctor
    this-> renderer=renderer;
    textura = IMG_LoadTexture(renderer, "resources/jugadores/player1/picaro/right1.png");
    textura2= IMG_LoadTexture(renderer, "resources/jugadores/player1/picaro/right2.png");

    globTextura=textura;
    SDL_QueryTexture(globTextura, NULL, NULL, &rectangulo.w, &rectangulo.h);
    rectangulo.w=92;
    rectangulo.h=92;
    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;

}

Caballero::~Caballero()
{
    //dtor
}
void Caballero::dibujar()
{

    SDL_RenderCopy(renderer, globTextura, NULL, &rectangulo);

}

void Caballero::mover(int pos1,int pos2)
{

    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;
    SDL_RenderCopy(renderer, textura, NULL, &rectangulo);


}
