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
    
float regulation(int regul, float csgn, float tN, float tNm1, float* integrale,int mode_PID){
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
			if(tN < tNm1){
				i = ((csgn-tNm1)*dt)+(tNm1-tN)*dt/2;				
			}else if(tN > tNm1){
				i = (dt*(csgn-tN))+(tN-tNm1)*dt/2;
			}else{
				i=0;
			}
			*integrale += i;

			d = (tNm1 - tN) / dt;
			if(mode_PID==1){
				cmd = p + *integrale*0.1 + d*0.1;
			}else if(mode_PID==2){
				cmd = p*6 + *integrale*0.5 + d*0.1;
			}
			if(cmd<0){
				cmd=0;
			}else if(cmd>100){
				cmd=100;
			}
			break;
	}
	return cmd;
}