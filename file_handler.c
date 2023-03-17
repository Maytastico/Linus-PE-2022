//
// Created by maylis on 16.03.23.
//

#include "file_handler.h"
#include "graphics_handler.h"
#include <stdlib.h>
#include <stdio.h>

int create_ppm(char *pFilename, int size_X, int size_Y){
    int ret = EXIT_FAILURE;
    FILE *pFileHandler = fopen(pFilename, "w");
    if(NULL != pFileHandler){
        fprintf(pFileHandler, "P3\n %d %d\n 255\n", size_X, size_Y);
        fclose(pFileHandler);
        ret = EXIT_SUCCESS;
    }
    return ret;
}

int writeBufferToFile(int i_pBuffer[SIZE_X][SIZE_Y]){

}
