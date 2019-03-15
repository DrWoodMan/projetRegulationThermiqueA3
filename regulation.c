   #include "regulation.h"
	 
	float regulationTest(int regul, float csgn, float* tabT, int nT){
		float cmd=100.0;
		float* integrale = malloc(sizeof(float));
		*integrale = 0;
		
		int i = 0;
		
		for(i = 0 ; i < nT ; i++){
			cmd = regulation(regul, csgn, tabT[i], tabT[i > 0 ? i - 1 : i], integrale,1);
		} 
		free(integrale);
		return cmd;
   }

/***************************************************************
 * 
 * nom :          regulation
 * 
 * fonction :     Si le fichier ".verrourData" n'existe pas
 *                le creer, écrit dans "data.txt" les valeurs
 *                contenues dans la myTemp.
 *                Supprime ensuite le fichier ".verrourConsigne".
 *                Ne fait rien si le fichier ".verrourData" existe.
 * 
 * paramètres :   (int) regul : mode de régulation, 1 pour ToR, 2 pour PID
 * 								(float) csgn : température de consigne
 * 								(float) tN : tempéature intérieure actuelle N
 * 								(float) tNm1 : température  intérieure précédente N-1
 * 								(float*) integrale : somme des intégrale précédemment calculées
 * 								(int) mode_PID : 1 pour tests unitaires, 2 pour simulation, 3 pour usb
 *                
 * retour :       
 * 
 ***************************************************************/

float regulation(int regul, float csgn, float tN, float tNm1, float* integrale, int mode_PID){
	int dt = 10;
	float p, i, d, cmd=0;

	switch (regul){
		case 1:
			if(tN < csgn){
				cmd = 40;
			}else{
				cmd = 0;
			}
			break;
	
		case 2:
			p = csgn - tN; //calcule de la différence avec la température de consigne

			// calcule de l'intégrale
			if(tN < tNm1){
				i = ((csgn-tNm1)*dt)+(tNm1-tN)*dt/2;				
			}else if(tN > tNm1){
				i = (dt*(csgn-tN))+(tN-tNm1)*dt/2;
			}else{
				i=0;
			}
			*integrale += i;

			d = (tNm1 - tN) / dt; //calcule de la dérivée
			if(mode_PID==1){
				cmd = p + *integrale*0.1 + d*0.1;
			}else if(mode_PID==2){
				cmd = p*6 + *integrale*0.5 + d*0.1;
			}else if(mode_PID==3){
				cmd=p*6 + *integrale*0.1 + d*0.001;
			}
			if(cmd<0){
				cmd=0;
			}else if(cmd>100){
				cmd=100;
			}
			break;

		default :
			if(tN < csgn){
				cmd = 40;
			}else{
				cmd = 0;
			}
			break;
	}
	return cmd;
}