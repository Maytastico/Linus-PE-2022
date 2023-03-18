#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "include/graphics_handler.h"
#include "include/file_handler.h"


int main(int argc, char **argv) {
    int frameBuffer[SIZE_X][SIZE_Y] = {0};

    if(create_ppm_header("First_Creation.ppm")==EXIT_SUCCESS){
        printf("Creating file successful!");
    }

    drawLine(1,1,1000,500,frameBuffer);

    if(writeBufferToFile("First_Creation.ppm", frameBuffer)==EXIT_SUCCESS){
        printf("Wrote Buffer successfuly");
    }
    printBufferOnConsole(frameBuffer);

    return 0;
}