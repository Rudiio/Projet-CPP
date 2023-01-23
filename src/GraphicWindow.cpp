//------------------------- INCLUDES ---------------------------------------
#include"GraphicWindow.hpp"
#include<vector>
#include"parametres.hpp"

//-------------------------FONCTIONS ------------------------------------------

GraphicWindow::GraphicWindow(size_t width,size_t heigth,const std::string title):
    _offset(30),
    _graduation(pas_espace), // pas d'espace
    _convert(20),
    _x_offset(0),
    _y_offset(0),
    _x_origine(0),
    _y_origine(0),
    _axis_offset(0),
    _font(NULL),
    _width(width),
    _heigth(heigth),
    _title(title),
    _case_size(_convert)
{
    //Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO)==-1)
		throw std::runtime_error(SDL_GetError());

    //Initialisation de la SDL_TTF
    if (TTF_Init() == -1) {
	    throw std::runtime_error(SDL_GetError());
    }

    //Création de la fenêtre
    window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED ,width,heigth,SDL_WINDOW_RESIZABLE);

    if (window==NULL)
        throw std::runtime_error(SDL_GetError());
    
    // Création du rendu
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (renderer==NULL)
        throw std::runtime_error(SDL_GetError());
    
    // Chargement de la police
    char path[]= "./font/dejavu/ttf/DejaVuSans.ttf";
    _font = charge_font(path,400);

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
    TTF_CloseFont(_font);
    TTF_Quit();
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
    SDL_SetRenderDrawColor(renderer, 254, 254, 224, 255);   //beige
    // SDL_SetRenderDrawColor(renderer,105,105,105,255);   // gris 
    // SDL_SetRenderDrawColor(renderer,255,255,255,255);   // gris 
	SDL_RenderClear(renderer);
}

/* Charge une font .ttf avec la taille de police size*/
TTF_Font * GraphicWindow::charge_font(char * path,int size)
{

    TTF_Font *font = NULL;
    font = TTF_OpenFont(path,size);
    if(!font)
    {
        SDL_Log("ERREUR: Chargement font > %s\n",SDL_GetError());
	    exit(EXIT_FAILURE);
    }

    return font;
}

//----------------------------------------------------------------------------

// Dessine les axes
void GraphicWindow::DrawAxis()
{   
    // Couleur des axes
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_Color col  = {0,0,0};
    int grad_width = 5;

    // Axe des abscisses
    int start_x = _offset + _case_size;
    int start_y = _offset +_case_size;

    // Traçage de l'axes
    SDL_RenderDrawLine(renderer,start_x,start_y,start_x + (_width - 2*_offset - 2*_case_size),start_y);
    SDL_RenderDrawLine(renderer,start_x,start_y+1,start_x + (_width - 2*_offset - 2*_case_size),start_y+1);

    // Dernière graduation
    SDL_RenderDrawLine(renderer,start_x + (_width - 2*_offset - 2*_case_size),start_y,start_x + (_width - 2*_offset - 2*_case_size),start_y+grad_width);
    SDL_RenderDrawLine(renderer,start_x + (_width - 2*_offset - 2*_case_size -1),start_y,start_x + (_width - 2*_offset - 2*_case_size - 1),start_y+grad_width);

    int i=_x_origine;
    for(int x = start_x ; x < (int)(start_x + _width - 2*_offset - 2*_case_size);x += _convert){
        std::string text = std::to_string(i);

        if (0<=i && i<=9)
            text = "0"+text;

        //Chargement du texte dans une surface
        SDL_Surface *surface = TTF_RenderText_Solid(_font,text.c_str(),col);

        if (surface==NULL)
            printf("%s\n",SDL_GetError());

        //Conversion de la surface en texture
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        //affichage de la texture
        SDL_Rect On_render = {x-10,start_y-grad_width -_convert/3,_convert/3,_convert/3};

        SDL_RenderCopy(renderer, texture,NULL, &On_render);
        SDL_RenderDrawLine(renderer,x,start_y-grad_width,x,start_y+grad_width);
        i+=_graduation;

        //Libération de la mémoire
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    // Axe des ordonnées
    start_x = _offset + _case_size;
    start_y = _offset + _case_size;
    
    // Traçage de l'axes
    SDL_RenderDrawLine(renderer,start_x,start_y,start_x ,_heigth - _offset -_case_size);
    SDL_RenderDrawLine(renderer,start_x+1,start_y,start_x+1,_heigth - _offset -_case_size);
    
    // Dernière graduation
    // SDL_RenderDrawLine(renderer,start_x - grad_width,_offset+_case_size,start_x ,_offset+_case_size);
    // SDL_RenderDrawLine(renderer,start_x - grad_width,_offset+_case_size,start_x ,_offset+_case_size);
    SDL_RenderDrawLine(renderer,start_x - grad_width,_heigth - _offset -_case_size,start_x ,_heigth - _offset -_case_size);
    SDL_RenderDrawLine(renderer,start_x - grad_width,_heigth - _offset -_case_size -1,start_x ,_heigth - _offset -_case_size -1);

    i = _y_origine;
    for(int y = start_y ;y  < (int)(_heigth - _offset -_case_size);y += _convert){
        std::string text = std::to_string(i);
        
        if (0<=i && i<=9)
            text = "0"+text;

        //Chargement du texte dans une surface
        SDL_Surface *surface = TTF_RenderText_Solid(_font,text.c_str(),col);

        if (surface==NULL)
            printf("%s\n",SDL_GetError());

        //Conversion de la surface en texture
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        //affichage de la texture
        SDL_Rect On_render = {start_x -_convert/2 ,y-7,_convert/3,_convert/3};

        SDL_RenderCopy(renderer, texture,NULL, &On_render);
        SDL_RenderDrawLine(renderer,start_x - grad_width,y,start_x + grad_width,y);
        i+=_graduation;

        //Libération de la mémoire
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
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
    int x = (j)*_case_size+_offset + _x_offset;
    int y = (i-_axis_offset)*_case_size+_offset + _y_offset;

    // Attention à la correspondance avec les axes de la SDL
    SDL_Rect rect = {x+1,y+1,(int)_case_size-1,(int)_case_size-1};

    //Affichage d'un mur
    if(espace(i,j)==1){
        // SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_SetRenderDrawColor(renderer,105,105,105,255);
        SDL_RenderFillRect(renderer,&rect);
    }
    else if (espace(i,j)==0){
        rect = {x,y,(int)_case_size,(int)_case_size};
        SDL_SetRenderDrawColor(renderer,254, 254, 224,255);
        // SDL_SetRenderDrawColor(renderer,255, 0, 0,255);
        SDL_RenderFillRect(renderer,&rect);
    }
    else if (espace(i,j)==2){
        rect = {x,y,(int)_case_size,(int)_case_size};
        SDL_SetRenderDrawColor(renderer,70, 130, 180,255);
        SDL_RenderFillRect(renderer,&rect);
    }
}

// Dessine la foule
void GraphicWindow::DrawFoule(ModeleFoule& foule)
{
    int opt[] = {(int)_width,(int)_heigth,_offset,_graduation,_convert,_x_offset,_y_offset,(int)_case_size};

    size_t n = foule.get_n();
    std::vector<Individu*> vec_foule = foule.get_foule();

    for (size_t i=0;i<n;i++)
        vec_foule[i]->_DrawIndividu(window,renderer,opt);
    
}
