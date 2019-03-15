#include "releve.h"
//la fonction releve() revoie la températures lue en USB avec 6 octets envoye avec les variable ftHandle et ftStatus
temp_t releve(FT_HANDLE ftHandle,FT_STATUS ftStatus){
    //Varriables :
    int indice=0;
    short tempExt=0,tempInt=0; 
    temp_t temperature;
    DWORD RxBytes=6;
    DWORD BytesReceived;
    char RxBuffer[6]={0};
    char octets[6]={0};

    //Ouverture et verification port usb connecte
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        printf("\nEchec de la lecture usb");
        return;
    }
    //Lecture des 6 octets
    ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
    if (ftStatus == FT_OK) {
        if (BytesReceived == RxBytes) {
            printf("\nLecture reussite");
        }
        else {
           printf("\nEchec de la lecture");
        }
     }
    
   
    //Trie des octets par rapport au premier octet de la température Ext :
    for(int i=0;i<6;i++){
        if((RxBuffer[i] &0xF0) == 0){
            indice=i;
        }
    }
     for(int i=0;i<6;i++){
         octets[i]=RxBuffer[indice];
         indice++;
         if(indice>5){
             indice=0;            
         }
     }
    //Traitement des octets trie
    tempExt=((octets[0] &0x0F)<<8)|((octets[1] &0x0F)<<4)|(octets[2]&0x0F);
    tempInt=((octets[3] &0x0F)<<8)|((octets[4] &0x0F)<<4)|(octets[5]&0x0F);
    //Température absolue en °C = -39,64 + 0,04 x SOT
    temperature.interieure=(float)tempInt*0.04 -39.64;
    temperature.exterieure=(float)tempExt*0.04 -39.64;
    //Fermeture de connexion
    FT_Close(ftHandle);
    return temperature;
}

