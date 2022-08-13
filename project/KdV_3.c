#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define N  160

void kdvExact(double x[], double t, double v, double x0) {

	int i;
	double denom;

	for(i = 0; i < N; i++) {
      denom = cosh(0.5 * sqrt(v) * (x[i] - v * t - x0));
	  x[i] = v / (2. * denom * denom);
	}

}