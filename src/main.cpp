#include"Simulation.hpp"
#include"parametres.hpp"
#include<cstdlib>

int main(int argc,char** argv)
{
    Simulation Simu(WIDTH,HEIGTH,"Modèlisation de mouvements de foule");
    
    Simu.Mainloop();
    
    return 0;

}