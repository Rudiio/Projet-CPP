// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <string>

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
  
  // Tableau2D<float> tab2 = tab;
  // REQUIRE(tab2 == tab);
  // tab2(1,1) = 1.5;
  // REQUIRE_FALSE(tab2 == tab);
  // std::cout << " ---------- Tableau float ---------------" << std::endl;
  // std::cout << tab2 << std::endl;
}

