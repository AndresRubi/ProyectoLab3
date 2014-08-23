#include "Guerrero1.h"

Guerrero1::Guerrero1(SDL_Renderer*renderer)
{
    //ctor
    this-> renderer=renderer;
    textura = IMG_LoadTexture(renderer, "resources/jugadores/player2/warro/left1.png");
    textura2 = IMG_LoadTexture(renderer, "resources/jugadores/player2/warro/left2.png");
    globTextura=textura;
    SDL_QueryTexture(globTextura, NULL, NULL, &rectangulo.w, &rectangulo.h);
    rectangulo.w=92;
    rectangulo.h=92;
    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;

}

Guerrero1::~Guerrero1()
{
    //dtor
}
void Guerrero1::dibujar()
{

    SDL_RenderCopy(renderer, globTextura, NULL, &rectangulo);

}

void Guerrero1::mover(int pos1,int pos2)
{

    rectangulo.x= posxP*92;
    rectangulo.y=posyP*92;
    SDL_RenderCopy(renderer, textura, NULL, &rectangulo);


}
