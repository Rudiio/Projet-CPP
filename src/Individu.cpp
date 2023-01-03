
//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include"Individu.hpp"

//-------------------------------------------------------------------------

Individu::Individu(double x, double y):
    acc(Vec2D(0,0)),
    vit(Vec2D(0,0)),
    pos(Vec2D(x,y))
{
    
}

Individu::~Individu()
{

}