#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<SDL2/SDL.h>
#include"Espace.hpp"
#include"ModeleFoule.hpp"

//-------------------------------------------------------------------------

// Interface pour la mise en place de la partie graphique 
class GraphicWindow 
{
    public:
        // Constructeur et Destricteur
        GraphicWindow(size_t width,size_t heigth,const std::string title);
        ~GraphicWindow();
        
        virtual void Mainloop()=0;
        
        //fonctions d'affichage de base
        void blit();
        void CleanScreen();
        void Background();

        //fonctions d'affichage spécifiques
        virtual void Render() =0;
        void DrawAxis();
        void DrawCase(Espace& espace,size_t i,size_t j);
        void DrawEspace(Espace& espace);
        void DrawFoule(ModeleFoule& foule);

        // Inputs 
        virtual void Input() =0;

        // Getteurs
        int get_width() const { return _width;}
        int get_heigth() const {return _heigth;}
        int get_case_size() const {return _case_size;}
        int get_offset() const {return _offset;}
        int get_convert() const {return _convert;}

        // Setteurs
        void add_x(int val,int x_val_ori) { _x_offset +=val;_x_origine+=x_val_ori;} 
        void add_y(int val,int y_val_ori) { _y_offset +=val;_y_origine+=y_val_ori;} 

    protected:
        // Variables de la SDL
        SDL_Window* window;
        SDL_Renderer* renderer;
        

    private:
        // Paramètres de la fenêtre
        size_t _width;
        size_t _heigth;
        std::string _title;
        size_t _case_size; // Taille en pixels d'un coté du quadrillage
        
        // Paramètres d' affichage
        int _offset;     // Offset pour l'affichage (créé un cadre)
        int _graduation; // Graduation en m
        int _convert;    // Equivalent de la graduation en pixels
        int _x_offset;  //  Décalage d'affichage sur les x -> permet le déplacement de l'affichage sur les x
        int _y_offset;  // Décalage d'affichage sur les y -> permet le déplacement de l'affichage sur les y
        int _x_origine;  // origine sur les x
        int _y_origine;  // origine sur les y
};