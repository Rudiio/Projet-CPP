#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
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

        //  Inputs 
        void Input();

        // Boucle principale
        void Mainloop();

    private:
        //Variables pour l'espace de simulation
        Espace* _espace;
        int _n;
        int _m;

        // Paramètres de modèlisation
        double h;
        double time;

        // Paramètres de simulation
        bool _etat;
        bool _affiche_axes;

        // Variables de Foule
        size_t _nb;  // nombre d'individus dans la foule
        ModeleFoule * _foule;

};  