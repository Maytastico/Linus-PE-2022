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

void setPixel(Vector_2D i_point, int io_pBuffer[SIZE_X][SIZE_Y]);

void drawLine(Vector_2D i_start, Vector_2D i_end, int io_pBuffer[SIZE_X][SIZE_Y]);

void drawRect(Vector_2D i_A,Vector_2D i_B,Vector_2D i_C,Vector_2D i_D, int io_pBuffer[SIZE_X][SIZE_Y]);

void printBufferOnConsole(int io_pBuffer[SIZE_X][SIZE_Y]);


#endif //LINUS_PE_2022_GRAPHICS_HANDLER_H
