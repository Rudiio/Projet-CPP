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

        // Surcharges d'opérateurs
        int operator()(size_t i,size_t j) const;
        int& operator()(size_t i,size_t j);

        // Getteurs
        size_t get_n() const {return _n;};
        size_t get_m() const {return _m;};

    private:
        int* _map;
        size_t _n;
        size_t _m;
};