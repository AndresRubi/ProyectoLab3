#ifndef CABALLERO_H
#define CABALLERO_H
#include<SDL2/SDL_image.h>
#include <SDL2/SDL.h>
class Personaje;
class Caballero
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture* textura,*globTextura, *textura2;
        SDL_Rect rectangulo;
        int posxP=1;
        int posyP=5;
        int cursor_x=1;
        int cursor_y=1;
        void dibujar();
        void PoderEspecial();
        void mover(int pos1,int pos2);
        Caballero(){}
        Caballero(SDL_Renderer* renderer);
        virtual ~Caballero();
    protected:
    private:
};

#endif // CABALLERO_H
