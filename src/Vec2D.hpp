#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>


//-------------------------------------------------------------------------

class Vec2D
{
    public:
        Vec2D(double _x=0, double _y=0):
            x(_x),
            y(_y)
        {}

        double x;
        double y;
};

// Vec2D::Vec2D(double _x,double _y):
//     x(_x),
//     y(_y)
// {}