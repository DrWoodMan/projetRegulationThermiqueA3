#include "commande.h"
void commande(FT_HANDLE ftHandle,FT_STATUS ftStatus,float puissance){
    //Varriables :
    DWORD BytesWritten;
    char TxBuffer[1];
   
    //Traitement donnée puissance
    TxBuffer[0]= (puissance*1.27);
    TxBuffer[0] = (int)TxBuffer[0]&0x7F;

    //Ecriture de la puissance
    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);
    if (ftStatus == FT_OK) {
        printf("\nValeur ecrite %u",TxBuffer[0]);
    }
    else {
        printf("\nErreur d'ecriture");
    }
}



