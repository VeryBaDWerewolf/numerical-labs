#include "headers/vector.h"

void vector_init(dvector *v, size_t size){
  v->length = size;
  v->data = calloc(size, sizeof(double));
}

void vector_set(dvector *v, double *d, size_t size){
  vector_init(v, size);
  for(int i = 0; i<size; i++)
    v->data[i] = d[i];
}

dvector vector_sum(dvector *u, dvector *v){
  assert(u->length == v->length);
  
  dvector sum;
  int l = u->length;

  vector_init(&sum, l);

  for(int i = 0; i<l; i++)
    sum.data[i] = u->data[i] + v->data[i];

  return sum; 
}

dvector vector_dif(dvector *u, dvector *v){
  assert(u->length == v->length);
  dvector dif;
  int l = u->length;

  vector_init(&dif, l);

  for(int i = 0; i<l; i++)
    dif.data[i] = u->data[i] - v->data[i];

  return dif; 
}

dvector vector_sc_mult(dvector *u, double sclr){
  dvector scmlt;
  int l = u->length;

  vector_init(&scmlt, l);

  for(int i = 0; i<l; i++)
    scmlt.data[i] = u->data[i]*sclr;

  return scmlt; 
}

dvector vector_negate(dvector *v){
  dvector nv;
  vector_init(&nv, v->length);
  nv = vector_dif(&nv, v);
  return nv;
}


double vector_dot(dvector *u, dvector *v){
  assert(u->length == v->length);
  double dot = 0;
  int size = u->length;

  for(int i = 0; i<size; i++)
    dot += u->data[i] * v->data[i];

  return dot;
}

void vprint(dvector *v){
  int s = v->length;
  for(size_t i = 0 ; i<s; i++)
    printf("%.5f ", v->data[i]); 
}





void vector_free(dvector *v){
  free(v->data);
}


