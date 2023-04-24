/**
 * Programmentwurf 1. Semester
 * DHBW Heidenheim
 *
 * Name: Maylis Grune
 * Matrikelnummer: 5509286
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "include/graphics_handler.h"
#include "include/file_handler.h"

void drawRectangles(int n, Vector_2D i_a, Vector_2D i_b, Vector_2D i_c, Vector_2D i_d, int io_pBuffer[SIZE_X][SIZE_Y]);

int askForIterations();

int main(int argc, char **argv) {

    int number_of_interations = askForIterations();

    int frameBuffer[SIZE_X][SIZE_Y] = {0};

    if(create_ppm_header("First_Creation.ppm")==EXIT_SUCCESS){
        printf("Creating file successful!\n");


        //Defines the first points of the rectangle
        Vector_2D begin_A = {50,50};
        Vector_2D begin_B = {SIZE_X-50,50};
        Vector_2D begin_C = {SIZE_X-50,SIZE_Y-50};
        Vector_2D begin_D = {50,SIZE_X-50};

        Vector_2D middle_AB = middleOfVectors(begin_A, begin_B);
        Vector_2D middle_BC = middleOfVectors(begin_B, begin_C);
        Vector_2D middle_CD = middleOfVectors(begin_C, begin_D);
        Vector_2D middle_DA = middleOfVectors(begin_D, begin_A);

        drawLine(middle_AB, middle_CD, frameBuffer);
        drawLine(middle_BC, middle_DA, frameBuffer);

        drawRectangles(number_of_interations, begin_A, begin_B, begin_C, begin_D, frameBuffer);

        if(writeBufferToFile("First_Creation.ppm", frameBuffer)==EXIT_SUCCESS){
            printf("Wrote Buffer successfully\n");
        }
    }else{
        printf("Failed creating a new file!");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * Draws the rectangles as the given structure
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
        Vector_2D middle_AB = middleOfVectors(i_a, i_b);
        Vector_2D middle_BC = middleOfVectors(i_b, i_c);
        Vector_2D middle_CD = middleOfVectors(i_c, i_d);
        Vector_2D middle_DA = middleOfVectors(i_d, i_a);
        drawRectangles(n-1, middle_AB, middle_BC, middle_CD, middle_DA, io_pBuffer);
    }
}

/**
 * Asks the users for how many times the algorithm should be executed
 * @return
 */
int askForIterations(){
    int number_of_iterations = 0;
    printf("Enter the number of rectangles being generated: \n");
    scanf("%d", &number_of_iterations);
    return  number_of_iterations;
}