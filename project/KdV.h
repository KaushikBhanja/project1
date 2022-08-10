#ifndef KDV_H
#define KDV_H

void rk4(double x[], double xnew[], double dt, double dx);
void kdv(double x[], double xnew[], double dt, double dx);
void kdvExact(double x[], double t, double v, double x0);

#endif
