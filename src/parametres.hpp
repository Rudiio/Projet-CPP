#pragma once

#include<iostream>

//********************************* PARAMETRES DE SIMULATION *******************************************

// ------------------------------ PARAMETRES D'AFFICHAGE ---------------------------------------------------

const size_t WIDTH = 1080;      // Largeur de la fenêtre 

const size_t HEIGTH = 720;      // Hauteur de la fenêtre

const int offset = 30;      // Offset de l'affichage paer rapport au coin en haut à gauche

const int __convert = 10;     // équivalent de l'unité d'espace en pixels (permet de changer la taille de l'affichage et de la simulation)

// ------------------------------ PARAMETRES DE l'ESPACE DE SIMULATION --------------------------------------

const size_t Nx = ((HEIGTH-2*offset)/__convert);      // Nombre de ligne de l'espace

const size_t Ny = ((WIDTH-2*offset)/__convert);       // Nombre de colonne de l'espace

const size_t i_0=Nx/2;    // ordonnées du point d'évacuation

const size_t j_0=Ny-2;    // abscisse du point d'évacuation 

const size_t map = 1;   // choix de la map

// ------------------------------ PARAMETRES DES PIETONS/FOULE --------------------------------------

const size_t nombre_pietons = 1000; //Nombre de piétons

const double rayon_pietons = 0.5; // Rayons des piétons

const double masse_pieton = 70;    // Masse des piétons

const double vs = 30.34; // Vitesse des piétons (en m/s) 10.34

// ------------------------------ PARAMETRES DE MODELISATION --------------------------------------

const double pas_de_temps = 0.001; // Pas de  temps (en s)

const size_t pas_espace = 1; // Pas d'espace en m et l'unité d'espace en m

const double tau = 0.5; // temps de relaxation en s

const double PI = 3.14159265358979323846;

const double Ai = 2*10 ;//2*pow(10,3); // Coefficient d'interaction sociale entre individu (en Newton)

const double Bi = 0.08; // en mètres

const double k = 1.2*500000; // Coefficient de répulsion individu-individu (en kg.s^-2)

const double K = 2.4*20; // Coefficient de répulsion glissante individu-individu (en km.m^-1.s^-1)

const double Ai_mur = 2*1;    //  Coefficient d'interaction individu-mur (en Newton) 

const double k_mur = 1.4*1000000;  // Coefficient de répulsion individu-mur (en kg.s^-2)

const double K_mur = 1.2*100;    // Coefficient de répulsion glissante individu-mur (en km.m^-1.s^-1)

const double softening = 0.5; // Permet de corriger les interactions entre piétons trop proches

