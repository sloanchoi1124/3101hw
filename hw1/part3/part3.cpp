#include <iostream>
using namespace std;

//x_ and y_ are user input
int* index_vector(int *data, int x, int y, int x_, int y_)
{
    int index;
    index = y_ * (3 * x) + x_ * 3;
    return (data + index); 
}

void replace_in_vector(int *data, int x, int y, char c, int val, int x_, int y_)
{
    //on success, return 0; 
    //replace the r/g/b of pixel(x, y) with val
    int tmp;
    int *index;
    
    if (c == 'r')
        tmp = 0;
    else if (c == 'g')
        tmp = 1;
    else if (c == 'b')
        tmp = 2;
    else
        return;
    index = index_vector(data, x, y, x_, y_);
    *(index + tmp) = val;
}

void flip_vector(int *data, int x, int y)
{
    //flip the vector
    int i, tmp, row;
    int *start;

    for (row = 0; row < y; row ++) {
        start = data + row * (3 * x);
        for (i = 0; i < 3 * x / 2; i++) {
            cout << "swapped " << i << "and " << (3 * x - i) << endl;
            tmp = *(start + i);
            *(start + i) = *(start + 3 * x - 1 - i);
            *(start + 3 * x -1- i) = tmp;
        }
    }


}
/*
void print_vector(int *data, int x, int y) {
    int n, i, row;
    n = 3 * x * y;
    int *start;
    for (row = 0; row < y; row++) {
        start = data + row * (3 * x);
        for (i = 0; i < 3 * x; i+= 3) {
            cout << *(start + i) << " " << *(start + i + 1) << " " << *(start + i + 2) << "\t";
        }
        cout << endl;
    }
}
*/
/*
int main()
{
    int data[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int x = 2;
    int y = 2;
    print_vector(data, x, y);
    flip_vector(data, x, y);
    print_vector(data, x, y);
    replace_in_vector(data, x, y, 'g', 88, 0, 1);
    print_vector(data, x, y);
}
*/
