#include "Caballero1.h"

Caballero1::Caballero1(SDL_Renderer*renderer)
{
    //ctor
    this-> renderer=renderer;
    textura = IMG_LoadTexture(renderer, "resources/jugadores/player2/picaro/left1.png");
    textura2 = IMG_LoadTexture(renderer, "resources/jugadores/player2/picaro/left2.png");
    globTextura=textura;
    SDL_QueryTexture(globTextura, NULL, NULL, &rectangulo.w, &rectangulo.h);
    rectangulo.w=92;
    rectangulo.h=92;
    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;

}

Caballero1::~Caballero1()
{
    //dtor
}
void Caballero1::dibujar()
{

    SDL_RenderCopy(renderer, globTextura, NULL, &rectangulo);

}

void Caballero1::mover(int pos1,int pos2)
{

    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;
    SDL_RenderCopy(renderer, textura, NULL, &rectangulo);


}
