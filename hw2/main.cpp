#include <vector>
#include <iostream>
#include "hw1/include/hw1.h"
int main() {
    int x = 5;
    int y = 9;
    std::vector<int> v(x*y*3);
    populate_vector(v);

    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}
