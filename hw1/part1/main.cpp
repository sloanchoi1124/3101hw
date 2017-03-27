#include <iostream>
#include <string>
#include "part1.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
        cout << "Usage: " << argv[0] << " <x> <y>\n";
    else {
        vector<int> vec;
        int i, x, y, tmp;
        vector<int>::iterator v;

        x = stoi(argv[1], nullptr, 10);
        y = stoi(argv[2], nullptr, 10);
        
        populate_vector(&vec, x, y);
        
        cout << "extended vector size= " << vec.size() << endl;

    }
    return 0;

}
