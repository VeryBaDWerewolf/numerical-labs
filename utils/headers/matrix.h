#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct dmatrix dmatrix;

struct dmatrix{
  size_t m, n;
  double **data;
};

void matrix_init(dmatrix *a, size_t m_, size_t n_);
void matrix_set(dmatrix *a, double **data_, size_t m_, size_t n_);
void matrix_free(dmatrix *a);

dmatrix matrix_eye(int n_);
dmatrix matrix_sum(dmatrix *a, dmatrix *b);
dmatrix matrix_dif(dmatrix *a, dmatrix *b);
dmatrix matrix_mult(dmatrix *a, dmatrix *b);
dmatrix matrix_sc_mult(dmatrix *a, double b);
dvector matrix_vc_mult(dmatrix *a, dvector *v);


void mprint(dmatrix *a);

#endif
