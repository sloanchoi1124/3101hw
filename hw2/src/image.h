#include <vector>

class Image {
    public:
        Image();
        Image(int x, int y);
        Image(std::vector<int> &copy_from, int x, int y);

        virtual void populate_vector() = 0;
        virtual void print_vector() = 0;
        virtual void average_vector() = 0;
        virtual void invert_vector() = 0;
        virtual int* index_vector(int x_val, int y_val) = 0;
        virtual void replace_in_vector(int *start, char color, int value) = 0;
        virtual void flip_vector() = 0;

    protected:
        std::vector<int> v;
        int x;
        int y;
 
};
