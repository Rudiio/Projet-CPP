#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include <random>
#include"IndividuDisque.hpp"

//-------------------------------------------------------------------------


class ModeleFoule 
{
    public:
        ModeleFoule(size_t n,size_t espace_n,size_t espace_m);
        ~ModeleFoule();

        // Initialisation de la foule
        void InitFoule();
        
        // Calcul des forces 
        void CalculForce(FastMarching& FM);

        // Intégration
        void Euler(double h);

        // Fonctions pour la répulsion entre individus
        void InitGrille();
        void VideGrille();
        void Grille();
        
        void Evacutation();

        // getteur
        size_t get_n() const {return _n;}
        std::vector<Individu*> get_foule() const {return _foule;}

    private:
        size_t _n; // taille de la foule
        std::vector<Individu*> _foule;
        size_t _espace_n;
        size_t _espace_m;

        // Pour la force de répulsion / Grille
        int* _first;
        int* _pointers;

        // Dimension de la grille
        size_t _nx;
        size_t _ny;
        double _dx;

        double _xmin;
        double _ymin; 

        // Nombre d'évacués
        size_t _evacues;

};