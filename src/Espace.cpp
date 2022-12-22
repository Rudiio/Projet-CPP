
//------------------------- INCLUDES ---------------------------------------
#include"Espace.hpp"


//-------------------------------------------------------------------------


Espace::Espace(size_t n,size_t m):
    _n(n),
    _m(m)
{
    // Allocation de la mémoire pour la map
    _map = new bool[n*m];

    // Création de la map
    MapGenerator();
}


Espace::~Espace()
{
    delete[] _map;
}

//---------------------------------------------------------------------------

// Génére la carte de l'espace
void Espace::MapGenerator()
{
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++)
        _map[i]=false;

    // Génération de la carte
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = true;
        _map[(_m-1)+ i*_m]=true;
    }
    
    for(size_t j=0;j<_m;j++){
        _map[j] = true;
        _map[j + (_n-1)*_m]=true;
    }
    
}

//----------------------------------------------------------------------------

bool Espace::operator()(size_t i,size_t j) const
{
    return _map[j+i*_m];
}

bool& Espace::operator()(size_t i,size_t j) 
{
    return _map[j+i*_m];
}