#pragma once

//------------------------- INCLUDES ---------------------------------------
#include<iostream>
#include<string>
#include<cmath>

//-------------------------------------------------------------------------

template<typename T>
class Vec2D
{
    public:
        Vec2D(T _x=0, T _y=0):
            x(_x),
            y(_y)
        {}

        Vec2D(const Vec2D& X):
            x(X.x),
            y(X.y)
        {}

        T x;
        T y;
};

template<typename T>
double norm2(Vec2D<T> X1,Vec2D<T> X2) 
{
    T x = X2.x-X1.x;
    T y = X2.y-X1.y;

    return sqrt(x*x + y*y);
}

template<typename T>
double norm(Vec2D<T> X){return sqrt(X.x*X.x + X.y*X.y);}

template<typename T>
T dot(Vec2D<T> X1,Vec2D<T> X2){return (X1.x*X2.x + X1.y*X2.y);}

template<typename T>
Vec2D<T> operator+(Vec2D<T> X1, Vec2D<T> X2)
{
    Vec2D<T> res;

    res.x = X1.x+X2.x;
    res.y = X1.y+X2.y;

    return res;
}

template<typename T>
Vec2D<T> operator-(Vec2D<T> X1, Vec2D<T> X2)
{
    Vec2D<T> res;

    res.x = X1.x-X2.x;
    res.y = X1.y-X2.y;

    return res;
}

template<typename T>
Vec2D<T> operator*(double a, Vec2D<T> X)
{
    return Vec2D<T>(a*X.x,a*X.y);
}

template<typename T>
Vec2D<T> operator/(Vec2D<T> X,T a)
{
    return Vec2D<T>(X.x/a,X.y/a);
}

template<typename T>
bool operator==(Vec2D<T> X1,Vec2D<T> X2)
{
    if(X1.x==X2.x && X1.y==X2.y)
        return true;
    
    return false;
}

template<typename T>
Vec2D<T> ProjeteOrthogonal(Vec2D<T> pos, Vec2D<T> A, Vec2D<T> B)
{
    Vec2D<T> AB = B - A;
    Vec2D<T> OA = A;

    T d_ab = norm(AB);

    Vec2D<T> t = AB/d_ab;

    Vec2D<T> OH = OA + dot(pos - A,t)*t;

    Vec2D<T> BH = OH - B;

    Vec2D<T> AH = OH -A;

    if(dot(BH,AH)<0)
        return OH;
    
    return pos;

}
