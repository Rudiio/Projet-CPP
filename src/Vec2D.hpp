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


double norm2(Vec2D X1,Vec2D X2);
double norm(Vec2D X);
double dot(Vec2D X1,Vec2D X2);
Vec2D operator+(Vec2D X1, Vec2D X2);
Vec2D operator-(Vec2D X1, Vec2D X2);
Vec2D operator*(double a, Vec2D X);
Vec2D operator/(Vec2D X,double a);