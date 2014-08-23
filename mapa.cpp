#include "mapa.h"

Mapa::Mapa()
{
    //ctor
}

Mapa::~Mapa()
{
    //dtor
}

int Mapa::DibujarMapa()
{
    Pantalla();
    SDL_Texture *piso1,*piso2;
    SDL_Texture *cursor_normal,*cursor_seleccionado, *cursor_general;
    SDL_Texture *obstaculo1,*obstaculo2;
    SDL_Texture *pared1,*puerta1;
    SDL_Texture *menu
    SDL_Rect rectangulo, rectangulo_menu;

    menu = IMG_LoadTexture(renderer, "Imagenes/Menu/Menu.png");
    piso1 = IMG_LoadTexture(renderer, "resources/escenario/piso1.png");
    piso2 = IMG_LoadTexture(renderer, "resources/escenario/piso2.png");
    puerta = IMG_LoadTexture(renderer, "resources/escenario/puerta1.png");

    cursor = IMG_LoadTexture(renderer, "resources/escenario/cursor1.png");
    cursor = IMG_LoadTexture(renderer, "resources/escenario/cursor2.png");

    obstaculo1 = IMG_LoadTexture(renderer, "resources/escenario/obstaculo1.png");
    obstaculo1 = IMG_LoadTexture(renderer, "resources/escenario/obstaculo1.png");


    pared= IMG_LoadTexture(renderer, "resources/escenario/pared1.png");
    Seleccionador = IMG_LoadTexture(renderer, "Imagenes/Seleccionador.png");
    rectangulo.h=tile_width;
    rectangulo.w=tile_width;
    rectangulo.x=0;
    rectangulo.y=0;

int arr[7][13]={{0,0,0,0,0,1,2,1,0,0,0,0,0},
                {0,3,3,3,3,3,3,3,3,3,3,3,0},
                {0,3,3,3,3,3,5,5,3,3,3,3,0},
                {0,3,3,3,3,6,3,3,3,3,3,3,0},
                {0,3,3,3,3,6,3,4,3,3,3,3,0},
                {0,3,3,3,3,3,3,4,3,3,3,3,0},
                {0,0,0,0,0,1,2,1,0,0,0,0,0}};


    int frame=0;
    int frame_anterior = 0;
    int cursor_x=0;
    int curso_y=0;

      while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
        }

        for(int x=0;x<13;x++)
        {
            for(int y=0;y<7;y++){

                if(arr[y][x]==1)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, piso1, NULL, &rectangulo);
                }
                else if(arr[y][x]==2)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, piso2, NULL, &rectangulo);
                }
                else if(arr[y][x]==3)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, puerta1, NULL, &rectangulo);
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
                }
                 else if(arr[y][x]==6)
                {
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, Obstaculo3, NULL, &rectangulo);
                }
                else{
                    rectangulo.x = x*tile_width;
                    rectangulo.y = y*tile_width;
                    SDL_RenderCopy(renderer, pared1, NULL, &rectangulo);

                }
           }
        }
        rectangulo.x =0;
        rectangulo.y =0;
        SDL_RenderCopy(renderer, Menu, NULL, &rectangulo);
        SDL_RenderPresent(renderer);

        }
    return 0;
}
int Mapa::Pantalla()
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
}
