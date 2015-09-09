//test3Mott.cpp
//test_of_FTI_Mott_io.h & cpp

#include <math.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "material.h"
#include "betheMaterial.h"

int main()
{
    betheMaterial m1;
    double rnd, E_i;
    std::srand(time(0));
    rnd = (double)(rand() % 1000000000)/100000;
    std::cout << "Random value is " << rnd << std::endl;
    std::cout << "Insert E_i" << std::endl;
    std::cin >> E_i;
    double step = m1.calculate_step(E_i);
    std::cout << "Step lenght is " << step*1e7 << " nm" << std::endl;
    std::cout << "Energy loss is " << m1.calculate_E_loss(E_i, step)* 1000 << "eV" <<std::endl;
return 0;
}
