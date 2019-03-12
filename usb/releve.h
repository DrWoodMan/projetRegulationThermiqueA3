#include <stdio.h>
#include "lib/ftd2xx.h"
typedef struct temp_t temp_t;
struct temp_t{
    float interieure;
    float exterieure;
};

temp_t releve(FT_HANDLE ftHandle,FT_STATUS ftStatus);

