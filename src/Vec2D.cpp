#include<cmath>
#include"Vec2D.hpp"
//-------------------------------- FONCTIONS GENERALES ---------------------------------------

double norm2(Vec2D X1,Vec2D X2) 
{
    double x = X2.x-X1.x;
    double y = X2.y-X1.y;

    return sqrt(x*x + y*y);
}

double norm(Vec2D X){return sqrt(X.x*X.x + X.y*X.y);}

double dot(Vec2D X1,Vec2D X2){return (X1.x*X2.x + X1.y*X2.y);}

Vec2D operator+(Vec2D X1, Vec2D X2)
{
    Vec2D res;

    res.x = X1.x+X2.x;
    res.y = X1.y+X2.y;

    return res;
}

Vec2D operator-(Vec2D X1, Vec2D X2)
{
    Vec2D res;

    res.x = X1.x-X2.x;
    res.y = X1.y-X2.y;

    return res;
}

Vec2D operator*(double a, Vec2D X)
{
    return Vec2D(a*X.x,a*X.y);
}

Vec2D operator/(Vec2D X,double a)
{
    return Vec2D(X.x/a,X.y/a);
}

bool operator==(Vec2D X1,Vec2D X2)
{
    if(X1.x==X2.x && X1.y==X2.y)
        return true;
    
    return false;
}

Vec2D ProjeteOrthogonal(Vec2D pos, Vec2D A, Vec2D B)
{
    Vec2D AB = B - A;
    Vec2D OA = A;

    double d_ab = norm(AB);

    Vec2D t = AB/d_ab;

    Vec2D OH = OA + dot(pos - A,t)*t;

    Vec2D BH = OH - B;

    Vec2D AH = OH -A;

    if(dot(BH,AH)<0)
        return OH;
    
    return pos;

}

//--------------------------------------------------------------------------