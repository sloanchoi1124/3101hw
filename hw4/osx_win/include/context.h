#ifndef __CONTEXT__
#define __CONTEXT__

class Context{
    //Maintain state if needed

public:
    int height = 480; // for example
    int width = 640; // for example

    bool use_average = true;
    bool use_invert = true;
    bool use_flip = true; 

    int obj_identify_color = 0;

};

#endif
