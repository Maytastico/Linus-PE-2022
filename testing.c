#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "graphics_handler.h"

int main() {
    assert(addition(2, 3) == 5);
    assert(addition(0, 0) == 0);
    assert(addition(-2, 2) == 0);
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}
