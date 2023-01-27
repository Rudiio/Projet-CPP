#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"SDL2/SDL.h"
#include"GraphicWindow.hpp"
#include"FastMarching.hpp"

//-------------------------------------------------------------------------

struct keys
{
    size_t up;
    size_t down;
    size_t left;
    size_t rigth;
    int zoom_state;
};

// Classe gérant la totalité de la simulation
class Simulation : public GraphicWindow
{
    public:
        Simulation(int width,int heigth,std::string title);
        ~Simulation();
        
        // Fonctions d'affichage
        void DrawInfo();
        void Render();

        //  Inputs 
        void Input();
        void InputMovement();
        void InputZooming();
        void EventDOWN(SDL_Event &event);
        void EventUP(SDL_Event &event);

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
        bool _info;

        // Variables de Foule
        size_t _nb;  // nombre d'individus dans la foule
        ModeleFoule* _foule;
        FastMarching* _FM;
        keys _keys;

};  
