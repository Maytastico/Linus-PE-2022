//
// Created by maylis on 16.03.23.
//

#ifndef LINUS_PE_2022_GRAPHICS_HANDLER_H
#define LINUS_PE_2022_GRAPHICS_HANDLER_H

/**
 * Defines the resolution of the picture
 */
#define SIZE_X 50
#define SIZE_Y 50

/**
 * Defines the color of the drawn pixel
 */
#define BLANK 0
#define BLACK 1

int addition(int, int);

void setPixel(int i_x, int i_y, int io_pBuffer[SIZE_X][SIZE_Y]);

void drawLine(int i_start_x, int i_start_y, int i_end_x, int i_end_y, int io_pBuffer[SIZE_X][SIZE_Y]);


void printBufferOnConsole(int io_pBuffer[SIZE_X][SIZE_Y]);


#endif //LINUS_PE_2022_GRAPHICS_HANDLER_H
