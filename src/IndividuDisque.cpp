
//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<cstdlib>
#include"IndividuDisque.hpp"
#include<cmath>

//------------------------------------------------------------------------------------

IndividuDisque::IndividuDisque(double x, double y,double rayon):
    Individu(x,y),
    _rayon(rayon_pietons)
{
    aire = Aire();

    // rgb[0]=178; // Rouge
    // rgb[1]=34; // Vert
    // rgb[2]=34; // Bleu
    rgb[0]=rand()%256; // Rouge
    rgb[1]=rand()%256; // Vert
    rgb[2]=rand()%256; // Bleu
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

// ----------------------- FORCES -----------------------------------------------------

void IndividuDisque::ForcesPsycho(Individu* b)
{
    // Somme des rayons
    double R = _rayon + b->get_rayon();

    // Distance entre a et b
    double  d_ab = norm2(pos,b->get_pos());
    
    // vecteur direction
    Vec2D<double> u_ab = pos - b->get_pos();

    // Ajout de la force
    acc = acc + Ai*exp((R-d_ab)/Bi)*(u_ab/(d_ab+softening+1));
}

void IndividuDisque::ForcesCorps(Individu* b)
{
    // Somme des rayons
    double R = _rayon + b->get_rayon();

    // Distance entre a et b
    double  d_ab = norm2(pos,b->get_pos());

    if(d_ab < R){
        // vecteur direction
        Vec2D<double> u_ab = pos - b->get_pos();

        // Ajout de la force
        acc = acc + k*(R-d_ab)*u_ab/(d_ab+softening);
    }
}

void IndividuDisque::ForcesGlissante(Individu* b)
{   
    // Somme des rayons
    double R = _rayon + b->get_rayon();

    // Distance entre a et b
    double  d_ab = norm2(pos,b->get_pos());
    
    if(d_ab < R){
        // vecteur orthogona à AB
        Vec2D<double> t;
        t.x = -(pos.y - b->get_pos().y)/(d_ab+softening);
        t.y = (pos.x - b->get_pos().x)/(d_ab+softening);
        
        // Ajout de la force
        acc = acc + K*(R - d_ab*dot(b->get_vit() - vit,t))*t;;
    }
}   

void IndividuDisque::ForceRepulsionMur(Vec2D<double> projete)
{
    // Distance entre a et b
    double  d_ab = norm2(pos,projete);

    // std::cout << "distance " <<d_ab << std::endl;
    if(d_ab < _rayon){
        // vecteur direction
        Vec2D<double> u_ab = pos - projete;

        // Ajout de la force
        acc = acc + k_mur*(_rayon-d_ab)*u_ab/(d_ab+softening);
    }
}

void IndividuDisque::ForceGlissanteMur(Vec2D<double> projete)
{
    // Distance entre a et b
    double  d_ab = norm2(pos,projete);
    
    if(d_ab < _rayon){
        // vecteur orthogonal à AB
        Vec2D<double> t;
        t.x = -(pos.y - projete.y)/(d_ab+softening);
        t.y = (pos.x - projete.x)/(d_ab+softening);
        
        // Ajout de la force
        acc = acc + K_mur*(_rayon - d_ab*dot(-1*vit,t))*t;
    }
}

void IndividuDisque::ForcesPsychoMur(Vec2D<double> projete)
{

    // Distance entre a et b
    double  d_ab = norm2(pos,projete);
    
    // vecteur direction
    Vec2D<double> u_ab = pos - projete;

    // Ajout de la force
    acc = acc + Ai_mur*exp((_rayon-d_ab)/Bi)*u_ab/(d_ab+softening);
}

//------------------------------------------------------------------------------------

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