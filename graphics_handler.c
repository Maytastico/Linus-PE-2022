//
// Created by maylis on 16.03.23.
//

#include "graphics_handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void setPixel(int i_x, int i_y, int io_pBuffer[SIZE_X][SIZE_Y]){
    assert(i_x <= SIZE_X);
    assert(i_y <= SIZE_Y);
    io_pBuffer[i_x][i_y] = 1;
}

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

void printBufferOnConsole(int io_pBuffer[SIZE_X][SIZE_Y]){
    for (int i = 0; i < SIZE_X; ++i) {
        for (int j = 0; j < SIZE_Y; ++j) {
            switch (io_pBuffer[i][j]) {
                case BLANK:
                    printf(" ");
                    break;
                case BLACK:
                    printf("1");
                    break;
            }
        }
        printf("\n");
    }
}

int addition(int a, int b) {
    return a + b;
}