#include <vector>
#include "../hw1/include/hw1.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

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
        CameraImage() : Image() {}

        CameraImage(int x, int y) : Image(x, y){}

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

class PersistentCameraImage : public CameraImage {
    public:
        PersistentCameraImage() : CameraImage() {}
        PersistentCameraImage(int x, int y) : CameraImage(x, y) {}
        PersistentCameraImage(std::vector<int> &copy_from, int x, int y): CameraImage(copy_from, x, y) {}

        //new constructor
        PersistentCameraImage(const std::string& infilename, const std::string& outfilename) {
            std::ifstream infile(infilename);    
            std::string line;
            std::string all_num_str = "";
            int line_no = 0;
            int total = 0;

            while (std::getline(infile, line)) {
                line_no ++;
                all_num_str += line;
                all_num_str += " ";
            }
            this->y = line_no;
            
            char tmp[all_num_str.size() + 1];
            std::strcpy(tmp, all_num_str.c_str());
            char *token = std::strtok(tmp, " ");
            while (token != NULL){
                //std::cout << std::atoi(token) << std::endl;
                this->v.push_back(std::atoi(token));
                total ++;
                token = std::strtok(NULL, " ");
            }
            //this->v.pop_back();
            this->x = (total) / (3 * y);
           
            this->output_file = true;
            this->output_filename = outfilename;


        }

        void print_vector() {
            if (this->output_file) {
                std::cout << "redirect to output file!" << std::endl;
                std::cout << this->output_filename << std::endl;

                std::ofstream out(this->output_filename);
                std::streambuf *coutbuf = std::cout.rdbuf();
                std::cout.rdbuf(out.rdbuf());

                ::print_vector(this->v, this->x, this->y);
                std::cout.rdbuf(coutbuf);
            } else {
                ::print_vector(this->v, this->x, this->y);
            }
            
        }
    
    private:
        std::string output_filename;
        bool output_file = false;
};

int main(void){
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

    PersistentCameraImage tmp = PersistentCameraImage("input.txt", "result1.txt");
    tmp.print_vector();
    return 0;
}
