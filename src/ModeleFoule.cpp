

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<cstdlib>
#include<random>
#include<chrono>
#include"ModeleFoule.hpp"

//-------------------------------------------------------------------------

ModeleFoule::ModeleFoule(size_t n,size_t espace_n,size_t espace_m):
    _n(n),
    _espace_n(espace_n),
    _espace_m(espace_m)
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
    std::uniform_real_distribution<double> unif(0.2,0.35);
    std::uniform_real_distribution<double> posx(0,_espace_m/2-1);
    std::uniform_real_distribution<double> posy(0,_espace_n-2);
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    
    for(size_t i=0;i<_n;i++){
        double x = posx(re);
        double y = posy(re);
        double r = unif(re);
        
        _foule.push_back(new IndividuDisque(x,y,r));
    }
}
