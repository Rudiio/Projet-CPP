//------------------------- INCLUDES ---------------------------------------
#include"Simulation.hpp"


//-------------------------FONCTIONS ------------------------------------------

Simulation::Simulation(int width,int heigth,std::string title):
    GraphicWindow(width,heigth,title),
    _espace(NULL)
{

    // Création de l'esapce de la Simulation
    _n=(int) get_heigth()/get_case_size();
    _m=(int) get_width()/get_case_size();
    _espace = new Espace(_n,_m);
}

Simulation::~Simulation()
{
    delete _espace;
}

//-------------------------FONCTIONS ------------------------------------------

// Affiche les différents éléments
void Simulation::Render()
{
    CleanScreen();

    DrawEspace(*_espace);
    blit();

}

//-------------------------FONCTIONS ------------------------------------------

// Boucle principale de la simulation
void Simulation::Mainloop()
{

    SDL_Delay(1000);
    Render();
    SDL_Delay(1000);
}
