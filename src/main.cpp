#include"Simulation.hpp"
#include<cstdlib>

int main(int argc,char** argv)
{
    // srand(time(NULL));
    Simulation Simu(1080,720,"Modèlisation de mouvements de foule");
    
    Simu.Mainloop();

    return 0;

}