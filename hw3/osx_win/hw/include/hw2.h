#ifndef __HW2__
#define __HW2__

#include "hw1.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Image{
protected:
    int height;
    int width;
    vector<T> local_buffer;

public:
    Image(){}
    Image(int x, int y): height(y), width(x){}
    Image(vector<T> &copy_from, int x, int y)
     : height(y), width(x)
    {
        local_buffer.resize(x*y*3);
        for(uint i=0; i<copy_from.size(); ++i){
            local_buffer[i] = copy_from[i];
        } 
    }
    virtual ~Image(){}

    virtual void populate_image() = 0;
    virtual void print_image() = 0;
    virtual void average_image() = 0;
    virtual void invert_image() = 0;
    virtual T *index_image(int x_val, int y_val) = 0;
    virtual void replace_in_image(T *start, char color, int value) = 0;
    virtual void flip_image() = 0;
    virtual void copy_from(vector<T> &copy_from) = 0;
    //virtual ostream& operator<<(ostream& os, const Image& image)=0;
};

template <class T>
class CameraImage: public Image<T>{
public:
    CameraImage() : Image<T>(){}
    CameraImage(int x, int y) : Image<T>(x,y){}
    CameraImage(vector<T> &copy_from, int x, int y) : Image<T>(copy_from, x,y){}
    
    virtual ~CameraImage(){}

    virtual void populate_image(){
        hw::populate_vector(this->local_buffer);
    }

    virtual void print_image(){
        hw::print_vector(this->local_buffer, this->width, this->height);
    }

    virtual void average_image(){
        hw::average_vector(this->local_buffer);
    }

    virtual void invert_image(){
        hw::invert_vector(this->local_buffer);
    }

    virtual T *index_image(int x_val, int y_val){
        return hw::index_vector(this->local_buffer, this->width, this->height, x_val, y_val);
    }

    virtual void replace_in_image(T *start, char color, int value){
        hw::replace_in_vector(this->local_buffer, this->width, this->height, start, color, value);
    }

    virtual void flip_image(){
        hw::flip_vector(this->local_buffer, this->width, this->height);
    }

    //TODO copy from!
    virtual void copy_from(vector<T> &copy_from) {
        cout << "copy_from gets called" << endl;
        this->local_buffer.resize(this->height * this->width * 3);
        for (uint i = 0; i < copy_from.size(); ++i)
            this->local_buffer[i] = copy_from[i];
        //this->local_buffer = copy_from;
    }

    T average_calculaor() const{
        T result = 0;
        for (T i: this->local_buffer)
            result += i;
        result /= (3 * this->height * this->width);
        return result;
    }

    friend ostream& operator<<(ostream& os, const CameraImage<T>& cameraImage) {
        cout << "hello!" << endl;
        cout << cameraImage.local_buffer.size() << endl;
        int x_index = 0;
        for (T i: cameraImage.local_buffer) {
            if (x_index == cameraImage.width * 3) {
                x_index = 0;
                os << endl;
            }

            os << +i << " ";
            x_index ++;
            if (x_index % 3 == 0)
                os << "\t";
        }
        os << endl;
        return os;
    }

    template <typename U, typename H>
    friend bool operator>(const CameraImage<U>& lhs, const CameraImage<H>& rhs) {
        U i = lhs.average_calculaor();
        H j = rhs.average_calculaor();
        return (float)i > (float)j;
    }

    template<typename U, typename H>
    friend bool operator!=(const CameraImage<U>& lhs, const CameraImage<H>& rhs) {
        if (lhs.height * lhs.width != rhs.height * rhs.width)
            return true;

        int t;
        for (t = 0; t < lhs.local_buffer.size(); ++t) {
            if ((float)lhs.local_buffer[t] != (float)rhs.local_buffer[t])
                return true;
        }
        return false;
    }

    template<typename U, typename H>
    friend bool operator==(const CameraImage<U>& lhs, const CameraImage<H>& rhs) {
        if (lhs.height * lhs.width != rhs.height * rhs.width)
            return false;
        int t;
        for (t = 0; t < lhs.local_buffer.size(); ++t) {
            if ((float)lhs.local_buffer[t] != (float)rhs.local_buffer[t])
                return false;
        }
        return true;
    }


};


#endif
