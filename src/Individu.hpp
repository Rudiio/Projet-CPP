#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"Vec2D.hpp"
#include"FastMarching.hpp"
#include"PointMeca.hpp"
#include<SDL2/SDL.h>

//-------------------------------------------------------------------------

class Individu : public PointMeca
{
    public:
        Individu(double x,double y,double masse);
        virtual ~Individu();

        // Intégration avec Euler
        void _Euler(double h);

        // Calcul des forces 
        void ForceAcceleration(FastMarching& FM);
        void ForceInteractions(std::vector<Individu*> foule,Individu* current);
        virtual void ForcesPsycho(Individu* b)=0;
        virtual void ForcesCorps(Individu* b)=0;
        virtual void ForcesGlissante(Individu* b)=0;
        void ForcesMur(Espace& espace);
        void ForcesMurDiag(Espace& espace);
        virtual void ForceRepulsionMur(Vec2D<double> projete)=0;
        virtual void ForceGlissanteMur(Vec2D<double> projete)=0;
        virtual void ForcesPsychoMur(Vec2D<double> projete)=0;
        void ResetAcc();

        // Affichage de l'Individu
        virtual void _DrawIndividu(SDL_Window *window,SDL_Renderer *renderer, int opt[])=0;

        // Getteurs 
        Vec2D<double> get_pos()const{return pos;}
        Vec2D<double> get_vit()const{return vit;}
        virtual double get_rayon()const =0;

    protected:
        int rgb[3];
};

