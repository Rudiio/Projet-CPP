

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include"ModeleFoule.hpp"

//-------------------------------------------------------------------------

ModeleFoule::ModeleFoule(size_t n):
    _n(n)
{
    InitFoule();
    // _foule[0]->toString();
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
    for(size_t i=0;i<_n;i++){
        _foule.push_back(new IndividuDisque(3.5,i*2+1,0.5));
    }
}
