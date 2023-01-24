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

        Vec2D(const Vec2D& X):
            x(X.x),
            y(X.y)
        {}

        double x;
        double y;
};


double norm2(Vec2D X1,Vec2D X2);
double norm(Vec2D X);
double dot(Vec2D X1,Vec2D X2);
Vec2D ProjeteOrthogonal(Vec2D pos, Vec2D A, Vec2D B);
Vec2D operator+(Vec2D X1, Vec2D X2);
Vec2D operator-(Vec2D X1, Vec2D X2);
Vec2D operator*(double a, Vec2D X);
Vec2D operator/(Vec2D X,double a);
bool operator==(Vec2D X1,Vec2D X2);
