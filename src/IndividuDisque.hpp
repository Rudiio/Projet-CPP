#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"Individu.hpp"


//-------------------------------------------------------------------------

class IndividuDisque : public Individu
{   
    public:
        IndividuDisque(double x, double y,double rayon);
        ~IndividuDisque();

        // Calcul de l'aire 
        double Aire();

        // Affichage de l'Individu
        void _DrawIndividu(SDL_Window *window,SDL_Renderer *renderer,int opt[]);
        void DrawDisque(SDL_Window *window,SDL_Renderer *renderer,double x,double y, double rayon);

        virtual void CalculForces();

        void toString();
        
    private:
        double _rayon;
        const double PI = 3.14159265358979323846;

};

