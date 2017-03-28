#include <iostream>
#include "part2.h"
using namespace std;

int main(int argc, char *argv[])
{
    int data[12] = {1, 2, 3, 1, 2, 3, 4, 5, 6, 4, 5, 6};
    int x = 2;
    int y = 2;

    cout << "original vector" << endl;
    print_vector(data, x, y);
    
    average_vector(data, x, y);
    cout << "after average_vector" << endl;
    print_vector(data, x, y);

    invert_vector(data, x, y);
    cout << "after invert_vector" << endl;
    print_vector(data, x, y);

    return 0;
}
