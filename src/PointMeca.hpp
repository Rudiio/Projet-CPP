# pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include"Vec2D.hpp"

//-------------------------------------------------------------------------

class PointMeca 
{
    public:
        PointMeca(Vec2D<double> a, Vec2D<double> v, Vec2D<double> p,double masse);

    protected:
        Vec2D<double> acc;  // Accélération du point
        Vec2D<double> vit;  // Vitesse du point
        Vec2D<double> pos;  // position du point
        double m;   // Masse du point
};  