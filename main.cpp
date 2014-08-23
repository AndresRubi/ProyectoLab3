#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include "personaje.h"
#include "Mago.h"
#include "Guerrero.h"
#include "Caballero.h"
#include "Mago1.h"
#include "Caballero1.h"
#include "Guerrero1.h"

using namespace std;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
int tile_width = 92;
Mix_Music *musica = NULL;
Mix_Music *click = NULL;


bool colision(SDL_Rect r1, SDL_Rect r2)
{
    if(r1.x + r1.w <= r2.x)//r1 esta muy a la i
        return false;

    if(r2.x + r2.w <= r1.x)//r1 esta muy a la der
        return false;

    if(r1.y + r1.h <= r2.y)//r1 esta muy a la i
        return false;

    if(r2.y + r2.h <= r1.y)//r1 esta muy a la der
        return false;

    return true;
}

int main()
{
//Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Tablero", 100, 100, 1250/*WIDTH*/, 673/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

 //SDL mixer
    if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096))
    {
        return 40;
    }

    musica = Mix_LoadMUS("ritmo.ogg");
    Mix_PlayMusic(musica,20);
    click=Mix_LoadMUS("seleccion_p.ogg");


SDL_Texture *piso1,*piso2;
SDL_Texture *cursor_normal,*cursor_seleccionado, *cursor_general;
SDL_Texture *obstaculo1,*obstaculo2;
SDL_Texture *pared1,*puerta1,*per,*personaje_seleccionado;
SDL_Texture *menu;
SDL_Rect rectangulo, rectangulo_obs,rect_cursor;

    piso1 = IMG_LoadTexture(renderer, "resources/escenario/piso1.png");
    piso2 = IMG_LoadTexture(renderer, "resources/escenario/piso2.png");
    puerta1 = IMG_LoadTexture(renderer, "resources/escenario/puerta1.png");
    cursor_normal = IMG_LoadTexture(renderer, "resources/escenario/cursor1.png");
    cursor_seleccionado = IMG_LoadTexture(renderer, "resources/escenario/cursor2.png");

    obstaculo1 = IMG_LoadTexture(renderer, "resources/escenario/obstaculo1.png");
    obstaculo2 = IMG_LoadTexture(renderer, "resources/escenario/obstaculo2.png");
int w=1, h=1;
    SDL_QueryTexture(cursor_normal, NULL, NULL, &w, &h);
    rect_cursor.x = 0;
    rect_cursor.y = 0;
    rect_cursor.w = w;
    rect_cursor.h = h;

    pared1= IMG_LoadTexture(renderer, "resources/escenario/pared1.png");
    cursor_general= cursor_normal;

    rectangulo_obs.h=tile_width;
    rectangulo_obs.w=tile_width;
    rectangulo.h=tile_width;
    rectangulo.w=tile_width;
    Mago m(renderer);
    Mago1 m1(renderer);
    Guerrero g(renderer);
    Guerrero1 g1(renderer);
    Caballero c(renderer);
    Caballero1 c1(renderer);



    ////tablero

int arr[7][13]={{0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,3,3,3,3,3,6,3,3,3,3,3,0},
                {1,3,3,3,3,6,5,6,3,3,3,3,1},
                {2,3,3,3,6,4,3,4,6,3,3,3,2},
                {1,3,3,6,3,4,3,4,3,6,3,3,1},
                {0,3,6,6,6,6,6,6,6,6,6,3,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0}};
    int frame = 0;
    int frame_anterior = 0;
    int cursor_x = 1;
    int cursor_y = 1;

    int animacion_personaje = 0;

while(true){
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_w)
                {



                    if (arr[cursor_y][cursor_x]!=0){
                    cursor_y--;
                    }

                }
                if(Event.key.keysym.sym == SDLK_a)
                {


                     cursor_x--;

                }
                if(Event.key.keysym.sym == SDLK_s)
                {
                    cursor_y++;
                }
                if(Event.key.keysym.sym == SDLK_d)
                {
                    cursor_x++;
                }
                if(Event.key.keysym.sym == SDLK_SPACE)
                {
                    if(cursor_x==c.posxP && cursor_y==c.posyP)
                    {
                        cursor_general=cursor_seleccionado;
                        personaje_seleccionado=c.textura;
                        Mix_PlayMusic(click,0);
                    }

                    else if(cursor_x==c1.posxP && cursor_y==c1.posyP)
                    {
                        cursor_general=cursor_seleccionado;
                        personaje_seleccionado=c1.textura;
                        Mix_PlayMusic(click,0);
                    }
                    else if(cursor_x==m.posxP && cursor_y==m.posyP)
                    {
                        cursor_general=cursor_seleccionado;
                        personaje_seleccionado=m.textura;
                        Mix_PlayMusic(click,0);
                    }
                    else if(cursor_x==m1.posxP && cursor_y==m1.posyP)
                    {
                        cursor_general=cursor_seleccionado;
                        personaje_seleccionado=m1.textura;
                        Mix_PlayMusic(click,0);
                    }
                     else if(cursor_x==g.posxP && cursor_y==g.posyP)
                    {
                        cursor_general=cursor_seleccionado;
                        personaje_seleccionado=g.textura;
                        Mix_PlayMusic(click,0);
                    }
                    else if(cursor_x==g1.posxP && cursor_y==g1.posyP)
                    {
                        cursor_general=cursor_seleccionado;
                        personaje_seleccionado=g1.textura;
                        Mix_PlayMusic(click,0);
                    }

                    else if(cursor_general==cursor_seleccionado )
                    {
                        if(personaje_seleccionado==c.textura)
                        {
                            c.posxP=cursor_x;
                            c.posyP=cursor_y;
                            c.mover(cursor_x,cursor_y);
                            cursor_general=cursor_normal;
                            cout<<cursor_x<<endl;
                            cout<<cursor_y<<endl;
                        }
                        else if(personaje_seleccionado==c1.textura)
                        {
                            c1.posxP=cursor_x;
                            c1.posyP=cursor_y;
                            c1.mover(cursor_x,cursor_y);
                            cursor_general=cursor_normal;
                            cout<<cursor_x<<endl;
                            cout<<cursor_y<<endl;
                        }
                        else if(personaje_seleccionado==m.textura)
                        {
                            m.posxP=cursor_x;
                            m.posyP=cursor_y;
                            m.mover(cursor_x,cursor_y);
                           //p.dibujar();
                            cursor_general=cursor_normal;

                            cout<<m.posxP<<endl;
                            cout<<m.posyP<<endl;
                            cout<<"paso por aqui"<<endl;
                            cout<<cursor_x<<endl;
                            cout<<cursor_y<<endl;;
                        }
                        else if(personaje_seleccionado==m1.textura)
                        {
                            m1.posxP=cursor_x;
                            m1.posyP=cursor_y;
                            m1.mover(cursor_x,cursor_y);
                           //p.dibujar();
                            cursor_general=cursor_normal;

                            cout<<m1.posxP<<endl;
                            cout<<m1.posyP<<endl;
                            cout<<"paso por aqui"<<endl;
                            cout<<cursor_x<<endl;
                            cout<<cursor_y<<endl;;
                        }
                        else if(personaje_seleccionado==g.textura)
                        {
                            g.posxP=cursor_x;
                            g.posyP=cursor_y;
                            g.mover(cursor_x,cursor_y);
                           //p.dibujar();
                            cursor_general=cursor_normal;

                            cout<<g.posxP<<endl;
                            cout<<g.posyP<<endl;
                            cout<<"paso por aqui"<<endl;
                            cout<<cursor_x<<endl;
                            cout<<cursor_y<<endl;;
                        }
                        else if(personaje_seleccionado==g1.textura)
                        {
                            g1.posxP=cursor_x;
                            g1.posyP=cursor_y;
                            g1.mover(cursor_x,cursor_y);
                           //p.dibujar();
                            cursor_general=cursor_normal;

                            cout<<g1.posxP<<endl;
                            cout<<g1.posyP<<endl;
                            cout<<"paso por aqui"<<endl;
                            cout<<cursor_x<<endl;
                            cout<<cursor_y<<endl;;
                        }
                    }
                }
            }
        }
     for(int x=0;x<13;x++)
        {
            for(int y=0;y<7;y++){

                if(arr[y][x]==1)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, pared1, NULL, &rectangulo);
                }
                else if(arr[y][x]==2)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, puerta1, NULL, &rectangulo);
                }
                else if(arr[y][x]==3)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, piso1, NULL, &rectangulo);
                }
                 else if(arr[y][x]==4)
                {


                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, obstaculo1, NULL, &rectangulo);




                }
                 else if(arr[y][x]==5)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, obstaculo2, NULL, &rectangulo);
                }else if(arr[y][x]==6)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, piso2, NULL, &rectangulo);
                }

                else{
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, pared1, NULL, &rectangulo);

                }
           }
        }


        if(animacion_personaje%2 == 0){
           m.globTextura=m.textura;
           g.globTextura=g.textura;
           c.globTextura=c.textura;
            m1.globTextura=m1.textura;
           g1.globTextura=g1.textura;
           c1.globTextura=c1.textura;
           }

        else{
            m.globTextura=m.textura2;
            g.globTextura=g.textura2;
            c.globTextura=c.textura2;
            m1.globTextura=m1.textura2;
            g1.globTextura=g1.textura2;
            c1.globTextura=c1.textura2;
            }



        if(frame%50==0)
        {
            animacion_personaje++;
        }
        m.textura;
        m.textura2;

        m.dibujar();
        m1.dibujar();
        g.dibujar();
        g1.dibujar();
        c.dibujar();
        c1.dibujar();


        rectangulo.x = cursor_x*tile_width;
        rectangulo.y = cursor_y*tile_width;
        SDL_RenderCopy(renderer, cursor_general, NULL, &rectangulo);



    SDL_RenderPresent(renderer);

    frame++;
     int frame_actual=SDL_GetTicks() - frame_anterior;
           frame_anterior = SDL_GetTicks();
           if(17-frame_actual>0)
                SDL_Delay(17-frame_actual);
}

    return 0;
}
