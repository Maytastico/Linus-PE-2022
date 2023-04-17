
#include "graphics_handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


Vector_2D addVector(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    result.x = i_vec0.x + i_vec1.x;
    result.y = i_vec0.y + i_vec1.y;
    return result;
}

Vector_2D subtractVector(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    result.x = i_vec0.x - i_vec1.x;
    result.y = i_vec0.y - i_vec1.y;
    return result;
}

Vector_2D multiplyVector(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    result.x = i_vec0.x * i_vec1.x;
    result.y = i_vec0.y * i_vec1.y;
    return result;
}

Vector_2D divideVector(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    //assert(i_vec1.x==0);
    //assert(i_vec1.y==0);
    result.x = i_vec0.x / i_vec1.x;
    result.y = i_vec0.y / i_vec1.y;
    return result;
}

Vector_2D middleVector(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    Vector_2D factor = {2,2};
    result = addVector(i_vec0, i_vec1);
    result = divideVector(result, factor);
    return result;
}

/**
 * Draw a point inside a given matrix
 * @param i_x
 * @param i_y
 * @param io_pBuffer
 */
void setPixel(int i_x, int i_y, int io_pBuffer[SIZE_X][SIZE_Y]){
    assert(i_x <= SIZE_X);
    assert(i_y <= SIZE_Y);
    io_pBuffer[i_x][i_y] = 1;
}

/**
 * Takes an array and draws a line with the bresenham algorithm
 * @param i_start_x
 * @param i_start_y
 * @param i_end_x
 * @param i_end_y
 * @param io_pBuffer
 */
void drawLine(int i_start_x, int i_start_y, int i_end_x, int i_end_y, int io_pBuffer[SIZE_X][SIZE_Y]){
    int dx = abs(i_end_x - i_start_x);
    int dy = abs(i_start_y - i_end_y);
    int sx = i_start_x < i_end_x ? 1 : -1;
    int sy = i_start_y < i_end_y ? 1 : -1;
    int err = dx - dy;

    while (i_start_x != i_end_x || i_start_y != i_end_y) {
        setPixel(i_start_x, i_start_y, io_pBuffer);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            i_start_x += sx;
        }
        if (e2 < dx) {
            err += dx;
            i_start_y += sy;
        }
    }
    setPixel(i_end_x, i_end_y, io_pBuffer);
}

/**
 * Takes four point and draws lines vom point to point
 * @param i_X0
 * @param i_Y0
 * @param i_X1
 * @param i_Y1
 * @param i_X2
 * @param i_Y2
 * @param i_X3
 * @param i_Y3
 * @param io_pBuffer
 */
void drawRect(int i_X0, int i_Y0, int i_X1, int i_Y1, int i_X2, int i_Y2, int i_X3, int i_Y3, int io_pBuffer[SIZE_X][SIZE_Y]){

    drawLine(i_X0,i_Y0,i_X1,i_Y1,io_pBuffer);
    drawLine(i_X1,i_Y1,i_X2,i_Y2,io_pBuffer);
    drawLine(i_X2,i_Y2,i_X3,i_Y3,io_pBuffer);
    drawLine(i_X3,i_Y3,i_X0,i_Y0,io_pBuffer);
}
/**
 * Prints out and formates a given matrix to the console.
 * @param io_pBuffer
 */
void printBufferOnConsole(int io_pBuffer[SIZE_X][SIZE_Y]){
    for (int i = 0; i < SIZE_X; ++i) {
        for (int j = 0; j < SIZE_Y; ++j) {
            switch (io_pBuffer[i][j]) {
                case BLANK:
                    printf("0");
                    break;
                case BLACK:
                    printf("1");
                    break;
            }
        }
        printf("\n");
    }
}
