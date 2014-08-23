#ifndef MAPA_H
#define MAPA_H
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>

using namespace std;

class Mapa
{
    public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event Event;
    int tile_width = 96;
    int dibujarMapa();
    void implementarMenu();
    int pantalla();
        Mapa();
        virtual ~Mapa();
    protected:
    private:
};

#endif // MAPA_H
