#include <iostream>
#include "include/hw2.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char*argv[]) {
    int p = 0;
    cout << "persistent? type 1 for yes" << endl;
    cin >> p;

    CameraImage c_img;
    PersistentCameraImage p_img;

    if (p) {
        //TODO: ask for input/output name
        string infilename, outfilename;
        cout << "input file name" << endl;
        cin >> infilename;
        cout << "output file name" << endl;
        cin >> outfilename;
        p_img = PersistentCameraImage(infilename, outfilename);
        p_img.print_vector();
    } else {
        int x, y;
        cout << "please enter <x>" << endl;
        cin >> x;
        cout << "please enter <y>" << endl;
        cin >> y;
        c_img = CameraImage(x, y);
        c_img.populate_vector();
    }

    string usr_input;
    while (1) {
        cout << "command" << endl;
        getline(cin, usr_input);
        //cin >> usr_input;
        if (usr_input[0] == 'q')
            break;
        if (usr_input[0] == 'i'){
            p? p_img.invert_vector(): c_img.invert_vector();
        } else if (usr_input[0] == 'a') {
            p? p_img.average_vector() : c_img.average_vector();
        } else if (usr_input[0] == 'f') {
            p? p_img.flip_vector() : c_img.flip_vector();
        } else if (usr_input[0] == 'p') {
            p? p_img.print_vector() : c_img.print_vector();
        } else if (usr_input[0] == 'r') {
            istringstream iss(usr_input);
            string s;
            int i, x_, y_, val;
            char c;
            i = 0;
            while (getline(iss, s, ' ')) {
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
            if (!p) {
                int *pos = c_img.index_vector(x_, y_);
                c_img.replace_in_vector(pos, c, val);
            } else {
                int *pos = p_img.index_vector(x_, y_);
                p_img.replace_in_vector(pos, c, val);
            } 
        } else {
            //cout << "wrong command! type q to quit!" << endl;
            continue;
        }
        p ? p_img.print_vector() : c_img.print_vector();
    }
    return 0;
}
