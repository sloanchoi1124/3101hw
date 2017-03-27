#include <vector>
using namespace std;

void print_vector(vector<int> *vec, int x, int y) {
    int n, i, j;
    n = *vec.size();
    for (i = 0; i < n; i += 3 * x) {
        for (j = 0; j < 3 * x; j += 3) {
            cout << "[";
            cout << *vec[i+j] << " " << *vec[i+j+1] << " " << *vec[i+j+2];
            cout << "] "
        }
        cout << endl;
    }
}

void average_vector(vector<int> *vec) {
    int n, i, avg;

    n = *vec.size();
    for (i = 0; i < size; i += 3) {
        avg = (*vec[i] + *vec[i+1] + *vec[i+2])/3;
        vec[i] = avg;
        vec[i+1] = avg;
        vec[i+2] = avg;
    }
}

void invert_vector(vector<int> *vec) {
    vector<int>::iterator v;
    while (v != *vec.end()) {
        *v = 255 - *v;
    }
}
