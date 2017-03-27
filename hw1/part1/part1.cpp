#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void populate_vector(vector<int> *vec, int x, int y)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 3 * x * y; i++)
        (*vec).push_back(rand() % 256);
}
