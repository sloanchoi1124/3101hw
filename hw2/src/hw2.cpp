#include <vector>
#include "hw1/include/hw1.h"

class Image {
    public:
        Image() {
            this.x = 0;
            this.y = 0;
        }

        Image(int x, int y) {
            int i;
            this.x = x;
            this.y = y;
            for (i = 0; i < x*y; i++)
                this.v.push_back(0);
        }
        Image(std::vector<int> &copy_from, int x, int y) {
            this.x = x;
            this.y = y;
            this.v = *copy_from;
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
}


class CameraImage: public Image {
    public:
        CameraImage(): base {}
        CameraImage(int x, int y): base(int x, int y) {}
        CameraImage(std::vector<int> &copy_from, int x, int y): base(std::vector<int> &copy_from, int x, int y) {}


        void populate_vector() {
            return populate_vector(&this.v);
        }

        void print_vector() {
            return print_vector(&this.v, this.x, this.y)
        }

        void average_vector() {
            return average_vector(&this.v);
        }

        void invert_vector() {
            return invert_vector(&this.v);
        }

        int* index_vector(int x_val, int y_val) {
            return index_vector(&this.v, this.x, this.y, x_val, y_val);
        }

        void replace_in_vector(int *start, char color, int value) {
            return replace_in_vector(&this.v, this.x, this.y, start, color, value);
        }
        
        void flip_vector() {
            return flip_vector(&this.v, this.x, this.y);
        }
}



int main(void){
    return 0;
}
