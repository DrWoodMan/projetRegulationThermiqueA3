#include "releve.h"
#include "commande.h"
#include "define.h"
#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"

int main(/*int argc, char *argv[]*/){
    //Varriables :
    float* integrale = malloc(sizeof(float));
    float csgn=0, cmd;
    int mode,mode_PID;
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    temp_t temperatures, temperatures_Acienne;

   //Ouverture et verification port usb connecte
   /* ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        printf("\nEchec de la lecture usb");
        return;
    } */
    *integrale = 0;
    cmd=0;
    temperatures = releve(ftHandle,ftStatus);
    temperatures_Acienne=temperatures;
    commande(ftHandle,ftStatus,cmd);
    csgn = consigne(csgn);
    // TOR = 1 / PID = 2
    mode=2;
    /*
      mode_PID=1;// tests unitaires
      mode_PID=2;// intégration dans le simulateur
      mode_PID=3;// intégration en USB
    */
    mode_PID=1;
    if(csgn<5){
      return 0;
    }
    visualisationT(temperatures);
    //Suppresion des verrous s'ils existent encore
    remove(".verrouData");
    remove(".verrouConsigne");
    //programme lancer
    while(1){    
        visualisationT(temperatures);
        csgn = consigne(csgn);
        cmd = regulation(mode, csgn, temperatures.interieure, temperatures_Acienne.interieure, integrale,mode_PID);
        visualisationC(cmd);
        commande(ftHandle,ftStatus,cmd);
        temperatures_Acienne=temperatures;
        temperatures = releve(ftHandle,ftStatus);
        printf("\next :%lf int :%lf\n",temperatures.exterieure,temperatures.interieure);
        printf("\nconsignes:%lf\n",csgn);
        printf("\npuissance en :%f\n",cmd);
    } 
    //FT_Close(ftHandle);
    free(integrale);
    return 0;
}

