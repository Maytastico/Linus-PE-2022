
#include "graphics_handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * Adds two vectors
 * @param i_vec0
 * @param i_vec1
 * @return
 */
Vector_2D addVectors(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    result.x = i_vec0.x + i_vec1.x;
    result.y = i_vec0.y + i_vec1.y;
    return result;
}

/**
 * Subtracts two vectors
 * @param i_vec0
 * @param i_vec1
 * @return
 */
Vector_2D subtractVectors(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    result.x = i_vec0.x - i_vec1.x;
    result.y = i_vec0.y - i_vec1.y;
    return result;
}

/**
 * Multiplys two vectors
 * @param i_vec0
 * @param i_vec1
 * @return
 */
Vector_2D multiplyVectors(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    result.x = i_vec0.x * i_vec1.x;
    result.y = i_vec0.y * i_vec1.y;
    return result;
}

/**
 * Devides two vectors
 * @param i_vec0
 * @param i_vec1
 * @return
 */
Vector_2D divideVectors(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    //assert(i_vec1.x==0);
    //assert(i_vec1.y==0);
    result.x = i_vec0.x / i_vec1.x;
    result.y = i_vec0.y / i_vec1.y;
    return result;
}

/**
 * Calculates the point that lies at the middle of two vectors
 * @param i_vec0
 * @param i_vec1
 * @return
 */
Vector_2D middleOfVectors(Vector_2D i_vec0, Vector_2D i_vec1){
    Vector_2D result;
    Vector_2D factor = {2,2};
    result = addVectors(i_vec0, i_vec1);
    result = divideVectors(result, factor);
    return result;
}

/**
 * Compares two frames with eachother.
 * Can be used for testing whether on frame has equel content.
 * @param i_array1
 * @param i_array2
 * @param size
 * @return
 */
bool compareFrames(int i_array1[], int i_array2[], int size){
    for (int i = 0; i < size*size; ++i) {
        if(i_array1[i] != i_array2[i]){
            return false;
        }
    }
    return true;
}

/**
 * Draw a point inside a given matrix
 * @param i_x
 * @param i_y
 * @param io_pBuffer
 */
void setPixel(Vector_2D i_point, int io_pBuffer[SIZE_X][SIZE_Y]){
    assert(i_point.x <= SIZE_X);
    assert(i_point.y <= SIZE_Y);
    io_pBuffer[i_point.x][i_point.y] = 1;
}

/**
 * Takes an array and draws a line with the bresenham algorithm
 * @param i_start
 * @param i_end
 * @param io_pBuffer
 */
void drawLine(Vector_2D i_start, Vector_2D i_end, int io_pBuffer[SIZE_X][SIZE_Y]){
    Vector_2D point = {0,0};
    int dx = abs(i_end.x - i_start.x);
    int dy = abs(i_start.y - i_end.y);
    int sx = i_start.x < i_end.x ? 1 : -1;
    int sy = i_start.y < i_end.y ? 1 : -1;
    int err = dx - dy;

    while (i_start.x != i_end.x || i_start.y != i_end.y) {
        point.x = i_start.x;
        point.y = i_start.y;
        //Calculates and draws the point into buffer
        setPixel(point, io_pBuffer);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            i_start.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            i_start.y += sy;
        }
    }
    //Sets the End Point to be drawn
    point.x = i_end.x;
    point.y = i_end.y;
    setPixel(point, io_pBuffer);
}

/**
 * Takes vector structures and draws lines from vector to vector so it resembles a rectangle
 * @param i_A
 * @param i_B
 * @param i_C
 * @param i_D
 * @param io_pBuffer
 */
void drawRect(Vector_2D i_A,Vector_2D i_B,Vector_2D i_C,Vector_2D i_D, int io_pBuffer[SIZE_X][SIZE_Y]){
    drawLine(i_A,i_B, io_pBuffer);
    drawLine(i_B,i_C,io_pBuffer);
    drawLine(i_C, i_D,io_pBuffer);
    drawLine(i_D,i_A,io_pBuffer);
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
