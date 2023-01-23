
//------------------------- INCLUDES ---------------------------------------
#include"Espace.hpp"
#include<cmath>
//--------------------------------------------------------------------------

Espace::Espace(size_t n,size_t m):
    _n(n),
    _m(m)
{
    // Allocation de la mémoire pour la map
    _map = new int[n*m];

    // Tableau des distances
    _dist = new double[(n-2)*(m-2)];

    // Création de la map
    MapGenerator();
}

Espace::~Espace()
{
    delete[] _map;
    delete[] _dist;
}

//---------------------------------------------------------------------------

// Génére la carte de l'espace
void Espace::MapGenerator()
{
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;


        if(i!=_n/2 && i!=_n/2-1 && i!=_n/2+1){    // colonne du mileu
            _map[_m/2 + i*_m]=2;

        }

    }
    
    // Première et dernière colonne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }
    
}

int Espace::operator()(size_t i,size_t j) const
{
    return _map[j+i*_m];
}

int& Espace::operator()(size_t i,size_t j) 
{
    return _map[j+i*_m];
}

//--------------------------------------------------------------------------------------------
