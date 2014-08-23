#ifndef CABALLERO1_H
#define CABALLERO1_H
#include<SDL2/SDL_image.h>
#include <SDL2/SDL.h>
class Personaje;
class Caballero1
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture* textura,*textura2, *globTextura;
        SDL_Rect rectangulo;
        int posxP=11;
        int posyP=5;
        int cursor_x=1;
        int cursor_y=1;
        void dibujar();
        void PoderEspecial();
        void mover(int pos1,int pos2);
        Caballero1(){}
        Caballero1(SDL_Renderer* renderer);
        virtual ~Caballero1();
    protected:
    private:
};

#endif // CABALLERO1_H
