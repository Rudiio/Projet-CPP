
//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include"Individu.hpp"
#include"parametres.hpp"

//-------------------------------------------------------------------------

Individu::Individu(double x, double y):
    acc(Vec2D(0,0)),
    vit(Vec2D(0,0)),
    pos(Vec2D(x,y)),
    m(masse_pieton)
{
    
}

Individu::~Individu()
{

}


void Individu::_CalculForces(FastMarching& FM)
{   
    // Calcul des forces à l'étape actuelle
    // ResetAcc(); // On met l'accélération à 0 
    // ForceAcceleration(FM);
    // // ForceInteractions();
    // // ForceCorps();
    // ForceFrictionGlissante();

}

void Individu::ForceInteractions(std::vector<Individu*> foule,Individu* current)
{   
    // Itération sur la foule
    for(size_t j=0;j<foule.size();j++)
    {
        Individu* b = foule[j];

        if(b!=current){
            ForcesPsycho(b);
            ForcesCorps(b);
            ForcesGlissante(b);
        }
    }
}

void Individu::ForceAcceleration(FastMarching& FM)
{

    // Calcul des coordonnées de l'individu
    size_t x = pos.y/pas_espace +1;
    size_t y = pos.x/pas_espace +1; 

    // Calcul du gradient
    Vec2D gradient=FM.Gradient(x,y);
    gradient.x *= -vs;
    gradient.y *= -vs;

    // Calcul de la force
    acc.x += m/tau * (gradient.x - vit.x);
    acc.y += m/tau * (gradient.y - vit.y);

}

void Individu::ResetAcc()
{
    acc.x=0;
    acc.y=0;
}

/* Intègre l'accélération puis la vitesse en utilisant une méthode d'Eler d'ordre 2*/
void Individu::_Euler(double h)
{
    // Calcul de la vitesse
    vit.x += h*acc.x;
    vit.y += h*acc.y;

    // Calcul de la position
    pos.x += h*vit.x;
    pos.y += h*vit.y;

}