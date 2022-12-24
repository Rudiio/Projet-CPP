//------------------------- INCLUDES ---------------------------------------
#include"GraphicWindow.hpp"



//-------------------------FONCTIONS ------------------------------------------

GraphicWindow::GraphicWindow(size_t width,size_t heigth,const std::string title):
    _width(width),
    _heigth(heigth),
    _title(title),
    _case_size(60),
    _offset(30),
    _graduation(1),
    _convert(50),
    _x_offset(0),
    _y_offset(0)
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

void GraphicWindow::Background()
{
    /* Colore le rendu en blanc pour réinitialiser l'affichage */
    SDL_SetRenderDrawColor(renderer, 254, 254, 224, 255); 
	SDL_RenderClear(renderer);
}

//----------------------------------------------------------------------------

// Dessine les axes
void GraphicWindow::DrawAxis()
{   
    // Couleur des axes
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    int grad_width = 5;

    // Axe des abscisses
    int start_x = _offset + _case_size;
    int start_y = _heigth - _offset -_case_size-2;

    SDL_RenderDrawLine(renderer,start_x,start_y,start_x + (_width - 2*_offset - 2*_case_size),start_y);
    SDL_RenderDrawLine(renderer,start_x,start_y+1,start_x + (_width - 2*_offset - 2*_case_size),start_y+1);

    SDL_RenderDrawLine(renderer,start_x + (_width - 2*_offset - 2*_case_size),start_y,start_x + (_width - 2*_offset - 2*_case_size),start_y+grad_width);
    SDL_RenderDrawLine(renderer,start_x + (_width - 2*_offset - 2*_case_size -1),start_y,start_x + (_width - 2*_offset - 2*_case_size - 1),start_y+grad_width);

    for(int x = start_x + _convert; x < (int)(start_x + _width - 2*_offset - 2*_case_size);x += _convert){
        SDL_RenderDrawLine(renderer,x,start_y-grad_width,x,start_y+grad_width);
    }

    // Axe des ordonnées
    start_x = _offset + _case_size+2;
    start_y = _heigth - _offset -_case_size;

    SDL_RenderDrawLine(renderer,start_x,start_y,start_x ,_offset+_case_size);
    SDL_RenderDrawLine(renderer,start_x-1,start_y,start_x-1,_offset+_case_size);
    
    SDL_RenderDrawLine(renderer,start_x - grad_width,_offset+_case_size,start_x ,_offset+_case_size);
    SDL_RenderDrawLine(renderer,start_x - grad_width,_offset+_case_size,start_x ,_offset+_case_size);

    for(int y = start_y -_convert ;y  > (int)(_offset+_case_size);y -= _convert){
        SDL_RenderDrawLine(renderer,start_x - grad_width,y,start_x + grad_width,y);
    }
}

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
    int x = j*_case_size+_offset + _x_offset;
    int y = i*_case_size+_offset + _y_offset;

    // Attention à la correspondance avec les axes de la SDL
    SDL_Rect rect = {x+1,y+1,(int)_case_size-1,(int)_case_size-1};

    //Affichage d'un mur
    if(espace(i,j)){
        // SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_SetRenderDrawColor(renderer,105,105,105,255);
        SDL_RenderFillRect(renderer,&rect);
    }
    else{
        rect = {x,y,(int)_case_size,(int)_case_size};
        SDL_SetRenderDrawColor(renderer,254, 254, 224,255);
        SDL_RenderFillRect(renderer,&rect);
    }
}
