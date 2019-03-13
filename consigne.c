#include "consigne.h"

float consigne(float csgn){

   if( access( ".verrouConsigne", F_OK ) != -1 ){
      // Fichier existe
      return csgn;
   }else{
      // Fichier n'existe pas
      float value;
      FILE *fp = NULL;
      char fileContent[6];

      fp = fopen(".verrouConsigne", "w");
      fclose(fp);

      fp = fopen("consigne.txt", "r");
      if(fgets(fileContent, 6, fp)){}
      if(fileContent[strlen(fileContent) - 1] == '\n'){
         fileContent[strlen(fileContent) - 1] = '\0';
      }
      fclose(fp);
      value = atof(fileContent);
      remove(".verrouConsigne");
      printf("%2.2f\n", value);
      return value;
   }

}
