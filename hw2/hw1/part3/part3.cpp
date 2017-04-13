#include <iostream>
#include "part3.h"

int *index_vector(std::vector<int> &v, int x_dim, int y_dim, int x_val, int y_val){
    return &(v[y_val*x_dim*3 + x_val*3]);
}

void replace_in_vector(std::vector<int> &v, int x_dim, int y_dim, int *start, char color, int value){
    switch(color){
        case 'r': 
            *start = value;
            break;
        case 'g':
            *(start + 1) = value;
            break;
        case 'b':
            *(start + 2) = value;
            break;
    }
}

void flip_vector(std::vector<int> &v, int x, int y){
    int *pixel;
    int *flip_pixel;
    int tmp = 0;

    for(int j = 0; j < y; ++j){
        for(int i = 0; i < x/2; ++i){
            pixel = index_vector(v, x, y, i, j);
            flip_pixel = index_vector(v, x, y, x-i-1, j);
            for(int k=0; k<3; ++k){
                tmp = *(pixel + k);
                *(pixel + k) = *(flip_pixel + k);
                *(flip_pixel + k) = tmp;
            }
        }
    }
}
