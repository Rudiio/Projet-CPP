#pragma once

#include<iostream>
#include<cmath>
#include"Vec2D.hpp"
#include"FastMarching.hpp"

//-------------------------- PARAMETRES DE SIMULATION --------------------------------------

const size_t nombre_pietons = 50 ; //Nombre de piétons

const double rayon_pietons = 0.5; // Rayons des piétons

const double masse_pieton = 70;    // Masse des piétons

const double vs = 10.34; // Vitesse des piétons (en m/s)

const double pas_de_temps = 0.003; // Pas de  temps (en s)

const size_t pas_espace = 1; // Pas d'espace en m

const double tau = 0.5; // temps de relaxation en s

//-------------------------------- FONCTIONS GENERALES ---------------------------------------

// double norm2(double x1,double y1,double x2,double y2)
// {
//     double x = x2-x1;
//     double y = y2-y2;

//     return sqrt(x*x + y*y);
// }

// double norm(double x,double y){return sqrt(x*x + y*y);}

// Vec2D gradient_fm(size_t x,size_t y,FastMarching& FM)
// {
//     Vec2D gradient;

//     // gradient.x = 
// }

//--------------------------------------------------------------------------