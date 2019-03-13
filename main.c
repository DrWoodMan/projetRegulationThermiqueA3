//#include <stdio.h>
#include "releve.h"
#include "commande.h"
#include "define.h"
#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"
int main(/*int argc, char *argv[]*/){
   /* float* integrale = malloc(sizeof(float));
    float csgn, cmd;
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus; */
    temp_t temperatures, temperatures_Acienne;
    /*
    //verif port usb connecte
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        printf("\nEchec de la lecture usb");
        return;
    }
    *integrale = 0;
    temperatures = releve(ftHandle,ftStatus);
    commande(ftHandle,ftStatus,0);
    csgn = consigne(csgn);
    if(csgn<5){
      return 0;
    }*/
    temperatures.exterieure=0;
    temperatures.interieure=0;
    visualisationT(temperatures);
    visualisationC(0);
    /*while(1){     
        visualisationT(temperatures);
        csgn = consigne(csgn);
        cmd = regulation(1, csgn, temperatures.interieure, temperatures_Acienne.interieure, integrale,2);
        visualisationC(cmd);
        temperatures_Acienne=temperatures;
        temperatures = releve(ftHandle,ftStatus);
        printf("\next :%lf int :%lf\n",temperatures.exterieure,temperatures.interieure);
        printf("\nconsignes:%lf\n",temperatures.exterieure,temperatures.interieure);
    } */
    FT_Close(ftHandle);
    free(integrale);
    return 0;
}

