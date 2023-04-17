//
// Created by maylis on 16.03.23.
//

#ifndef LINUS_PE_2022_GRAPHICS_HANDLER_H
#define LINUS_PE_2022_GRAPHICS_HANDLER_H

/**
 * Defines the resolution of the picture
 */
#define SIZE_X 1000
#define SIZE_Y 1000

/**
 * Defines the color of the drawn pixel
 */
#define BLANK 0
#define BLACK 1

/**
 * Structure for Vector Calculations
 */
struct Vector_2D{
    int x;
    int y;

};

typedef struct Vector_2D Vector_2D;

Vector_2D middleVector(Vector_2D i_vec0, Vector_2D i_vec1);

Vector_2D divideVector(Vector_2D i_vec0, Vector_2D i_vec1);

Vector_2D multiplyVector(Vector_2D i_vec0, Vector_2D i_vec1);

Vector_2D subtractVector(Vector_2D i_vec0, Vector_2D i_vec1);

Vector_2D addVector(Vector_2D i_vec0, Vector_2D i_vec1);

void setPixel(int i_x, int i_y, int io_pBuffer[SIZE_X][SIZE_Y]);

void drawLine(int i_start_x, int i_start_y, int i_end_x, int i_end_y, int io_pBuffer[SIZE_X][SIZE_Y]);

void drawRect(int i_X0, int i_Y0, int i_X1, int i_Y1, int i_X2, int i_Y2, int i_X3, int i_Y3, int io_pBuffer[SIZE_X][SIZE_Y]);

void printBufferOnConsole(int io_pBuffer[SIZE_X][SIZE_Y]);


#endif //LINUS_PE_2022_GRAPHICS_HANDLER_H
