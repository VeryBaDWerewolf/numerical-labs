#include "headers/matrix.h"
#include "headers/vector.h"


void matrix_init(dmatrix *a, size_t m_, size_t n_){
  a->m = m_;
  a->n = n_;

  a->data = calloc(m_, sizeof(double*));
  
  for(size_t i = 0; i<m_; i++)
    a->data[i] = calloc(n_, sizeof(double));
}
void matrix_set(dmatrix *a, double **data_, size_t m_, size_t n_){
  matrix_init(a, m_, n_);
  for(int i = 0; i<m_; i++)
    for(int j = 0; j<n_; j++)
      a->data[i][j] = data_[i][j];
}



dmatrix matrix_eye(int n_){
  dmatrix a;
  
  matrix_init(&a, n_, n_);
  
  for(size_t i = 0; i< n_; i++)
    a.data[i][i] = 1.0;
  
  return a;
}

dmatrix matrix_sum(dmatrix *a, dmatrix *b){
  assert(a->n == b->n && a->m == b->m);

  dmatrix c;
  size_t m_ = a->m;
  size_t n_ = a->n;

  matrix_init(&c, m_, n_);

  for(size_t i = 0; i<m_; i++)
    for(size_t j = 0; j<n_; j++)
      c.data[i][j] = a->data[i][j] + b->data[i][j];

  return c;
}

dmatrix matrix_dif(dmatrix *a, dmatrix *b){
  assert(a->n == b->n && a->m == b->m);

  dmatrix c;
  size_t m_ = a->m;
  size_t n_ = a->n;

  matrix_init(&c, m_, n_);

  for(size_t i = 0; i<m_; i++)
    for(size_t j = 0; j<n_; j++)
      c.data[i][j] = a->data[i][j] - b->data[i][j];

  return c;
}

dmatrix matrix_mult(dmatrix *a, dmatrix *b){
  assert(a->n == b->m);

  dmatrix c;
  size_t m_ = a->m;
  size_t n_ = b->n;
  matrix_init(&c, m_, n_);

  for(size_t i = 0; i < m_; i++)
    for(size_t j = 0; j < n_; j++)
      for(size_t k = 0; k < n_; k++)
	c.data[i][j] += a->data[i][k]* (b->data[k][j]);

  return c;
}
dmatrix matrix_sc_mult(dmatrix *a, double b){
  dmatrix c;
  size_t m_ = a->m;
  size_t n_ = a->n;

  matrix_init(&c, m_, n_);

  for(size_t i = 0; i<m_; i++)
    for(size_t j = 0; j<n_; j++)
      c.data[i][j] = a->data[i][j]*b;

  return c;
}
dvector matrix_vc_mult(dmatrix *a, dvector *v){
  assert(v->length != 0);

  size_t n = v->length;
  dvector x;
  dmatrix tmp, tnp;
  
  matrix_init(&tmp, n, 1);
  vector_init(&x, n);
  
  for(size_t i = 0; i < n; i++) 
    tmp.data[i][0] = v->data[i];

  tnp = matrix_mult(a, &tmp);
  for(size_t i = 0; i < n; i++) 
    x.data[i] = tnp.data[i][0];

  matrix_free(&tmp);
  matrix_free(&tnp);

  return x; 
  
};

void matrix_free(dmatrix *a){
  size_t n = a->m;
  
  for(int i = 0; i<n; i++)
    free(a->data[i]);
  free(a->data);
}

void mprint(dmatrix *a){
  size_t m_ = a->m;
  size_t n_ = a->n;
  
  for(int i = 0; i<m_; i++){
    for(int j = 0; j<n_; j++)
      printf("%.5f ", a->data[i][j]);
    printf("\n");
  }
}
