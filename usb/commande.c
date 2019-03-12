#include "commande.h"
#include "lib/ftd2xx.h"
void commande(int puissance){
    //Varriables :
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD BytesWritten;
    char TxBuffer[1]; 
    //Traitement donnée puissance
    if(puissance==0){
        TxBuffer[0] = 0;
    }else{
        TxBuffer[0] = (char)puissance&0x7F;
    }
    //verif port usb connecte
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        printf("\nEchec de la lecture usb");
        return;
    }
    //Ecriture de la puissance
    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);
    if (ftStatus == FT_OK) {
        printf("\nValeur ecrite");
    }
    else {
        printf("\nErreur d'ecriture");
    }
    FT_Close(ftHandle);
}



