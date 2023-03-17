#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "graphics_handler.h"

void test_line();
void test_pixel();

int main() {
    assert(addition(2, 3) == 5);
    assert(addition(0, 0) == 0);
    assert(addition(-2, 2) == 0);
    test_line();
    test_pixel();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void test_line(){
    int frame[SIZE_X][SIZE_Y];
    drawLine(0,0,5,5,frame);
    assert(frame[0][0] == 1);
    assert(frame[1][1] == 1);
    assert(frame[2][2] == 1);
    assert(frame[3][3] == 1);
    assert(frame[4][4] == 1);
    assert(frame[5][5] == 1);
    assert(frame[6][6] == 0);
}


void test_pixel(){
    int frame[SIZE_X][SIZE_Y];
    setPixel(2,5,frame);
    assert(frame[2][5]==1);
    assert(frame[2][6]==0);
    assert(frame[2][4]==0);
    assert(frame[1][5]==0);
    assert(frame[3][5]==0);

}