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
        void MapGenerator1();
        void MapGenerator2();
        void MapGenerator3();
        void MapGenerator4();
        void MapGenerator5();
        void MapGenerator6();
        void MapGenerator7();

        // Surcharges d'opérateurs
        int operator()(size_t i,size_t j) const;
        int& operator()(size_t i,size_t j);

        // Getteurs
        size_t get_n() const {return _n;};
        size_t get_m() const {return _m;};

    private:
        int* _map;  // Représentation de l'espace
        size_t _n;
        size_t _m;
};