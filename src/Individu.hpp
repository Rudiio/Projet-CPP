#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"Vec2D.hpp"
#include"FastMarching.hpp"
#include<SDL2/SDL.h>

//-------------------------------------------------------------------------

class Individu
{
    public:
        Individu(double x,double y);
        virtual ~Individu();

        // Intégration avec Euler
        void _Euler(double h);

        // Calcul des forces 
        void _CalculForces(FastMarching& FM);
        void ForceAcceleration(FastMarching& FM);
        virtual void ForceInteraction()=0;
        virtual void ForceCorps(size_t xmin,size_t ymin,double dx,size_t Nx,size_t Ny,int* first,int* pointers)=0;
        virtual void ForceFrictionGlissante()=0;
        void ResetAcc();

        // Aire
        virtual double Aire()=0;

        // Affichage de l'Individu
        virtual void _DrawIndividu(SDL_Window *window,SDL_Renderer *renderer, int opt[])=0;

        virtual void toString()=0;

        Vec2D get_pos(){return pos;}

    protected:
        Vec2D acc;
        Vec2D vit;
        Vec2D pos;
        double aire;
        double m; // masse d'un individu
        int rgb[3];
};

