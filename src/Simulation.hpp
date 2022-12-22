#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include"GraphicWindow.hpp"


//-------------------------------------------------------------------------
// Classe gérant la totalité de la simulation
class Simulation : public GraphicWindow
{
    public:
        Simulation(int width,int heigth,std::string title);
        ~Simulation();
        
        // Fonctions d'affichage
        void Render();

        // Boucle principale
        void Mainloop();

    private:
        //Variables pour l'espace de simulation
        Espace* _espace;
        int _n;
        int _m;

        // Paramètres de simulation
        double h;
        double time;
};  