#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define DX 0.1
#define L  8
#define DT 1e-4
#define N  160


void kdv(double x[], double xnew[], double dt, double dx) {

	int i;
	double *f1 = malloc(sizeof(double) * N);
	double *f2 = malloc(sizeof(double) * N);
	double *f3 = malloc(sizeof(double) * N);
	double *f4 = malloc(sizeof(double) * N);
	double *b1 = malloc(sizeof(double) * N);
	double *b2 = malloc(sizeof(double) * N);
	double *b3 = malloc(sizeof(double) * N);
	double *b4 = malloc(sizeof(double) * N);
	double *ux1 = malloc(sizeof(double) * N);
	double *ux3 = malloc(sizeof(double) * N);

	for(i = 0; i < N-1; i++) {
		f1[i] = x[i+1];
	}
	f1[N-1] = x[0];

	for(i = 0; i < N-2; i++) {
		f2[i] = x[i+2];
	}
	f2[N-1] = x[1];
	f2[N-2] = x[0];

	for(i = 0; i < N-3; i++) {
		f3[i] = x[i+3];
	}
	f3[N-1] = x[2];
	f3[N-2] = x[1];
	f3[N-3] = x[0];

	for(i = 0; i < N-4; i++) {
		f4[i] = x[i+4];
	}
	f4[N-1] = x[3];
	f4[N-2] = x[2];
	f4[N-3] = x[1];
	f4[N-4] = x[0];

	for(i = 1; i < N; i++) {
		b1[i] = x[i-1];
	}
	b1[0] = x[N-1];

	for(i = 2; i < N; i++) {
		b2[i] = x[i - 2];
	}
	b2[0] = x[N-2];
	b2[1] = x[N-1];

	for(i = 3; i < N; i++) {
		b3[i] = x[i - 3];
	}
	b3[0] = x[N-3];
	b3[1] = x[N-2];
	b3[2] = x[N-1];

	for(i = 4; i < N; i++) {
		b4[i] = x[i - 4];
	}
	b4[0] = x[N-4];
	b4[1] = x[N-3];
	b4[2] = x[N-2];
	b4[3] = x[N-1];


	for(i = 0; i < N; i++) {
		ux1[i] = (                            (f3[i] - b3[i]) -   9. * (f2[i] - b2[i]) +  45. * (f1[i] - b1[i])) / ( 60. * dx);
		ux3[i] = (7 * (f4[i] - b4[i]) - 72. * (f3[i] - b3[i]) + 338. * (f2[i] - b2[i]) - 488. * (f1[i] - b1[i])) / (240. * dx * dx * dx);

		xnew[i] = -6. * x[i] * ux1[i] - ux3[i];
	}

	free(f1);
	free(f2);
	free(f3);
	free(f4);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
	free(ux1);
	free(ux3);
}