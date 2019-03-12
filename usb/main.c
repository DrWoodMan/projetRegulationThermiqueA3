//#include <stdio.h>
#include "releve.h"
int main(/*int argc, char *argv[]*/){
    printf("ok\n");
    temp_t temperatures;
    for(int i=0;i<50;i++){
        temperatures = releve();
        printf("\next :%lf int :%lf",temperatures.exterieure,temperatures.interieure);
    }
}

