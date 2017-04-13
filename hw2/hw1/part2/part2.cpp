#include <iostream>
#include "part2.h"

void print_vector(std::vector<int> &v, int x, int y){
    int x_index = 0;
    for(int i: v){
        if(x_index == x*3){
            x_index = 0;
            std::cout << std::endl;
        }

        std::cout << i << " ";
        x_index++;

        if(x_index%3 ==0){
            std::cout << "\t";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void average_vector(std::vector<int> &v){
    int x_index = 0;
    int average = 0;

    for(std::vector<int>::iterator i = v.begin(); i<v.end(); ++i){
        x_index++;

        if(x_index==3){
            average = (*(i-2) + *(i-1) + *i)/3;
            *(i-2) = average;
            *(i-1) = average;
            *i = average;
            x_index = 0;
        }
    }
}

void invert_vector(std::vector<int> &v){
    for(std::vector<int>::iterator i = v.begin(); i<v.end(); ++i){
        *i = 255 - *i;
    }
}
