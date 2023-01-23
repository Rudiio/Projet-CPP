#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"Individu.hpp"
#include"parametres.hpp"

//-------------------------------------------------------------------------

class IndividuDisque : public Individu
{   
    public:
        // Constructeurs-destructeurs
        IndividuDisque(double x, double y,double rayon);
        ~IndividuDisque();

        // Calcul de l'aire 
        double Aire();

        // Affichage de l'Individu
        void _DrawIndividu(SDL_Window *window,SDL_Renderer *renderer,int opt[]);
        void DrawDisque(SDL_Window *window,SDL_Renderer *renderer,double x,double y, double rayon);
        
        // Calcul des forces soumises à un individu
        void _CalculForces(FastMarching& FM,size_t* first,size_t* pointers);
        void ForceInteraction();
        void ForceCorps(size_t xmin,size_t ymin,double dx,size_t Nx,size_t Ny,int* first,int* pointers);
        void ForceFrictionGlissante();

        void toString();
        
    private:
        double _rayon;
        const double PI = 3.14159265358979323846;

};

