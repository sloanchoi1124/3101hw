#include <iostream>
#include <string>
using namespace std;

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

void average_vector(int *data, int x, int y) {
    int n, i, avg;

    n = 3 * x * y;
    for (i = 0; i < n; i += 3) {
        avg = (*(data + i) + *(data + i + 1) + *(data + i + 2)) / 3;
        *(data + i) = avg;
        *(data + i + 1) = avg;
        *(data + i + 2) = avg;
    }
}

void invert_vector(int *data, int x, int y) {
    int n, i;
    n = 3 * x * y;
    for (i = 0; i < n; i++)
        *(data + i) = 255 - *(data + i);
}
/*
int main(int argc, char *argv[])
{
    int data[6] = {1, 2, 3, 4, 5, 6};
    int x = 1;
    int y = 2;
    print_vector(data, x, y);
    average_vector(data, x, y);
    print_vector(data, x, y);
    
    invert_vector(data, x, y);
    print_vector(data, x, y);
    return 0;
}
*/
