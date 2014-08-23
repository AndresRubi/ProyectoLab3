#ifndef GUERRERO1_H
#define GUERRERO1_H
#include<SDL2/SDL_image.h>
#include <SDL2/SDL.h>
class Personaje;
class Guerrero1
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture* textura,*textura2, *globTextura;
        SDL_Rect rectangulo;
        int posxP=11;
        int posyP=1;
        int cursor_x=1;
        int cursor_y=1;
        void dibujar();
        void PoderEspecial();
        void mover(int pos1,int pos2);
        Guerrero1(){}
        Guerrero1(SDL_Renderer* renderer);
        virtual ~Guerrero1();
    protected:
    private:
};

#endif // GUERRERO1_H
