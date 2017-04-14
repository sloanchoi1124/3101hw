#include <iostream>
#include "src/image.h"
#include "src/camera_image.h"
#include "src/persistent_camera_image.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

int main(void) {
    CameraImage tmp = CameraImage(3, 5);
    tmp.print_vector();
    tmp.average_vector();
    tmp.print_vector();
    return 0;
}
