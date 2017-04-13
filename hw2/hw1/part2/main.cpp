#include <vector>
#include <iostream>
#include "part1.h"
#include "part2.h"

int main(){
    int x = 5;
    int y = 9;

    std::vector<int> v(x*y*3);

    populate_vector(v);
    print_vector(v, x, y);

    average_vector(v);
    print_vector(v, x, y);

    invert_vector(v);
    print_vector(v, x, y);
    
}