#include "visualisationC.h"

/***************************************************************
 * 
 * nom :          visualisationC
 * 
 * fonction :     Si le fichier ".verrourData" n'existe pas
 *                le creer, lit et stocke les valeurs contenues
 *                dans le fichier "data.txt".
 *                Réécrit les valeurs dans le fichier "data.txt".
 *                Si puissance_f = 0, écrit "false" en fin de fichier.
 *                Si puissance_f est > 0 et <= 100 écrit "true" en fin
 *                de fichier.
 *                Supprime ensuite le fichier ".verrourConsigne".
 *                Ne fait rien si le fichier ".verrourData" existe.
 * 
 * paramètres :   (float) puissance_f : température de consigne
 *                
 * retour :       
 * 
 ***************************************************************/

void visualisationC(float puissance_f){

   if( access( ".verrouData", F_OK ) != -1 ){
    // Fichier existe
   }else{     
    // Fichier n'existe pas
    int i = 0;
    FILE *fp = NULL;
    char fileContent[3][7];

   
    fclose(fopen(".verrouData", "w"));

    fp = fopen("data.txt", "r");

    while(fgets(fileContent[i], 7, fp)){

      if(fileContent[i][strlen(fileContent[i]) - 1] == '\n'){
        fileContent[i][strlen(fileContent[i]) - 1] = '\0';
      }
      i++;
    }
    fclose(fp);

    fp = fopen("data.txt", "w");
    fprintf(fp, "%s\n", fileContent[0]);
    fprintf(fp, "%s\n", fileContent[1]);

    if(puissance_f == 0){
         fprintf(fp, "%s", "false");
         
      }else if(puissance_f > 0 && puissance_f <= 100){
         fprintf(fp, "%s", "true");
      }
    fclose(fp);

    remove(".verrouData");
  }
}
