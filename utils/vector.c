#include "headers/vector.h"
#include <stdlib.h>
typedef struct dvector dvector;

struct dvector{
  double *data;
  size_t length;
};


void vector_init(dvector *v, size_t size){
  v->length = size;
  v->data = calloc(size, sizeof(void*));
}

int vector_set(dvector *v, double *d, size_t size){
  if(size != v->length)
    return 0;
  for(int i = 0; i<size; i++)
    v->data[i] = d[i];
  return size;
}

dvector vector_sum(dvector *u, dvector *v){
  dvector sum;
  int l = u->length;

  vector_init(&sum, l);

  for(int i = 0; i<l; i++)
    sum.data[i] = u->data[i] + v->data[i];

  return sum; 
}

dvector vector_dif(dvector *u, dvector *v){
  dvector dif;
  int l = u->length;

  vector_init(&dif, l);

  for(int i = 0; i<l; i++)
    dif.data[i] = u->data[i] + v->data[i];

  return dif; 
}





void vector_free(dvector *v){
  free(v->data);
}
