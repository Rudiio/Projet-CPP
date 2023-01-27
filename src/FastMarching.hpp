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
        
        // Fonctions de Fast-Marching
        void InitFM(size_t i0,size_t j0,size_t t);
        std::vector<Vec2D<size_t>> voisins(size_t i,size_t j);
        bool in(std::vector<Vec2D<size_t>> L,size_t i,size_t j);
        void FM();
        
        // Calcul du gradient
        Vec2D<double> Gradient(size_t i,size_t j);

        // opérateur
        double operator()(size_t i, size_t j);

        // Getteurs
        size_t GetPosEspace(size_t i,size_t j);
        double *get_dist() const {return _dist;}
        size_t *get_fini() const {return _fini;}
        std::vector<Vec2D<size_t>> get_L() const {return L;}
    private:
        Espace* _espace;
        double* _dist;   // Ta bleau des distances pour Dijkstra
        size_t* _fini;   // tableau des cases finies
        std::vector<Vec2D<size_t>> L;   // Cases à traiter

        // Taille  de la grille
        size_t __n;
        size_t __m;

        // Coordonnées de la sortie
        size_t _i0;
        size_t _j0;

        // pas d'espace
        double _p;
};
