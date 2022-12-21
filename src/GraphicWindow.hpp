#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<SDL2/SDL.h>


//-------------------------------------------------------------------------

// Interface pour la mise en place de la partie graphique 
class GraphicWindow 
{
    public:
        GraphicWindow(int width,int heigth,const std::string title);
        ~GraphicWindow();
        // virtual void Mainloop();
        // virtual void Render();

    protected:
        SDL_Window* window;
        SDL_Renderer* renderer;

    private:
        
        int _width;
        int _heigth;
        std::string _title;
};