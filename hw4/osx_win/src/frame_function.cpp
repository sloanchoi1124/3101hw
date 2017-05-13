#include "frame_function.h"
#include "hw1.h"
#include "hw2.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

#define RGB_THRESHOLD_POSITIVE 10
#define RGB_THRESHOLD_NEGATIVE -20
#define DELTA_X_MIN 5
#define DELTA_X_MAX 200

/*global variable to keep the previous x, y coordinate of the center of mass*/
int avg_center_x = -1;
int avg_center_y = -1;

void frame_function(Context &context, 
        vector<uint8_t> &buffer_prev, 
        vector<uint8_t> &buffer_current, 
        vector<uint8_t> &buffer_trajectory){
    /*allocate an array to only store the average RGB of the input image*/
    uint8_t *buffer_current_data = (uint8_t *)malloc(context.width * context.height);
    if (buffer_current_data == NULL)
        return;

    /*calculate the average RGB of the current frame*/
    for (int i = 0 ; i < buffer_current.size(); i += 3)
        buffer_current_data[i/3] = (buffer_current[i] + buffer_current[i + 1] + buffer_current[i + 2])/3;
    /*average the RGB of the previous frame*/
    hw::average_vector(buffer_prev);

    bool dark_to_light, light_to_dark;
    int motion_start, motion_end;
    int k_sum_x = 0;
    int k_sum_y = 0;
    int k_count = 0;

    /*for each row of pixels, identify the boudary of movement*/
    for (int row = 0; row < context.height; ++row) {
        /*reset flags*/
        motion_start = -1;
        motion_end = -1;
        dark_to_light = false;
        light_to_dark = false;
        
        for (int x = 0; x < context.width * 3; x += 3) {
            int i = row * context.width * 3 + x;
            int diff = (int)buffer_current_data[i/3] - (int)buffer_prev[i];
            
            if (motion_start > 0) {
                if ((dark_to_light && diff > RGB_THRESHOLD_POSITIVE) 
                        || (light_to_dark && diff < RGB_THRESHOLD_NEGATIVE)) {
                    /**/
                    motion_end = i;
                    /*ignore cases where the range of motion in the line is too small or too big*/
                    if (motion_end - motion_start > DELTA_X_MIN 
                            && motion_end - motion_start < DELTA_X_MAX) {
                        /* - Fill in the objects with the color in obj_identity_color 
                         *   between motion_start and motion_end
                         *
                         * - k_sum_x and k_sum_y are used to calculate the x, y coordinate of 
                         *   the center of mass of the detected object*/
                        k_sum_x += (motion_start % (context.width * 3) + motion_end % (context.width * 3)) / 2;
                        k_sum_y += row;
                        k_count ++;
                        for (int k = motion_start; k <= motion_end; k +=3) {
                            switch(context.obj_identify_color) {
                                case 0:
                                    buffer_current[k] = 0;
                                    buffer_current[k + 1] = 0;
                                    buffer_current[k + 2] = 255;
                                    break;
                                case 1:
                                    buffer_current[k] = 0;
                                    buffer_current[k + 1] = 255;
                                    buffer_current[k + 2] = 0;
                                    break;
                                case 2:
                                    buffer_current[k] = 255;
                                    buffer_current[k + 1] = 0;
                                    buffer_current[k + 2] = 0;
                                    break;
                                case 3:
                                    buffer_current[k] = 0;
                                    buffer_current[k + 1] = 0;
                                    buffer_current[k + 2] = 0;
                                    break;
                                case 4:
                                    buffer_current[k] = 255;
                                    buffer_current[k + 1] = 255;
                                    buffer_current[k + 2] = 255;
                                    break;       
                            }
                        }
                    }
                    /*reset flags*/
                    motion_start = -1;
                    motion_end = -1;
                    light_to_dark = false;
                    dark_to_light = false;
                }
                continue;
            }
            /*detect the start of movement*/
	    if (diff < RGB_THRESHOLD_NEGATIVE) {
                dark_to_light = true;
                motion_start = i;
	    } else if (diff > RGB_THRESHOLD_POSITIVE) {
                light_to_dark = true;
                motion_start = i;
            }
        }
    }
    /* Plot trajectory line by plotting the center of the detected object;
     * Mark center of mass of mass with white in buffer_trajectory;
     * Since motion detection might not be very accurate, 
     * x, y coordinates of the center of mass is smoothed with the previous coordinates;
     * The smoothing ratio is determined based on experiments.
     * */
    if (k_count > 0){
        /*Smooth the x, y coordinate of the center of mass*/
        avg_center_x = (k_sum_x / k_count * 0.5 + avg_center_x * 0.5);
        avg_center_y = (k_sum_y / k_count * 0.3 + avg_center_y * 0.7);
        
        /*round center to 3k*/
        int center = (avg_center_y * context.width * 3 + avg_center_x) / 3 * 3;
        
        /*mark center of mass in trajectory buffer*/
        buffer_trajectory[center] = 255;
        buffer_trajectory[center + 1] = 255;
        buffer_trajectory[center + 2] = 255;    
    }
    free(buffer_current_data);
}

