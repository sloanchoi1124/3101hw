#ifndef __PART3__
#define __PART3__

#include <vector>

int *index_vector(std::vector<int> &v, int x_dim, int y_dim, int x_val, int y_val);
void replace_in_vector(std::vector<int> &v, int x_dim, int y_dim, int *start, char color, int value);
void flip_vector(std::vector<int> &v, int x, int y);

#endif