#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../part1/part1.h"
#include "../part2/part2.h"
#include "part3.h"
using namespace std;

int main(int argc, char *argv[])
{
    int x, y;

    string usr_input;
    if (argc != 3){
        cout << "Usage: ./part3 <x> <y>" << endl;
        return 0;
    }
    x = stoi(argv[1], nullptr, 10);
    y = stoi(argv[2], nullptr, 10);

    int data[3 * x * y];
    populate_vector(data, x, y);
    print_vector(data, x, y);

    int tmp;

    while (1) {
        getline(cin, usr_input);
        if (usr_input[0] == 'q')
            break;

        if (usr_input[0] == 'i') {
            invert_vector(data, x, y);
        } else if (usr_input[0] == 'a') {
            cout << "average"<<endl;
            average_vector(data, x, y);
        } else if (usr_input[0] == 'f') {
            flip_vector(data, x, y);
        } else if (usr_input[0] == 'p') {
            print_vector(data, x, y);
        } else if (usr_input[0] == 'r') {
            istringstream iss(usr_input);
            string s;
            int i, x_, y_, val;
            char c;
            i = 0;
            while (getline(iss, s, ' ')){
                if (i == 1)
                    x_ = stoi(s.c_str(), nullptr, 10);
                else if (i == 2)
                    y_ = stoi(s.c_str(), nullptr, 10);
                else if (i == 3)
                    c = s.c_str()[0];
                else if (i == 4)
                    val = stoi(s.c_str(), nullptr, 10);
                i++;
            }
            replace_in_vector(data, x, y, c, val, x_, y_);

        }
        else {
            cout << "wrong command !" << endl;
            break;
        }
        print_vector(data, x, y);

    }

    return 0;
}
