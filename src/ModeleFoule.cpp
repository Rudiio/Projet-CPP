

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<cstdlib>
#include<random>
#include<chrono>
#include"ModeleFoule.hpp"
#include"parametres.hpp"

//-------------------------------------------------------------------------

ModeleFoule::ModeleFoule(size_t n,size_t espace_n,size_t espace_m):
    _n(nombre_pietons),
    _espace_n(espace_n),
    _espace_m(espace_m)
{
    InitFoule();
    InitGrille();
}

ModeleFoule::~ModeleFoule()
{
    // Suppression de la foule
    for ( size_t i=0; i<_n; i++)
    {
        delete _foule[i];
    }

    delete[] _first;
    delete[] _pointers;
}

void ModeleFoule::InitFoule()
{   
    // std::uniform_real_distribution<double> unif(0.2,0.35);
    std::uniform_real_distribution<double> posx(0,_espace_m/2-1);
    std::uniform_real_distribution<double> posy(0,_espace_n-2);
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    
    for(size_t i=0;i<_n;i++){
        double x = posx(re);
        double y = posy(re);
        // double r = unif(re);
        
        _foule.push_back(new IndividuDisque(x,y,rayon_pietons));
    }
}

//------------------------------------ FORCE DE REPULSION ------------------------------------------

void ModeleFoule::InitGrille()
{
    // Calcul de la taille de la grille
    _dx = 2*rayon_pietons;
    _nx = (_espace_m*pas_espace)/_dx;
    _ny = (_espace_n*pas_espace)/_dx;

    _xmin = -_dx*_nx/2;
    _ymin = -_dx*_ny/2; 

    // Création de la grille
    _first = new int[_nx*_ny];
    _pointers = new int[_n];

    // Initialisation
    VideGrille();
}

void ModeleFoule::VideGrille()
{
    for(size_t i=0;i<_nx*_ny;i++)
        _first[i]=-1;
    for(size_t i=0;i<_n;i++)
        _pointers[i]=-1;
}

void ModeleFoule::Grille()
{   
    VideGrille();
    for(size_t i=0;i<_foule.size();i++)
    {
        Individu& in = *_foule[i];

        // Calcul des indexs d'espace
        size_t k1 = (in.get_pos().x - _xmin)/_dx;
        size_t k2 = (in.get_pos().y - _ymin)/_dx;
        size_t l = k1 + _nx*k2;

        // Ajout d'un premier disque dans le tableau
        if(_first[l]==-1)
            _first[l] = i;
        
        // Ajout de Linking
        else{
            size_t ni = _first[l];

            while(_pointers[ni]!=-1){
                ni = _pointers[ni];
            }
            ni = i;
        }
    }
}

//--------------------------------------------------------------------------------------------

void ModeleFoule::CalculForce(FastMarching& FM)
{
    // Grille();
    for (Individu* person : _foule){
        person->ResetAcc();
        person->ForceAcceleration(FM);
        // person->ForceInteraction();
        person->ForceCorps(_xmin,_ymin,_dx,_nx,_ny,_first,_pointers);
        // person->ForceFrictionGlissante();
    }
        
}

void ModeleFoule::Euler(double h)
{
    for (Individu* person: _foule)
        person->_Euler(h);
}