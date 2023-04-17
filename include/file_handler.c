//
// Created by maylis on 16.03.23.
//

#include "file_handler.h"
#include "graphics_handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int create_ppm_header(char *pFilename){
    int ret = EXIT_FAILURE;
    FILE *pFileHandler = fopen(pFilename, "w");
    if(NULL != pFileHandler){
        fprintf(pFileHandler, "P3\n%d %d\n255\n", SIZE_X, SIZE_Y);
        fclose(pFileHandler);
        ret = EXIT_SUCCESS;
    }else{
        assert("File could not be opened!");
    }
    return ret;
}

int writeBufferToFile(char *pFilename, int i_pBuffer[SIZE_X][SIZE_Y]){
    int ret = EXIT_FAILURE;
    FILE *pFileHandler = fopen(pFilename, "a");
    if(NULL != pFileHandler){
        for (int i = 0; i < SIZE_X ; ++i) {
            for (int j = 0; j < SIZE_Y; ++j) {
                int currentElement = i_pBuffer[i][j];
                switch (currentElement) {
                    case 0:
                        fprintf(pFileHandler, "255 255 255");
                        break;
                    case 1:
                        fprintf(pFileHandler, "0 0 255");
                        break;
                }
                fprintf(pFileHandler, " ");
            }
        }
        fclose(pFileHandler);
        ret = EXIT_SUCCESS;
    }else{
        assert("File could not be opened!");
    }
    return ret;
}
