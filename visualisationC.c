#include "visualisationC.h"

void visualisationC(float puissance_f){
   if( access( ".verrouData", F_OK ) != -1 ){
    // Fichier existe
   }else{/*
      FILE *fp = NULL;
      int i = 0;
      char fileContent[3][7];
      printf("1\n");
      fclose(fopen(".verrouData", "w"));

      fp = fopen("data.txt", "r+");
      while(fgets(fileContent[i], 7, fp)){
         if(fileContent[i][strlen(fileContent[i]) - 1] == '\n'){
            fileContent[i][strlen(fileContent[i]) - 1] = '\0';
         }
      i++;
      }
      

      if(puissance_f == 0){
         printf("%s\n", fileContent[2]);
         if(fileContent[2][0] == 't'){
            printf("2 \n");
            fseek(fp, -4, SEEK_END);
            fprintf(fp, "%s", "false");
         }
      }else if(puissance_f > 0 && puissance_f <= 100){
         if(fileContent[2][0] == 'f'){
            printf("3\n");
            fseek(fp, -5, SEEK_END);
            fprintf(fp, "%s", "true\n");
         }
      }


      fclose(fp);
      remove(".verrouData");
      */
     
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
