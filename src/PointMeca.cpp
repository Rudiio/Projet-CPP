#include"PointMeca.hpp"

//-----------------------------------------------------------------------------------

PointMeca::PointMeca(Vec2D<double> a, Vec2D<double> v, Vec2D<double> p, double masse):
    acc(a),
    vit(v),
    pos(p),
    m(masse)
{

}