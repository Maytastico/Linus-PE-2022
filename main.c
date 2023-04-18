#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "include/graphics_handler.h"
#include "include/file_handler.h"

void drawRectangles(int n, Vector_2D i_a, Vector_2D i_b, Vector_2D i_c, Vector_2D i_d, int io_pBuffer[SIZE_X][SIZE_Y]);

int main(int argc, char **argv) {
    int frameBuffer[SIZE_X][SIZE_Y] = {0};

    if(create_ppm_header("First_Creation.ppm")==EXIT_SUCCESS){
        printf("Creating file successful!\n");
    }

    Vector_2D begin_A = {0,0};
    Vector_2D begin_B = {1000,0};
    Vector_2D begin_C = {1000,1000};
    Vector_2D begin_D = {0,1000};

    drawRectangles(30, begin_A, begin_B, begin_C, begin_D, frameBuffer);

    if(writeBufferToFile("First_Creation.ppm", frameBuffer)==EXIT_SUCCESS){
        printf("Wrote Buffer successfully\n");
    }
    //printBufferOnConsole(frameBuffer);

    return 0;
}

/**
 * Draws the rectangles with
 * @param n
 * @param i_a
 * @param i_b
 * @param i_c
 * @param i_d
 * @param io_pBuffer
 */
void drawRectangles(int n, Vector_2D i_a, Vector_2D i_b, Vector_2D i_c, Vector_2D i_d, int io_pBuffer[SIZE_X][SIZE_Y]){
    if (n==0){
        return;
    }else {
        drawRect(i_a, i_b, i_c,i_d, io_pBuffer);
        Vector_2D middle_A = middleVector(i_a, i_b);
        Vector_2D middle_B = middleVector(i_b, i_c);
        Vector_2D middle_C = middleVector(i_c, i_d);
        Vector_2D middle_D = middleVector(i_d, i_a);
        drawRectangles(n-1, middle_A, middle_B, middle_C, middle_D, io_pBuffer);
    }
}
