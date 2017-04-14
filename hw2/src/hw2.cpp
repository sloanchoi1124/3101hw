#include <vector>
#include "../hw1/include/hw1.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "image.h"
#include "camera_image.h"
#include "persistent_camera_image.h"

Image::Image() 
{
    x = 0;
    y = 0;
}

Image::Image(int x, int y) 
{
    int i;
    this->x = x;
    this->y = y;
    for (i = 0; i < x*y*3; i++)
        this->v.push_back(0);
}

Image::Image(std::vector<int> &copy_from, int x, int y) 
{
    this->x = x;
    this->y = y;
    this->v = copy_from;
}
CameraImage::CameraImage() : Image() {}

CameraImage::CameraImage(int x, int y) : Image(x, y){}

CameraImage::CameraImage(std::vector<int> &copy_from, int x, int y) : Image(copy_from, x, y) {}

void CameraImage::populate_vector() 
{
    ::populate_vector(this->v);
}

void CameraImage::print_vector() 
{
    ::print_vector(this->v, this->x, this->y);
}

void CameraImage::average_vector() 
{
    ::average_vector(this->v);
}

void CameraImage::invert_vector() 
{
    ::invert_vector(this->v);
}

int* CameraImage::index_vector(int x_val, int y_val) 
{
    return ::index_vector(this->v, this->x, this->y, x_val, y_val);
}

void CameraImage::replace_in_vector(int *start, char color, int value) 
{
    ::replace_in_vector(this->v, this->x, this->y, start, color, value);
}
        
void CameraImage::flip_vector() 
{
    ::flip_vector(this->v, this->x, this->y);
}

PersistentCameraImage::PersistentCameraImage() : CameraImage() {}
PersistentCameraImage::PersistentCameraImage(int x, int y) : CameraImage(x, y) {}
PersistentCameraImage::PersistentCameraImage(std::vector<int> &copy_from, 
        int x, int y): CameraImage(copy_from, x, y) {}

        //new constructor
PersistentCameraImage::PersistentCameraImage(const std::string& infilename, 
        const std::string& outfilename) 
{
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

void PersistentCameraImage::print_vector()
{
    if (this->output_file) {
        std::ofstream out(this->output_filename);
        std::streambuf *coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(out.rdbuf());

        ::print_vector(this->v, this->x, this->y);
        std::cout.rdbuf(coutbuf);
    } else {
        ::print_vector(this->v, this->x, this->y);
    }
}

/*testing code for each class*/
/*
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
*/
