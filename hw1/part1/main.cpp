#include <iostream>
#include <string>
#include "part1.h"
using namespace std;

int main(int argc, char *argv[])
{
    int x, y;
    if (argc != 3)
        cout << "Usage: " << argv[0] << " <x> <y>\n";
    else {
        x = stoi(argv[1], nullptr, 10);
        y = stoi(argv[2], nullptr, 10);

        int n = x * y * 3;
        int data[n];
        populate_vector(data, x, y);

        int i;
        for (i = 0; i < 3 * x * y; i++)
            cout << data[i] << " ";

        cout << endl;
    }
    return 0;

}
