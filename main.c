#include "releve.h"
#include "commande.h"
#include "define.h"
#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"

int main(){
    //Varriables :
    float* integrale = malloc(sizeof(float));
    float csgn=0, cmd;
    int mode,mode_PID;
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    temp_t temperatures, temperatures_Acienne;

   //Ouverture et verification port usb connecte
    *integrale = 0;
    cmd=0;
    temperatures = releve(ftHandle,ftStatus);
    temperatures_Acienne=temperatures;
    commande(ftHandle,ftStatus,cmd);
    csgn = consigne(csgn);
    // TOR = 1 / PID = 2
    mode=2;

    mode_PID=3;

    if(csgn<5){
      return 0;
    }
    visualisationT(temperatures);
    //Suppresion des verrous s'ils existent encore
    remove(".verrouData");
    remove(".verrouConsigne");

    //Programme lancé
    do{    
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
    }while(csgn > 5);

    free(integrale);
    return 0;
}

