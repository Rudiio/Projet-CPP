
//------------------------- INCLUDES --------------------------------------------------
#include<iostream>
#include<string>
#include"Individu.hpp"
#include"parametres.hpp"

//--------------------------------------------------------------------------------------

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

// ----------------------- FORCES -----------------------------------------------------

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

void Individu::ForcesMur(Espace& espace)
{
    // Déterminer si l'individu est pres de mur
    size_t i = pos.y/pas_espace +1; // case dans le tableau d'espace
    size_t j = pos.x/pas_espace +1; // case dans le tableau d'espace

    // Mur au dessus
    if(espace(i-1,j)==2 ||espace(i-1,j)==1){
        Vec2D projete(pos.x,pas_espace*(i-1));
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // Mur en dessous
    if(espace(i+1,j)==2 || espace(i+1,j)==1){
        Vec2D projete(pos.x,pas_espace*i);
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // mur à gauche 
    if(espace(i,j-1)==2 || espace(i,j-1)==1){
        Vec2D projete(pas_espace*(j-1),pos.y);
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // Mur à droite
    if(espace(i,j+1)==2 || espace(i,j+1)==1){
        // On replace les index dans l'espace
        Vec2D projete(pas_espace*j,pos.y);
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }
}

//--------------------------------------------------------------------------------------

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