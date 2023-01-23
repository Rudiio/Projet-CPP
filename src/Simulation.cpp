//------------------------- INCLUDES ---------------------------------------
#include"Simulation.hpp"
#include"parametres.hpp"

//------------------------- SIMULATION ------------------------------------------

Simulation::Simulation(int width,int heigth,std::string title):
    GraphicWindow(width,heigth,title),
    _espace(NULL),
    h(pas_de_temps),       // Pas de temps
    time(0),      // Temps total
    _etat(true),
    _affiche_axes(false),
    _nb(2) // Taille de la foule
{

    // Création de l'espace de la Simulation
    _n=((heigth-2*get_offset())/get_case_size());  // nombre de lignes
    _m=((width-2*get_offset())/get_case_size());  // nombre de colonnes
    _espace = new Espace(_n,_m);

    // Création de la foule
    _foule = new ModeleFoule(_nb,_n,_m);

    // Création du fast-Marching
    _FM = new FastMarching(_espace,_graduation);
    _FM->FM();
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
                switch(event.key.keysym.sym){
                    case SDLK_UP:
                        _y_offset+=_convert;
                        --_y_origine;
                        return ;

                    case SDLK_DOWN:
                        _y_offset-=_convert;
                        ++_y_origine;
                        return ;

                    case SDLK_LEFT:
                        _x_offset+=_convert;
                        --_x_origine;
                        return ;

                    case SDLK_RIGHT:
                        _x_offset-=_convert;
                        ++_x_origine;
                        return ;

                    case SDLK_j:
                        if(_convert-10>0){
                            _convert-=10;
                            add_case_size(-10);
                        }
                        return;

                    case SDLK_k:
                        if(_convert<100){
                            _convert+=10;
                            add_case_size(10);
                        }
                        return;

                    case SDLK_a:
                        _affiche_axes = !_affiche_axes;
                        return;
                        
                    case SDLK_ESCAPE:
                        _etat=false;
                        return;
                    
                } 
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
    while(_etat){

        // Gestion des Inputs et evèments
        Input();

        // ---------------------------- PARTIE MODELISATION ----------------------------- //
        
        // Calcul des forces
        _foule->CalculForce((*_FM));

        // Calcul de la position
        _foule->Euler(h);

        // ----------------------------------------------------------------------------- //
        // Mise à jour de l'affichage
        Render();

        time += h;
    }

}
