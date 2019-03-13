//#include <stdio.h>
#include "releve.h"
#include "commande.h"
int main(/*int argc, char *argv[]*/){
    int i=0;
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    printf("ok\n");
    temp_t temperatures;

    //verif port usb connecte
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        printf("\nEchec de la lecture usb");
        return;
    }
    
    temperatures = releve(ftHandle,ftStatus);
    printf("\next :%lf int :%lf\n",temperatures.exterieure,temperatures.interieure);
    printf("ok2\n");
    commande(ftHandle,ftStatus,10.00);
    while(1){
        commande(ftHandle,ftStatus,i);
        temperatures = releve(ftHandle,ftStatus);
        printf("\next :%lf int :%lf\n",temperatures.exterieure,temperatures.interieure);
        i++;
        if(i==100){
            i=0;
        }
    } 
    FT_Close(ftHandle);
}

