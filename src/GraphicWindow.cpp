//------------------------- INCLUDES ---------------------------------------
#include"GraphicWindow.hpp"



//-------------------------FONCTIONS ------------------------------------------

GraphicWindow::GraphicWindow(size_t width,size_t heigth,const std::string title):
    _width(width),
    _heigth(heigth),
    _title(title),
    _case_size(60)
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
	SDL_SetRenderDrawColor(renderer,255,255,255, 255); 
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

//----------------------------------------------------------------------------

void GraphicWindow::blit()
{
    /* Met à jour l'affichage */
    SDL_RenderPresent(renderer);
}

void GraphicWindow::CleanScreen()
{
    /* Colore le rendu en blanc pour réinitialiser l'affichage */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
	SDL_RenderClear(renderer);
}

//----------------------------------------------------------------------------

// Dessine l'espace de la simulation
void GraphicWindow::DrawEspace(Espace& espace)
{
    for(size_t i=0;i<espace.get_n();++i)
        for (size_t j=0;j<espace.get_m();++j)
            DrawCase(espace,i,j);
}

// Dessine un carré correspondant à un mur ou un obstacle
void GraphicWindow::DrawCase(Espace& espace,size_t i, size_t j)
{   
    int x = j*_case_size;
    int y = i*_case_size;

    // Attention à la correspondance avec les axes de la SDL
    SDL_Rect rect = {x,y,(int)_case_size-1,(int)_case_size-1};

    //Affichage d'un mur
    if(espace(i,j)){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderFillRect(renderer,&rect);
    }
    else{
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderFillRect(renderer,&rect);
    }
}
