
//------------------------- INCLUDES ---------------------------------------
#include"Espace.hpp"
#include"parametres.hpp"
#include<cmath>
//--------------------------------------------------------------------------

Espace::Espace(size_t n,size_t m):
    _n(n),
    _m(m)
{
    // Allocation de la mémoire pour la map
    _map = new int[n*m];

    // Création de la 
    if(map==0)
        MapGenerator();
    else if(map==1)
        MapGenerator1();
    else if(map==2)
        MapGenerator2();
    else if(map==3)
        MapGenerator3();
    else if (map==4)
        MapGenerator4();
    else if (map==5)
        MapGenerator5();
    else if(map==6)
        MapGenerator6();
    else 
        MapGenerator7();
}

Espace::~Espace()
{
    delete[] _map;
}

//---------------------------------------------------------------------------


// Génére la carte de l'espace
void Espace::MapGenerator()
{
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;

    }
    

    // Première et dernière colonne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }

}

// Génére la carte de l'espace
void Espace::MapGenerator1()
{
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;


        if(i!=_n/2 && i!=_n/2-1 && i!=_n/2+1){    // colonne du mileu
            _map[_m/2 + i*_m]=2;
            _map[_m/2+1 + i*_m]=2;
        }

    }

    // Première et dernière colonne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }

}

// Génére la carte de l'espace
void Espace::MapGenerator2()
{
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;


        if(i!=_n/2 && i!=_n/2-1 && i!=_n/2+1){    // colonne du mileu
            _map[_m/2 + i*_m]=2;
            _map[_m/2+1 + i*_m]=2;
        }

    }
    
    _map[_m/2-2 + _n/2*_m]  = 2;
    _map[_m/2-3 + _n/2*_m]  = 2;
    _map[_m/2-2 + (_n/2-1)*_m]  = 2;
    _map[_m/2-3 + (_n/2-1)*_m]  = 2;
    _map[_m/2-2 + (_n/2+1)*_m]  = 2;
    _map[_m/2-3 + (_n/2+1)*_m]  = 2;

    // Première et dernière colonne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }
}

// Génére la carte de l'espace
void Espace::MapGenerator3()
{
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte
    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;

    }

    for(size_t i=0; i<_n;i++)
        for(size_t j=0;j<_m;j++)
        {
            if(j%5==0 && i%5==0){
                _map[i*_m + j] =2;
                _map[i*_m + j+1] =2;
                _map[(i+1)*_m + j] =2;
                _map[(i+1)*_m + j+1] =2;
            }
        }

    // Première et dernière ligne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }

}
void Espace::MapGenerator4(){
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;

        if(i!=_n/3 && i!=_n/3-1 && i!=_n/3+1 && i!=2*_n/3 && i!= 2*_n/3-1 && i!=2*_n/3+1){   
            _map[_m/2 + i*_m]=2;
            _map[_m/2+1 + i*_m]=2;
        }
        else {
            _map[2*_m/3 + i*_m]=2;
            _map[2*_m/3+1 + i*_m]=2;
        }
    }
    

    // Première et dernière colonne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }
}

void Espace::MapGenerator5()
{
    // Initialisation de la carte
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;

        if(i!=_n/3 && i!=_n/3-1 && i!=_n/3+1 && i!=2*_n/3 && i!= 2*_n/3-1 && i!=2*_n/3+1){   
            _map[_m/2 + i*_m]=2;
            _map[_m/2+1 + i*_m]=2;
        }
        else {
            _map[2*_m/3 + i*_m]=2;
            _map[2*_m/3+1 + i*_m]=2;
        }
        if (i>_n/3-1 && i<2*_n/3+1){
            _map[3*_m/3-6+i*_m]=2;
            _map[3*_m/3-6+1+i*_m]=2;
        }



    }
    

    // Première et dernière colonne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }

    // _map[_m/2-1+(_n/2+2)*_m]=2;
    // _map[_m/2-2+(_n/2+3)*_m]=2;
    // _map[_m/2-3+(_n/2+4)*_m]=2;
    // _map[_m/2-4+(_n/2+5)*_m]=2;

    // _map[_m/2+1+(_n/2-2)*_m]=2;
    // _map[_m/2-2+(_n/2+3)*_m]=2;
    // _map[_m/2-3+(_n/2+4)*_m]=2;
    // _map[_m/2-4+(_n/2+5)*_m]=2;

}

void Espace::MapGenerator6(){
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;

    }

    _map[_m-9+(_n/2-7)*_m]=2;
    _map[_m-10+(_n/2-6)*_m]=2;
    _map[_m-11+(_n/2-5)*_m]=2;
    _map[_m-12+(_n/2-4)*_m]=2;
    _map[_m-13+(_n/2-3)*_m]=2;
    _map[_m-14+(_n/2-2)*_m]=2;
    _map[_m-15+(_n/2-1)*_m]=2;
    
    _map[_m-16+(_n/2)*_m]=2;

    _map[_m-15+(_n/2+1)*_m]=2;
    _map[_m-14+(_n/2+2)*_m]=2;
    _map[_m-13+(_n/2+3)*_m]=2;
    _map[_m-12+(_n/2+4)*_m]=2;
    _map[_m-11+(_n/2+5)*_m]=2;
    _map[_m-10+(_n/2+6)*_m]=2;
    _map[_m-9+(_n/2+7)*_m]=2;
    

    // Première et dernière colonne
    for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }


}

void Espace::MapGenerator7(){
    for(size_t i=0;i<_n*_m;i++){
        _map[i]=0;
    }

    // Génération de la carte

    // Première et dernière colonne
    for(size_t i=0;i<_n;i++){
        _map[i*_m] = 1;
        _map[(_m-1)+ i*_m]=1;

    }

     for(size_t j=0;j<_m;j++){
        _map[j] = 1;
        _map[j + (_n-1)*_m]=1;
       
    }

    _map[_m/2+(_n/2)*_m]=2;
    _map[_m/2+(_n/2+1)*_m]=2;
    _map[_m/2+(_n/2+2)*_m]=2;
    _map[_m/2+(_n/2+3)*_m]=2;
    _map[_m/2+(_n/2+4)*_m]=2;
    _map[_m/2+(_n/2+5)*_m]=2;
    _map[_m/2+(_n/2+6)*_m]=2;
    _map[_m/2+(_n/2+7)*_m]=2;
    _map[_m/2+(_n/2-1)*_m]=2;
    _map[_m/2+(_n/2-2)*_m]=2;
    _map[_m/2+(_n/2-3)*_m]=2;
    _map[_m/2+(_n/2-4)*_m]=2;
    _map[_m/2+(_n/2-5)*_m]=2;
    _map[_m/2+(_n/2-6)*_m]=2;
    _map[_m/2+(_n/2-7)*_m]=2;
    _map[_m/2+1+(_n/2+6)*_m]=2;

    _map[_m/2+1+(_n/2+7)*_m]=2;
    _map[_m/2+2+(_n/2+7)*_m]=2;
    _map[_m/2+3+(_n/2+7)*_m]=2;
    _map[_m/2+4+(_n/2+7)*_m]=2;
    _map[_m/2+5+(_n/2+7)*_m]=2;
    _map[_m/2+6+(_n/2+7)*_m]=2;
    _map[_m/2+7+(_n/2+7)*_m]=2;
    _map[_m/2+8+(_n/2+7)*_m]=2;





    // _map[_m/2+2+(_n/2)*_m]=2;
    // _map[_m/2+3+(_n/2)*_m]=2;
    // _map[_m/2+4+(_n/2)*_m]=2;
    // _map[_m/2+5+(_n/2)*_m]=2;
    // _map[_m/2+6+(_n/2)*_m]=2;
    // _map[_m/2+7+(_n/2)*_m]=2;
    // _map[_m/2+8+(_n/2)*_m]=2;

}


int Espace::operator()(size_t i,size_t j) const
{
    return _map[j+i*_m];
}

int& Espace::operator()(size_t i,size_t j) 
{
    return _map[j+i*_m];
}

//--------------------------------------------------------------------------------------------
