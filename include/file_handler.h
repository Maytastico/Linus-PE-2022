//
// Created by maylis on 16.03.23.
//

#ifndef LINUS_PE_2022_FILE_HANDLER_H
#define LINUS_PE_2022_FILE_HANDLER_H
#include "graphics_handler.h"

int create_ppm_header(char *pFilename);

int writeBufferToFile(char *pFilename, int i_pBuffer[SIZE_X][SIZE_Y]);

#endif //LINUS_PE_2022_FILE_HANDLER_H
