//------------------------- INCLUDES ---------------------------------------
#include"Simulation.hpp"


//------------------------- SIMULATION ------------------------------------------

Simulation::Simulation(int width,int heigth,std::string title):
    GraphicWindow(width,heigth,title),
    _espace(NULL),
    h(10),       // Pas de temps
    time(0),      // Temps total
    _etat(true),
    _affiche_axes(true),
    _nb(5) // Taille de la foule
{

    // Création de l'esapce de la Simulation
    _n=((heigth-2*get_offset())/get_case_size());  // nombre de lignes
    _m=((width-2*get_offset())/get_case_size());  // nombre de colonnes
    _espace = new Espace(_n,_m);
    
    // Création de la foule
    _foule = new ModeleFoule(_nb);

}

Simulation::~Simulation()
{
    // Suppresion de l'espace
    delete _espace;

    // Suppression de la foule
    delete _foule;

}

//------------------------- AAFFICHAGE ------------------------------------------

// Affiche les différents éléments
void Simulation::Render()
{
    // Nettoyage de l'écran
    CleanScreen();

    // Affichage du background 
    // Background();

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
                        add_y(get_convert(),1);
                        return ;

                    case SDLK_DOWN:
                        add_y(-get_convert(),-1);
                        return ;

                    case SDLK_LEFT:
                        add_x(get_convert(),-1);
                        return ;

                    case SDLK_RIGHT:
                        add_x(-get_convert(),1);
                        return ;
                    
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

        // Mise à jour de l'affichage
        Render();

        time += h;
    }

}
