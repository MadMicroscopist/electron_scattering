//randomMy.hpp
//Function for pseudorandom number generation (0, 1]

#include <random>
#include <ctime>

#ifndef RANDOMMY_HPP
#define RANDOMMY_HPP

double rndMy()
{
	std::random_device rd;
    std::mt19937_64 gen(time(NULL));
	return (1 - std::generate_canonical<double, 10>(gen) );
}

#endif