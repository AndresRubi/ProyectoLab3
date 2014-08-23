#ifndef MAGO_H
#define MAGO_H
#include<SDL2/SDL_image.h>
#include <SDL2/SDL.h>
class Personaje;
class Mago
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture* textura,*textura2,*globTextura;
        SDL_Rect rectangulo;
        int posxP=1;
        int posyP=3;
        int cursor_x=1;
        int cursor_y=1;
        void dibujar();
        void PoderEspecial();
        void mover(int pos1,int pos2);
        Mago(){}
        Mago(SDL_Renderer* renderer);
        virtual ~Mago();
    protected:
    private:
};

#endif // MAGO_H
