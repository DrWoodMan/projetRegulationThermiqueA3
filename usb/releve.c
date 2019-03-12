#include <windows.h>
#include "lib/ftd2xx.h"
#include "releve.h"

temp_t releve(){
    int indice=0;
    short tempExt=0,tempInt=0; // 16 OCTET
    temp_t temperature;
    //todo faire la syncronisation en usb
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD RxBytes=6;
    DWORD BytesReceived;
    char RxBuffer[6]={0};
    char octets[6]={0};
    //verif port usb connecte
    ftStatus = FT_Open(0,&ftHandle);
        if (ftStatus != FT_OK) {
            // FT_Open OK, use ftHandle to access device
            printf("\nechec de la lecture usb");
            return ;
        }
    //lecture des 6 octets
    ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
    if (ftStatus == FT_OK) {
        if (BytesReceived == RxBytes) {
            printf("\nlecture reussite");
        }
        else {
           printf("\nechec de la lecture");
        }
     }
    FT_Close(ftHandle);
   
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
    //traitement des octets trie
    tempExt=((octets[0] &0x0F)<<8)|((octets[1] &0x0F)<<4)|(octets[2]&0x0F);
    tempInt=((octets[3] &0x0F)<<8)|((octets[4] &0x0F)<<4)|(octets[5]&0x0F);
    temperature.interieure=(float)tempInt*0.04 -39.64;
    temperature.exterieure=(float)tempExt*0.04 -39.64;
    return temperature;
}

