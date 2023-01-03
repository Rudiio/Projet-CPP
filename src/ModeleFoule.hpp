#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<vector>
#include"IndividuDisque.hpp"

//-------------------------------------------------------------------------


class ModeleFoule 
{
    public:
        ModeleFoule(size_t n);
        ~ModeleFoule();

        // Initialisation de la foule
        void InitFoule();

        // getteur
        size_t get_n() const {return _n;}
        std::vector<Individu*> get_foule() const {return _foule;}

    private:
        size_t _n; // taille de la foule
        std::vector<Individu*> _foule;


};