
//------------------------- INCLUDES ---------------------------------------
#include"FastMarching.hpp"
#include"parametres.hpp"
#include<cmath>

//-------------------------------- FONCTIONS GENERALES ---------------------------------------



//--------------------------------------------------------------------------

FastMarching::FastMarching(Espace* espace,double graduation):
_espace(espace),
__n(espace->get_n()),
__m(espace->get_m()),
_i0(i_0),
_j0(j_0),
_p(graduation)
{
    // Création de dist
    _dist = new double[__n*__m];

    // Création de fini
    _fini = new size_t[__n*__m];
    
}

FastMarching::~FastMarching()
{
    delete[] _dist;
    delete[] _fini;
}


//---------------------------- FAST-MARCHING/ALGORITHME DE DIJKSTRA ----------------------------------------

void FastMarching::InitFM(size_t _i0,size_t _j0,size_t t)
{
    // Initialisation des distances
    double inf = pow(10.0,t);
    for(size_t i=0;i<(__n)*(__m);i++){
        _dist[i]= inf;
    }
    _dist[_i0*__m + _j0]=0;    // Point d'arrivée avec une distance nulle

    // Initialisation de fini
    for(size_t i=0;i<__n;i++)
        for(size_t j=0;j<__m;j++){
            if( (*_espace)(i,j)==2 ||(*_espace)(i,j)==1 )
                _fini[i*__m + j]=1;
            else if ((*_espace)(i,j)==0)
                _fini[i*__m + j]=0;
        }
    
    L.push_back(Vec2D(_i0,_j0));
}       

std::vector<Vec2D> FastMarching::voisins(size_t i,size_t j)
{
    std::vector<Vec2D> voisins;

    if(i+1<__n)
        voisins.push_back(Vec2D(i+1,j));
    if(i-1>=0)
        voisins.push_back(Vec2D(i-1,j));
    if(j+1<__m)
        voisins.push_back(Vec2D(i,j+1));
    if(j-1>=0)
        voisins.push_back(Vec2D(i,j-1));
    
    return voisins;
}

bool FastMarching::in(std::vector<Vec2D> L,size_t i,size_t j)
{
    for(size_t x=0; x<L.size();x++)
    {
        if(L[x].x==i && L[x].y==j)
            return true;
        
    }

    return false;
}

void FastMarching::FM()
{   
    // Valeur de t pour l'infini
    size_t t=__m;
    if(__n>__m)
        t = __n;
    
    // Initialisation du Fast-Marching (dist,fini,L)
    InitFM(_i0,_j0,t);

    while (L.size()!=0 ) 
    {
        double d = pow(10.0,t);
        size_t r=0;
        // Recherche de la plus petite distance
        for(size_t i=0;i<L.size();i++){
            size_t ci = L[i].x;
            size_t cj = L[i].y;

            if(_dist[ci*__m + cj] < d){
                d = _dist[ci*__m + cj];
                r = i;
            }
        }

        size_t min_i = L[r].x;
        size_t min_j = L[r].y;

        // Calcul des voisins
        std::vector<Vec2D> v = voisins(min_i,min_j);

        // Calcul des distances des voisins
        for(size_t i=0;i<v.size();i++)
        {
            size_t vi = v[i].x;
            size_t vj = v[i].y;

            if(_fini[vi*__m + vj]!=1){
                if(_dist[min_i*__m + min_j] + _p < _dist[vi*__m + vj])
                    _dist[vi*__m + vj] = _dist[min_i*__m + min_j] + _p;

                if (!in(L,vi,vj))
                    L.push_back(v[i]);
            }
            
        }

        L.erase(L.begin()+r);
        _fini[min_i*__m + min_j]=1;
    
    }

    // for(size_t i=0;i<__n*__m;i++){
    // if(i%__m==0)
    //     std::cout << std::endl;
    // std::cout << " " <<_dist[i]<< " ";
    // }
    // std::cout << std::endl;
}

//--------------------------------------------------------------------------------------------

double FastMarching::operator()(size_t i,size_t j)
{
    return _dist[i*__m+ j];
}

Vec2D FastMarching::Gradient(size_t i,size_t j)
{
    Vec2D gradient;

    // Calcul du gradient
    gradient.x = _dist[i*__m+ (j+1)] - _dist[i*__m+ (j-1)];
    gradient.y = _dist[(i+1)*__m+ j] - _dist[(i-1)*__m+ j];

    if(GetPosEspace(i+1,j)==2 )
        gradient.y=0;

    if(GetPosEspace(i,j+1)==2  )
        gradient.x=0;

    double gnorm = norm(gradient);

    if(gnorm>0){
        gradient.x /=gnorm;
        gradient.y /=gnorm;
    }

    // std::cout << "i=" << i << " j=" << j << " x=" << gradient.x << ", y=" << gradient.y << std::endl;

    return gradient;
}

size_t FastMarching::GetPosEspace(size_t i,size_t j)
{
    return (*_espace)(i,j);
}