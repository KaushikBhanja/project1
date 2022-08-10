#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define DX 0.1
#define L  8
#define DT 1e-4
#define N  160

void rk4(double x[], double xnew[], double dt, double dx) {

	int i;
	double *k1 = malloc(sizeof(double) * N);
	double *k2 = malloc(sizeof(double) * N);
	double *k3 = malloc(sizeof(double) * N);
	double *k4 = malloc(sizeof(double) * N);

	kdv(x, k1, dt, dx);
	for(i = 0; i < N; i++) {
		xnew[i] = x[i] + 0.5 * k1[i] * dt;
	}
	kdv(xnew, k2, dt, dx);
	for(i = 0; i < N; i++) {
		xnew[i] = x[i] + 0.5 * k2[i] * dt;
	}
	kdv(xnew, k3, dt, dx);
	for(i = 0; i < N; i++) { 
		xnew[i] = x[i] + k3[i] * dt;
	}
	kdv(xnew, k4, dt, dx);
	for(i = 0; i < N; i++) {
		xnew[i] = x[i] + 1./6. * (k1[i] + 2. * k2[i] + 2. * k3[i] + k4[i]) * dt;
	}

	free(k1);
	free(k2);
	free(k3);
	free(k4);
}