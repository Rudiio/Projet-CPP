#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"Vec2D.hpp"
#include<SDL2/SDL.h>

//-------------------------------------------------------------------------

class Individu
{
    public:
        Individu(double x,double y);
        virtual ~Individu();

        // Calcul des forces 
        virtual void CalculForces()=0;

        // Aire
        virtual double Aire()=0;

        // Affichage de l'Individu
        virtual void _DrawIndividu(SDL_Window *window,SDL_Renderer *renderer, int opt[])=0;

        virtual void toString()=0;
    protected:
        Vec2D acc;
        Vec2D vit;
        Vec2D pos;
        double aire;
        int rgb[3];
};

