#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define DX 0.1
#define L  8
#define DT 1e-4
#define N  160

void kdvExact(double x[], double t, double v, double x0) {

	int i;
	double denom;

	#pragma omp parallel for
	for(i = 0; i < N; i++) {
      denom = cosh(0.5 * sqrt(v) * (x[i] - v * t - x0));
	  x[i] = v / (2. * denom * denom);
	}

}