#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "graphics_handler.h"


int main(int argc, char **argv) {
    int frameBuffer[SIZE_X][SIZE_Y] = {0};

    setPixel(5, 3,  &frameBuffer[0]);

    printBufferOnConsole(frameBuffer);
    return 0;
}

