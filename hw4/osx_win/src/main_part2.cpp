#include "ps3eye.h"
#include "context.h"
#include "frame_function.h"
#include <iostream>
#include <string.h>

int main(int argc, char *argv[]){
    Context ctx;
    /*parse color from command line*/
    if (argc > 1) {
        if (!strcmp(argv[1], "RED")) {
            ctx.obj_identify_color = 0;
        } else if (!strcmp(argv[1], "GREEN")) {
            ctx.obj_identify_color = 1;
        } else if (!strcmp(argv[1], "BLUE")) {
            ctx.obj_identify_color = 2;
        } else if (!strcmp(argv[1], "BLACK")) {
            ctx.obj_identify_color = 3;
        } else if (!strcmp(argv[1], "WHITE")) {
            ctx.obj_identify_color = 4;
        }
    }
    run_camera(ctx);
}
