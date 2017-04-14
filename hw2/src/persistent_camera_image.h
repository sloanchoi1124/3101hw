#include <vector>
#include <string>
#ifndef CAMERA_IMAGE_H
#define CAMERA_IMAGE_H
#endif

class PersistentCameraImage: public CameraImage {
    public:
        PersistentCameraImage();
        PersistentCameraImage(int x, int y);
        PersistentCameraImage(std::vector<int> &copy_from, int x, int y);
        PersistentCameraImage(const std::string& infilename, 
                const std::string& outfilename);
        void print_vector();
    private:
        std::string output_filename;
        bool output_file = false;
};
