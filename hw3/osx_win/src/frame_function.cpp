#include "frame_function.h"
#include "hw1.h"
#include "hw2.h"

void frame_function(Context &context, vector<uint8_t> &buffer){
	//for example: modify the buffer here
	//hw::average_vector(buffer);
	int x = context.width;
	int y = context.height;

	if (context.use_average)
		hw::average_vector(buffer);

	if (context.use_invert)
		hw::invert_vector(buffer);

	if (context.use_flip)
		hw::flip_vector(buffer, x, y);
}
