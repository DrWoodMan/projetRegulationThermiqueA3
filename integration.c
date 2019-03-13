#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "simulateur.h"
#include "consigne.h"

void integrationTest(int regul, temp_t tInit, int nIterations){

  temp_t tempN, tempNm1;
  float csgn, cmd;
  struct simParam_s* param_sim;
	float* integrale = malloc(sizeof(float));

  tempNm1 = tInit;
  tempN = tInit;
  cmd = 100.0;
	*integrale = 0;

  param_sim = simConstruct(tInit);
  csgn = 0;
  do{
    visualisationT(tempN);
    csgn = consigne(csgn);
    cmd = regulation(regul, csgn, tempN.interieure, tempNm1.interieure, integrale);
    visualisationC(cmd);
    tempNm1 = tempN;
    tempN = simCalc(cmd, param_sim);
  }while(csgn > 5);

  
  
}
