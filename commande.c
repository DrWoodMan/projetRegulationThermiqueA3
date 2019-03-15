#include "commande.h"
/* La fonction commande prend en entré la puisance en %  et fthandle, ftstatus pour la liaison usb.
   La fonction permet d'écrire un octet qui renvoie la puissance voulu à la carte.
*/
void commande(FT_HANDLE ftHandle,FT_STATUS ftStatus,float puissance){
    //Varriables :
    DWORD BytesWritten;
    char TxBuffer[1];
    //Ouverture et verification port usb connecte
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        printf("\nEchec de la lecture usb");
        return;
    }
    //Traitement de la donnée puissance
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
    //Fermeture de connexion
    FT_Close(ftHandle);
}



