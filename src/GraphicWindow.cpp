//------------------------- INCLUDES ---------------------------------------
#include"GraphicWindow.hpp"



//-------------------------FUNCTIONS ------------------------------------------

GraphicWindow::GraphicWindow(int width,int heigth,const std::string title):
    _width(width),
    _heigth(heigth),
    _title(title)
{
    //Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO)==-1)
		throw std::runtime_error(SDL_GetError());

    //Création de la fenêtre
    window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED ,width,heigth,SDL_WINDOW_RESIZABLE);

    if (window==NULL)
        throw std::runtime_error(SDL_GetError());
    
    // Création du rendu
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (renderer==NULL)
        throw std::runtime_error(SDL_GetError());

    //Coloriage du fond
	SDL_SetRenderDrawColor(renderer, 255, 255,255, 255); 
	SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

GraphicWindow::~GraphicWindow()
{
    // Suppression 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
