#ifndef PERSONAJE_H
#define PERSONAJE_H
#include<SDL2/SDL_image.h>
#include <SDL2/SDL.h>

class Personaje
{
    public:
        int vida;
        int ataque;
        int velocidad;
        Personaje();
       virtual void PoderEspecial()=0;
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
