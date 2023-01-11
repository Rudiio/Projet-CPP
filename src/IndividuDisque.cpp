
//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include"IndividuDisque.hpp"

//-------------------------------------------------------------------------

IndividuDisque::IndividuDisque(double x, double y,double rayon):
    Individu(x,y),
    _rayon(rayon)
{
    aire = Aire();

    // Couleur d'affichage de l'individu
    rgb[0]=178; // Rouge
    rgb[1]=34; // Vert
    rgb[2]=34; // Bleu
}

void IndividuDisque::_DrawIndividu(SDL_Window *window,SDL_Renderer *renderer,int opt[])
{
    // Options d'affichage
    // int width = opt[0];
    int offset = opt[2];     
    int graduation = opt[3]; 
    int convert = opt[4];    
    int x_offset = opt[5];  
    int y_offset = opt[6];
    int case_size = opt[7];

    // Détermination des nouvelles positions
    // Conversion du mètre en pixels
    double scaled_x =  (pos.x)*convert/graduation + offset + x_offset + case_size;
    double scaled_y = (pos.y)*convert/graduation + offset + y_offset + case_size;
    double scaled_r = _rayon*convert/graduation;

    // Affichage
    DrawDisque(window,renderer,scaled_x,scaled_y,scaled_r);  // Inversion des x et y pour la SDL

}

/* Dessine un Disque de centre (x,y) et de rayon r*/
void IndividuDisque::DrawDisque(SDL_Window *window,SDL_Renderer *renderer,double xc,double yc, double r)
{   
	for ( int x = (int) xc - r; x <= xc + r; x++) 
		for ( int y = (int) yc - r; y <= yc + r; y++) 
			if ((((x-xc) * (x -xc)) + ((y - yc) * (y - yc))) < (r*r)){
                SDL_SetRenderDrawColor(renderer,rgb[0],rgb[1],rgb[2],255);
      			SDL_RenderDrawPoint(renderer, x, y);
            }
}

void IndividuDisque::CalculForces()
{

}

void IndividuDisque::toString()
{
    std::cout << "Je suis un disque" << std::endl;
}

double IndividuDisque::Aire()
{
    return PI*_rayon*_rayon;
}

IndividuDisque::~IndividuDisque()
{

}