
//------------------------- INCLUDES --------------------------------------------------
#include<iostream>
#include<string>
#include"Individu.hpp"
#include"parametres.hpp"

//--------------------------------------------------------------------------------------

Individu::Individu(double x, double y,double masse):
    PointMeca(Vec2D<double>(0,0),Vec2D<double>(0,0),Vec2D<double>(x,y),masse)
{
    
}

Individu::~Individu()
{

}

// ----------------------- FORCES -----------------------------------------------------

// Calcules les force d'interaction de l'individu par rapport à tous les autres
void Individu::ForceInteractions(std::vector<Individu*> foule,Individu* current)
{   
    // Itération sur la foule
    for(size_t j=0;j<foule.size();j++)
    {
        Individu* b = foule[j];

        // Calcul des forces
        if(b!=current){
            ForcesPsycho(b);
            ForcesCorps(b);
            ForcesGlissante(b);
        }
    }
}

// Calcule la force d'accélération
void Individu::ForceAcceleration(FastMarching& FM)
{

    // Calcul des coordonnées de l'individu
    size_t x = pos.y/pas_espace +1;
    size_t y = pos.x/pas_espace +1; 

    // Calcul du gradient
    Vec2D<double> gradient=FM.Gradient(x,y);
    gradient.x *= -vs;
    gradient.y *= -vs;

    // Calcul de la force
    acc.x += m/tau * (gradient.x - vit.x);
    acc.y += m/tau * (gradient.y - vit.y);

}

// Calcule la force appliquées par les murs autour
void Individu::ForcesMur(Espace& espace)
{
    // Déterminer si l'individu est pres de mur
    size_t i = pos.y/pas_espace +1; // case dans le tableau d'espace
    size_t j = pos.x/pas_espace +1; // case dans le tableau d'espace

    // Mur au dessus
    if(espace(i-1,j)==2 ||espace(i-1,j)==1){
        Vec2D<double> projete(pos.x,pas_espace*(i-1));
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // Mur en dessous
    if(espace(i+1,j)==2 || espace(i+1,j)==1){
        Vec2D<double> projete(pos.x,pas_espace*i);
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // mur à gauche 
    if(espace(i,j-1)==2 || espace(i,j-1)==1){
        Vec2D<double> projete(pas_espace*(j-1),pos.y);
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // Mur à droite
    if(espace(i,j+1)==2 || espace(i,j+1)==1){
        Vec2D<double> projete(pas_espace*j,pos.y);
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }
}

// Calcule la force appliquées par les murs des coins
void Individu::ForcesMurDiag(Espace& espace)
{
    // Déterminer si l'individu est pres de mur
    size_t i = pos.y/pas_espace +1; // case dans le tableau d'espace
    size_t j = pos.x/pas_espace +1; // case dans le tableau d'espace

    // Diagonale en haut à droite
    if(espace(i-1,j+1)==2 ||espace(i-1,j+1)==1){
        Vec2D<double> projete(pas_espace*(j),pas_espace*(i-1));
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // Diagonale en haut à gauche
    if(espace(i-1,j-1)==2 || espace(i-1,j-1)==1){
        Vec2D<double> projete(pas_espace*(j-1),pas_espace*(i-1));
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // Diagonale en bas à gauche
    if(espace(i+1,j-1)==2 || espace(i+1,j-1)==1){
        Vec2D<double> projete(pas_espace*(j-1),pas_espace*(i));
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }

    // Diagonale en bas à droite
    if(espace(i+1,j+1)==2 || espace(i+1,j+1)==1){
        Vec2D<double> projete(pas_espace*(j),pas_espace*(i));
        ForcesPsychoMur(projete);
        ForceRepulsionMur(projete);
        ForceGlissanteMur(projete);
    }
}

//--------------------------------------------------------------------------------------

// Réinitialisation de l'accélération
void Individu::ResetAcc()
{
    acc.x=0;
    acc.y=0;
}

/* Intègre l'accélération puis la vitesse en utilisant une méthode d'Euler d'ordre 2*/
void Individu::_Euler(double h)
{
    // Calcul de la vitesse
    vit.x += h*acc.x;
    vit.y += h*acc.y;

    // Calcul de la position
    pos.x += h*vit.x;
    pos.y += h*vit.y;

}