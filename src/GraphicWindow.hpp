#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<SDL2/SDL.h>
#include"Espace.hpp"

//-------------------------------------------------------------------------

// Interface pour la mise en place de la partie graphique 
class GraphicWindow 
{
    public:
        // Constructeur et Destricteur
        GraphicWindow(size_t width,size_t heigth,const std::string title);
        ~GraphicWindow();
        
        // virtual void Mainloop();
        // virtual void Render();
        
        //fonctions d'affichage de base
        void blit();
        void CleanScreen();

        //fonctions d'affichage spécifiques
        virtual void Render() =0;
        void DrawCase(Espace& espace,size_t i,size_t j);
        void DrawEspace(Espace& espace);

        // Getteurs
        int get_width() const { return _width;}
        int get_heigth() const {return _heigth;}
        int get_case_size() const {return _case_size;}

    protected:
        // Variables de la SDL
        SDL_Window* window;
        SDL_Renderer* renderer;
        

    private:
        size_t _width;
        size_t _heigth;
        std::string _title;
        size_t _case_size; // Taille en pixels d'un coté du quadrillage

        int graduation; // Graduation en m
        int convert;    // Equivalent de la graduation en pixels
};