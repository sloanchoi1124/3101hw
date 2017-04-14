#include <vector>

#ifndef IMAGE_H
#define IMAGE_H

#endif
class CameraImage: public Image {
    public:
        CameraImage();
        CameraImage(int x, int y);
        CameraImage(std::vector<int> &copy_from, int x, int y);
        void populate_vector();
        void print_vector();
        void average_vector();
        void invert_vector();
        int *index_vector(int x_val, int y_val);
        void replace_in_vector(int *start, char color, int value);
        void flip_vector();


};
