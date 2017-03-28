#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void populate_vector(int *data, int x, int y)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 3 * x * y; i++)
        *(data + i) = rand() % 256;
}
