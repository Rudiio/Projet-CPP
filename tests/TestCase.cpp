// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <string>
#include<iomanip>

/************************* INCLUDES ****************************/

#include"../src/Espace.hpp"
#include"../src/FastMarching.hpp"
#include"../src/GraphicWindow.hpp"
#include"../src/Individu.hpp"
#include"../src/IndividuDisque.hpp"
#include"../src/ModeleFoule.hpp"
#include"../src/PointMeca.hpp"
#include"../src/Simulation.hpp"
#include"../src/Vec2D.hpp"
#include"../src/parametres.hpp"

/***************************************************************/

TEST_CASE("1: Vec2D")
{
  Vec2D<int> a(10,30);
  REQUIRE((a.x==10 && a.y==30));
  
  Vec2D<int> b(5,1);
  a = a+b;
  REQUIRE((a.x==15 && a.y==31));

  a = 3*a;
  REQUIRE((a.x==45 && a.y==93));
  
}

TEST_CASE("2: Individu Disque")
{
  IndividuDisque pieton(20,45,0.5,70);
  std::stringstream xx;
  xx << std::fixed << std::setprecision(1) << pieton.get_pos().x;
  std::string x = xx.str();

  REQUIRE(x == "20.0");
  
  std::stringstream yy;
  yy << std::fixed << std::setprecision(1) << pieton.get_pos().y;
  std::string y = yy.str();
  REQUIRE(y == "45.0");

  std::stringstream rr;
  rr << std::fixed << std::setprecision(1) << pieton.get_rayon();
  std::string r = rr.str();
  REQUIRE(r == "0.5");
}

TEST_CASE("3: Espace ")
{
  Espace espace(Nx,Ny);
  REQUIRE(espace.get_map()!=NULL);
  
  size_t val = espace(10,10);
  size_t n = espace.get_n();
  size_t m = espace.get_m();
  REQUIRE(val==espace.get_map()[10*m + 10]);

  espace(0,3) = 99;
  REQUIRE(espace.get_map()[3]==99);

}

TEST_CASE("4: ModeleFoule")
{
  Espace espace(Nx,Ny);
  size_t n = espace.get_n();
  size_t m = espace.get_m();

  ModeleFoule foule(100,n,m);
  foule.InitFoule(espace);

  REQUIRE(foule.get_foule().size()==100);
  REQUIRE(foule.get_evacues()==0);

}

TEST_CASE("5: FastMarching")
{
  Espace espace(Nx,Ny);
  size_t n = espace.get_n();
  size_t m = espace.get_m();

  FastMarching FM(&espace,pas_espace);
  REQUIRE(FM.get_dist()!= NULL);
  REQUIRE(FM.get_fini()!=NULL);

  FM.InitFM(10,10,1);
  REQUIRE(FM.get_L()[0]==Vec2D<size_t>(10,10));
  REQUIRE(FM.GetPosEspace(10,10)==0);

}
