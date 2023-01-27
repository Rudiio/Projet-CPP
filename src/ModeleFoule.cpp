

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<cstdlib>
#include<random>
#include<chrono>
#include<omp.h>
#include"ModeleFoule.hpp"
#include"parametres.hpp"

//-------------------------------------------------------------------------

ModeleFoule::ModeleFoule(size_t n,size_t espace_n,size_t espace_m):
    _n(n),
    _espace_n(espace_n),
    _espace_m(espace_m),
    _evacues(0)
{
    InitFoule();
}

ModeleFoule::~ModeleFoule()
{
    // Suppression de la foule
    for ( size_t i=0; i<_n; i++)
    {
        delete _foule[i];
    }

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

//--------------------------------------------------------------------------------------------

void ModeleFoule::CalculForce(FastMarching& FM,Espace* espace)
{
    # pragma omp parallel for schedule(static,1)
    for (Individu* person : _foule){
        person->ResetAcc();
        person->ForceAcceleration(FM);
        person->ForceInteractions(_foule,person);
        person->ForcesMur(*espace);
    }
        
}

void ModeleFoule::Euler(double h)
{
    #pragma omp parallel for schedule(static,1)
    for (Individu* person: _foule)
        person->_Euler(h);
}

//--------------------------------------------------------------------------------------------

void ModeleFoule::Evacutation()
{
    for(size_t i=0;i<_foule.size();i++){
        size_t x = _foule[i]->get_pos().x/pas_espace +1;
        size_t y = _foule[i]->get_pos().y/pas_espace +1;

        // std::cout << "x= " <<  << "y= " << y << std::endl;

        if(x==j_0 && y==i_0){
            _n--;
            _foule.erase(_foule.begin()+i);
            _evacues++;
        }
    }   
}