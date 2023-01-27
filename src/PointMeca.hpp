# pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include"Vec2D.hpp"

//-------------------------------------------------------------------------


class PointMeca 
{
    public:
        PointMeca(Vec2D a, Vec2D v, Vec2D p,double masse);

    protected:
        Vec2D acc;  // Accélération du point
        Vec2D vit;  // Vitesse du point
        Vec2D pos;  // position du point
        double m;   // Masse du point
};  