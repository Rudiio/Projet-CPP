#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include"Vec2D.hpp"

//-------------------------------------------------------------------------

class Individu
{
    public:
        Individu(double x,double y);
        ~Individu();

        // Calcul des forces 
        void CalculForces();

        // Aire
        virtual double Aire()=0;

    protected:
        Vec2D acc;
        Vec2D vit;
        Vec2D pos;
};

