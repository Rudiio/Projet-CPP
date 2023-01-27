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
        void ForceInteractions(std::vector<Individu*> foule,Individu* current);
        void ForcesPsycho(Individu* b);
        void ForcesCorps(Individu* b);
        void ForcesGlissante(Individu* b);
        void ForceRepulsionMur(Vec2D<double> projete);
        void ForceGlissanteMur(Vec2D<double> projete);
        void ForcesPsychoMur(Vec2D<double> projete);

        void toString();

        double get_rayon()const {return _rayon;}
        
    private:
        double _rayon;

};

