#include "visualisationT.h"

/***************************************************************
 * 
 * nom :          visualisationT
 * 
 * fonction :     Si le fichier ".verrourData" n'existe pas
 *                le creer, écrit dans "data.txt" les valeurs
 *                contenues dans la myTemp.
 *                Supprime ensuite le fichier ".verrourConsigne".
 *                Ne fait rien si le fichier ".verrourData" existe.
 * 
 * paramètres :   (stuct temp_t) myTemp : température intérieure et extérieure
 *                
 * retour :       
 * 
 ***************************************************************/

void visualisationT(temp_t myTemp){
  
  if( access( ".verrouData", F_OK ) != -1 ){
    // Fichier existe
  }else{
    // Fichier n'existe pas
    int i = 0;
    FILE *fp = NULL;
    char fileContent[3][7];

    fp = fopen(".verrouData", "w");
    fclose(fp);

    fp = fopen("data.txt", "r");
    while(fgets(fileContent[i], 7, fp)){
      if(fileContent[i][strlen(fileContent[i]) - 1] == '\n'){
        fileContent[i][strlen(fileContent[i]) - 1] = '\0';
      }
      i++;
    }
    fclose(fp);

    fp = fopen("data.txt", "w");
    fprintf(fp, "%2.2f\n", myTemp.exterieure);
    fprintf(fp, "%2.2f\n", myTemp.interieure);
    fprintf(fp, "%s", fileContent[2]);
    fclose(fp);

    remove(".verrouData");
  }
}
