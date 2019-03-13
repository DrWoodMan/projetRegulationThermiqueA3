#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "consigne.h"
#include "visualisationT.h"
#include "visualisationC.h"
 #include "regulation.h"

int main(){
	
	temp_t temperature;
	temperature.exterieure = 15.0;
	temperature.interieure = 17.0;
	/*visualisationT(temperature);
	printf("test-sim : %2.2f\n",consigne(20.00));
	visualisationC(0.0);
	
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	int i=0; // increment de boucle
	float puissance = 70.0; // puissance de chauffage
	for(i=0;i< 30;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur
	*/
	integrationTest(2, temperature, 5);
	return EXIT_SUCCESS;
}
