#ifndef __FRAME_FUNCTION__
#define __FRAME_FUNCTION__

#include "context.h"
#include <stdint.h>
#include <vector>

using namespace std;

void frame_function(Context &context, vector<uint8_t> &buffer_prev, vector<uint8_t> &buffer_current, vector<uint8_t> &buffer_current_protected);

#endif