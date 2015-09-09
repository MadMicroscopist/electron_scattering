#include <random>
#include <iostream>
#include <ctime>
 
int main()
{
    std::random_device rd;
    std::mt19937_64 gen(time(NULL));
    for(int n=0; n<10; ++n) {
        std::cout << std::generate_canonical<double, 10>(gen) << ' ';
    }
}