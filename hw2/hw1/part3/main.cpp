#include <vector>
#include <iostream>
#include "part1.h"
#include "part2.h"
#include "part3.h"

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
    

    for(int i = 0; i < x; ++i){
        for(int j=0; j < y; ++j){
            replace_in_vector(v, x, y, index_vector(v, x, y, i, j), 'b', 255);
        }
    }
    print_vector(v, x, y);

    flip_vector(v, x, y);
    print_vector(v, x, y);

}