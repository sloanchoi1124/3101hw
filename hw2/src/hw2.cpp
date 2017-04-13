#include <vector>
#include "../hw1/include/hw1.h"
#include <iostream>

class Image {
    public:
        Image() {
            x = 0;
            y = 0;
        }

        Image(int x, int y) {
            int i;
            this->x = x;
            this->y = y;
            for (i = 0; i < x*y*3; i++)
                this->v.push_back(0);
        }

        Image(std::vector<int> &copy_from, int x, int y) {
            this->x = x;
            this->y = y;
            this->v = copy_from;
        }

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


class CameraImage: public Image {
    public:
        CameraImage() : Image() {
        }

        CameraImage(int x, int y) : Image(x, y){
        }

        CameraImage(std::vector<int> &copy_from, int x, int y) : Image(copy_from, x, y) {
        
        }

        void populate_vector() {
            ::populate_vector(this->v);
        }

        void print_vector() {
            ::print_vector(this->v, this->x, this->y);
        }

        void average_vector() {
            ::average_vector(this->v);
        }

        void invert_vector() {
            ::invert_vector(this->v);
        }

        int* index_vector(int x_val, int y_val) {
            return ::index_vector(this->v, this->x, this->y, x_val, y_val);
        }

        void replace_in_vector(int *start, char color, int value) {
            ::replace_in_vector(this->v, this->x, this->y, start, color, value);
        }
        
        void flip_vector() {
            ::flip_vector(this->v, this->x, this->y);
        }
        
};



int main(void){
    //TODO: create a CameraImage class and try some member functions;
//    CameraImage myCameraImage = CameraImage();
    CameraImage myCameraImage = CameraImage(3, 5);
    myCameraImage.print_vector();
    myCameraImage.populate_vector();
    myCameraImage.print_vector();
    
    myCameraImage.average_vector();
    myCameraImage.print_vector();

    myCameraImage.invert_vector();
    myCameraImage.print_vector();

    myCameraImage.flip_vector();
    myCameraImage.print_vector();

    int *position = myCameraImage.index_vector(1, 1);
    myCameraImage.replace_in_vector(position, 'r', 0);
    myCameraImage.print_vector();

    return 0;
}
