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

        // getteur
        size_t get_n() const {return _n;}
        std::vector<Individu*> get_foule() const {return _foule;}

    private:
        size_t _n; // taille de la foule
        std::vector<Individu*> _foule;
        size_t _espace_n;
        size_t _espace_m;


};