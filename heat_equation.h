#ifndef HE_H
#define HE_H 

#define A_CONST 0.024

#define X_START 0
#define X_END 1

#define T_START 0
#define T_END 1


#include "utils/headers/vector.h"
#include "utils/headers/matrix.h"

dmatrix backward_euler(double dx, double dt, double (*U)(double, double), double (*f)(double, double));


#endif
