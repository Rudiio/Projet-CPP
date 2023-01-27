#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"Espace.hpp"
#include"Vec2D.hpp"

//-------------------------------------------------------------------------
// Classe représentant l'algorithme de Dijkstra
class FastMarching
{
    public:
        FastMarching(Espace* Espace,double graduation);
        ~FastMarching();

        void InitFM(size_t i0,size_t j0,size_t t);
        std::vector<Vec2D<size_t>> voisins(size_t i,size_t j);
        bool in(std::vector<Vec2D<size_t>> L,size_t i,size_t j);
        void FM();
        
        Vec2D<double> Gradient(size_t i,size_t j);

        size_t GetPosEspace(size_t i,size_t j);
        double operator()(size_t i, size_t j);

    private:
        Espace* _espace;
        double* _dist;   // Tableau des distances pour Dijkstra
        size_t* _fini;
        std::vector<Vec2D<size_t>> L;

        size_t __n;
        size_t __m;

        size_t _i0;
        size_t _j0;

        double _p;
};
