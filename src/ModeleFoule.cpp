

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
}

ModeleFoule::~ModeleFoule()
{
    // Suppression de la foule
    for ( size_t i=0; i<_n; i++)
    {
        delete _foule[i];
    }

    for (Individu* In : _Levacues)
    {
        delete In;
    }

}

void ModeleFoule::InitFoule(Espace& espace)
{   
    // std::uniform_real_distribution<double> unif(0.2,0.35);
    std::uniform_real_distribution<double> posx(1,_espace_m/2-2);
    std::uniform_real_distribution<double> posy(1,_espace_n-2);
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    
    for(size_t i=0;i<_n;i++){
        
        // Génération de positions aléatoires
        double x = posx(re);
        double y = posy(re);
        // double r = unif(re);

        size_t k = y/pas_espace+1;
        size_t j = x/pas_espace+1;

        while (espace(k,j)==1 || espace(k,j)==2)
        {
            x = posx(re);
            y = posy(re);

            k = y/pas_espace+1;
            j = x/pas_espace+1;
        }
        
        // Ajout des Individus dans la foule
        _foule.push_back(new IndividuDisque(x,y,rayon_pietons,masse_pieton));
    }
}

//--------------------------------------------------------------------------------------------

// Calcule les force pour chacun des Individus
void ModeleFoule::CalculForce(FastMarching& FM,Espace* espace)
{
    # pragma omp parallel for schedule(static,1)
    for (Individu* person : _foule){
        person->ResetAcc();
        person->ForceAcceleration(FM);
        person->ForceInteractions(_foule,person);
        person->ForcesMur(*espace);
        person->ForcesMurDiag(*espace);
    }
        
}

// Calcule la position pour chaque individu
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

        // Suppression des individus hors de l'espace
        if(_foule[i]->get_pos().x <0 || _foule[i]->get_pos().x > _espace_m*pas_espace ||
            _foule[i]->get_pos().y<0 || _foule[i]->get_pos().y>_espace_n*pas_espace){
            _n--;
            delete _foule[i];
            _foule.erase(_foule.begin()+i);
            }
        
        // Evacuation des individus s'ils atteignent la sortie
        if((x==j_0 && y==i_0) || (y==i_0-1 && x==j_0) ||(y==i_0+1 && x==j_0)){
            _n--;
            _Levacues.push_back(_foule[i]);
            _foule.erase(_foule.begin()+i);
            _evacues++;
        }
    }   
}