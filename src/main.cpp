#include"Simulation.hpp"


int main(int argc,char** argv)
{
    
    Simulation Simu(1080,720,"Modèlisation de mouvements de foule");
    
    Simu.Mainloop();

    return 0;

}