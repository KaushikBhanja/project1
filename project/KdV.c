#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DX 0.1
#define L  8
#define DT 1e-4
#define N  160

void rk4(double x[], double xnew[], double dt, double dx);
void kdv(double x[], double xnew[], double dt, double dx);
void kdvExact(double x[], double t, double v, double x0);

int main(void) {

	int i, j;
	double t, plot1, plot2;
	double *x    = (double *) malloc(N * sizeof(double));
	double *xnew = (double *) malloc(N * sizeof(double));

	for(i = 0; i < N; i++) {
	    x[i] = -L + i * DX;
		xnew[i] = -L + i * DX;
	}

	/* 
	 * Initial Conditions
	 */
	kdvExact(x, 0., 16., 4.);
	kdvExact(xnew, 0., 4., -4.);

	for(i = 0; i < N; i++) {
		x[i] = x[i] + xnew[i];
	}

	t = 0.;
	j = 0;
	while(t < 2) {

		if((j % 100) == 0) {
	        for(i = 0; i < N; i++) {
				plot1 = -L + i*DX;
				plot2 = x[i];
				printf("%e \n", plot2);
		        //printf("%e %e\n", -L + i * DX, x[i]);
	        }
			printf("\n\n");
		}

		rk4(x, xnew, DT, DX);

		for(i = 0; i < N; i++) {
			x[i] = xnew[i];
		}
		
		j++;
		t += DT;
	}
	
	free(x);
	free(xnew);

	return 0;
}
