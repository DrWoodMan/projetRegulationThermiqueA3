   #include "regulation.h"
	 
	float regulationTest(int regul, float csgn, float* tabT, int nT){
		float cmd=100.0;
		float* integrale = NULL;
		integrale = 0;
		int i = 0;
		for(i = 0 ; i < nT ; i++){
			cmd = regulation(regul, csgn, tabT[i], tabT[i > 0 ? i - 1 : i], &integrale);
		}
		return cmd;
   }
    
float regulation(int regul, float csgn, float tN, float tNm1, float* integrale){
	int dt = 10;
	float p, i, d, cmd;

	switch (regul){
		case 1:
			if(tN < csgn){
				cmd = 40;
			}else{
				cmd = 0;
			}
			break;
	
		case 2:
			p = csgn - tN;
			//printf("p : %f\n", p);
			if(tN == tNm1){
				i = 0;
			}else if(p > 0){
				i = (dt * ((tN < tNm1 ? tN : tNm1) - csgn)) + ((((tN - tNm1) * ((tN >= tNm1) ? 1 : -1))*dt) / 2);
			}else if(p < 0){
				i = (dt * ((tN )))
			}
				*integrale += i;
			printf("i : %f\n", i);
			d = (tN - tNm1) / dt;
			//printf("d : %f\n", d);
			cmd = p + i*0.1 + d*0.1;
			break;
	}
	return cmd;
}