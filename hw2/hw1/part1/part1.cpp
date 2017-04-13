#include <stdlib.h>
#include <time.h>
#include "part1.h"

void populate_vector(std::vector<int> &v){
    for(std::vector<int>::iterator i = v.begin(); i<v.end(); ++i){
        *i = rand() % 256;
    }
}
