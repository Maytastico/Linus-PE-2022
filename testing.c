#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "include/graphics_handler.h"

void test_line();
void test_pixel();
void testVectors();
void testRectangle();

int main() {
    test_line();
    test_pixel();
    testVectors();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void test_line(){
    int frame[SIZE_X][SIZE_Y];
    Vector_2D point_A = {0,0};
    Vector_2D point_B = {5,5};

    drawLine(point_A,point_B,frame);
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
    Vector_2D point = {2,5};
    setPixel(point,frame);
    assert(frame[2][5]==1);
    assert(frame[2][6]==0);
    assert(frame[2][4]==0);
    assert(frame[1][5]==0);
    assert(frame[3][5]==0);
}

void testVectors(){
    Vector_2D result = {500,340};
    Vector_2D test_vector = {20,30};
    assert(result.x==500);
    assert(result.y==340);
    result = addVector(result, test_vector);
    assert(result.x==520);
    assert(result.y==370);
    result = multiplyVector(result, test_vector);
    assert(result.x==10400);
    assert(result.y==11100);
    result = divideVector(result, test_vector);
    assert(result.x==520);
    assert(result.y==370);
    result = middleVector(result, test_vector);
    assert(result.x==270);
    assert(result.y==200);
    result = subtractVector(result, test_vector);
    assert(result.x==250);
    assert(result.y==170);
}
