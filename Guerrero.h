#ifndef GUERRERO_H
#define GUERRERO_H
#include<SDL2/SDL_image.h>
#include <SDL2/SDL.h>
class Personaje;
class Guerrero
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture* textura,*textura2,*globTextura;
        SDL_Rect rectangulo;
        int posxP=1;
        int posyP=1;
        int cursor_x=1;
        int cursor_y=1;
        void dibujar();
        void PoderEspecial();
        void mover(int pos1,int pos2);
        Guerrero(){}
        Guerrero(SDL_Renderer* renderer);
        virtual ~Guerrero();
    protected:
    private:
};

#endif // GUERRERO_H
