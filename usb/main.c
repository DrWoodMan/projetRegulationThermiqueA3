//#include <stdio.h>
#include "releve.h"
int main(/*int argc, char *argv[]*/){
    int i=0;
    printf("ok\n");
    temp_t temperatures;
    temperatures = releve();
    printf("\next :%lf int :%lf\n",temperatures.exterieure,temperatures.interieure);
    printf("ok2\n");
    commande(127);
    while(1){
        commande(i);
        temperatures = releve();
        printf("\next :%lf int :%lf\n",temperatures.exterieure,temperatures.interieure);
        i++;
        if(i==127){
            i=0;
        }
    }
}

