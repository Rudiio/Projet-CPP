//------------------------- INCLUDES ---------------------------------------
#include"Simulation.hpp"
#include"parametres.hpp"
#include<omp.h>
//------------------------- SIMULATION ------------------------------------------

Simulation::Simulation(int width,int heigth,std::string title):
    GraphicWindow(width,heigth,title),
    _espace(NULL),
    h(pas_de_temps),       // Pas de temps
    time(0),      // Temps total
    _etat(true),
    _affiche_axes(false),
    _info(false),
    _nb(nombre_pietons) // Taille de la foule
{

    // Création de l'espace de la Simulation
    _n=Nx;  // nombre de lignes
    _m=Ny;  // nombre de colonnes
    _espace = new Espace(_n,_m);

    // Création de la foule
    _foule = new ModeleFoule(_nb,_n,_m);
    _foule->InitFoule(*_espace);

    // Création du fast-Marching
    _FM = new FastMarching(_espace,_graduation);
    _FM->FM();

    // Initialisation de la structure keys
    _keys.up = 0;
    _keys.down = 0;
    _keys.left = 0;
    _keys.rigth = 0;
    _keys.zoom_state = 0;
}

Simulation::~Simulation()
{
    // Suppresion de l'espace
    delete _espace;

    // Suppression de la foule
    delete _foule;

    delete _FM;

}

//------------------------- AAFFICHAGE ------------------------------------------

// Affiche les informations de simulations
void Simulation::DrawInfo()
{   
    SDL_Color col  = {0,0,0};

    // Création de la string contenant le texte
    std::string text[4];
    text[0] = "Nombre d'individus restants : N=" + std::to_string(_foule->get_n());
    text[1] = "Nombre d'individus evacues : " + std::to_string(_foule->get_evacues());
    text[2] = "Pas de temps : h=" + std::to_string(h)+"s";
    text[3] = "Temps total : T=" + std::to_string(time) +"s";

    for(int i=0;i<4;i++){
        //Chargement du texte dans une surface
        SDL_Surface *surface = TTF_RenderText_Solid(_font,text[i].c_str(),col);

        if (surface==NULL)
            printf("%s\n",SDL_GetError());

        //Conversion de la surface en texture
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        if (texture==NULL)
            printf("%s\n",SDL_GetError());

        //affichage de la texture
        SDL_Rect On_render = {_offset + get_case_size(),_offset + get_case_size() + 30*i,250,30};
        SDL_RenderCopy(renderer, texture,NULL, &On_render);

        //Libération de la mémoire
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }
}

// Affiche les différents éléments
void Simulation::Render()
{
    // Nettoyage de l'écran
    CleanScreen();

    // Affichage du background 
    Background();

    // Affichage de l'espace
    DrawEspace(*_espace);

    // Affichage de la foule 
    DrawFoule(*_foule);

    // Affichage des axes
    if (_affiche_axes)
        DrawAxis();

    if(_info)
        DrawInfo();

    // Affichage du rendu
    blit();

}

//-------------------------FONCTIONS ------------------------------------------

// Gére les événements et inputs
void Simulation::Input()
{
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT :
                _etat=false;

            case SDL_KEYDOWN:
                EventDOWN(event);
                return;

            case SDL_KEYUP:
                EventUP(event);
                return;
        }
    }
}

void Simulation::EventDOWN(SDL_Event &event)
{
    switch(event.key.keysym.sym){
                    case SDLK_UP:_keys.up = 1; 
                        return ;

                    case SDLK_DOWN:_keys.down = 1; 
                        return ;

                    case SDLK_LEFT:_keys.left = 1; 
                        return ;

                    case SDLK_RIGHT:
                        _keys.rigth = 1; 
                        return ;

                    case SDLK_j:_keys.zoom_state=-1;
                        return;

                    case SDLK_k:_keys.zoom_state=1;
                        return;

                    case SDLK_a:
                        _affiche_axes = !_affiche_axes;
                        return;
                    
                    case SDLK_i:_info = !_info;
                        return;

                    case SDLK_ESCAPE:_etat=false;
                        return;
            } 
}

void Simulation::EventUP(SDL_Event& event)
{
    switch(event.key.keysym.sym){
                    case SDLK_UP:_keys.up = 0; 
                        return ;

                    case SDLK_DOWN:_keys.down = 0; 
                        return ;

                    case SDLK_LEFT:_keys.left = 0; 
                        return ;

                    case SDLK_RIGHT:_keys.rigth = 0; 
                        return ;

                    case SDLK_j:_keys.zoom_state=0;
                        return;

                    case SDLK_k:_keys.zoom_state=0;
                        return;
            }
}

// Gestion des mouvements
void Simulation::InputMovement()
{
    if(_keys.up){
        _y_offset+=_convert;
        --_y_origine;
    }
    if(_keys.down){
        _y_offset-=_convert;
        ++_y_origine;
    }
    if(_keys.left){
        _x_offset+=_convert;
        --_x_origine;
    }
    if(_keys.rigth){
        _x_offset-=_convert;
        ++_x_origine;
    }
}

// Gestion des zooms/dezooms
void Simulation::InputZooming()
{
    if(_keys.zoom_state==-1)
    {
        if(_convert-2>0)
        {
            _convert-=1;
            add_case_size(-1);
        }
    }
    if(_keys.zoom_state==1)
    {
        if(_convert<20){
            _convert+=1;
            add_case_size(1);
        }
    }
}

//------------------------- BOUCLE DE SIMULATION ------------------------------------------

// Boucle principale de la simulation
void Simulation::Mainloop()
{

    // Premier affichage
    Render();

    // Boucle
    while(_etat && _foule->get_foule().size()!=0){

        // Gestion des Inputs et evèments
        Input();
        InputMovement();
        InputZooming();

        // ---------------------------- PARTIE MODELISATION ----------------------------- //
        
        // Calcul des forces
        _foule->CalculForce((*_FM),_espace);

        // Calcul de la position
        _foule->Euler(h);

        // Evacuation
        _foule->Evacutation();

        // ----------------------------------------------------------------------------- //
        // Mise à jour de l'affichage
        Render();

        time += h;
    }
    std::cout << " ************************* FIN DE LA SIMULATION ********************************" << std::endl;

}
