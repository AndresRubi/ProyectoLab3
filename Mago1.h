#ifndef MAGO1_H
#define MAGO1_H
#include<SDL2/SDL_image.h>
#include <SDL2/SDL.h>
class Personaje;
class Mago1
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture* textura,*textura2,*globTextura;
        SDL_Rect rectangulo;
        int posxP=11;
        int posyP=3;
        int cursor_x=1;
        int cursor_y=1;
        void dibujar();
        void PoderEspecial();
        void mover(int pos1,int pos2);
        Mago1(){}
        Mago1(SDL_Renderer* renderer);
        virtual ~Mago1();
    protected:
    private:
};

#endif // MAGO1_H
