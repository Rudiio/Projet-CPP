#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include <random>
#include"IndividuDisque.hpp"

//-------------------------------------------------------------------------


class ModeleFoule 
{
    public:
        ModeleFoule(size_t n,size_t espace_n,size_t espace_m);
        ~ModeleFoule();

        // Initialisation de la foule
        void InitFoule(Espace& espace);
        
        // Calcul des forces 
        void CalculForce(FastMarching& FM,Espace* espace);

        // Intégration
        void Euler(double h);
        
        // Gestion de l'évacuation
        void Evacutation();

        // getteur
        size_t get_n() const {return _n;}
        size_t get_evacues() const {return _evacues;}
        std::vector<Individu*> get_foule() const {return _foule;}

    private:
        size_t _n; // taille de la foule
        std::vector<Individu*> _foule;  // Foule d'individu

        // Taille de l'espace (en nombre de cases)
        size_t _espace_n;
        size_t _espace_m;

        // Nombre d'évacués
        size_t _evacues;
        std::list<Individu*> _Levacues; // Individus évacués

};