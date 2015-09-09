//test3Mott.cpp
//test_of_FTI_Mott_io.h & cpp

#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "material.h"
#include "betheMaterial.h"

int main()
{
    std::srand(time(0));
    for(int i = 1; i < 50; i++) std::cout << (double)(rand() % 1000000000)/100000 << std::endl;
return 0;
}
