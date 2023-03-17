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
    if(i_end_x < i_start_x){
        int temp_end_x = i_end_x;
        int temp_end_y = i_end_x;
        i_end_x = i_start_x;
        i_end_x = i_start_y;
        i_start_x = temp_end_x;
        i_start_y = temp_end_y;
    }
}

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

int addition(int a, int b) {
    return a + b;
}