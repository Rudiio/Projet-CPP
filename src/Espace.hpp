#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>

//-------------------------------------------------------------------------
// Classe représentant l'espace de la simulation
class Espace 
{
    public:
        Espace(size_t n,size_t m);
        ~Espace();

        // Générateur de carte
        void MapGenerator();

        // Fast-marching
        void InitNoeud(size_t i0,size_t j0,double inf);

        // Surcharges d'opérateurs
        int operator()(size_t i,size_t j) const;
        int& operator()(size_t i,size_t j);

        // Getteurs
        size_t get_n() const {return _n;};
        size_t get_m() const {return _m;};

    private:
        int* _map;  // Représentation de l'espace
        double* _dist;   // Tableau des distances pour Dijkstra
        size_t _n;
        size_t _m;
};