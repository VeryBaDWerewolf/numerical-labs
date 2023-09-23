#ifndef VECTOR_H
#define VECTOR_H 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
typedef struct dvector dvector;

struct dvector{
  double *data;
  size_t length;
};


void vector_init(dvector *v, size_t size);
void vector_set(dvector *v, double *d, size_t size);
void vector_free(dvector *v);


dvector vector_negate(dvector *v);
dvector vector_sum(dvector *u, dvector *v);
dvector vector_dif(dvector *u, dvector *v);
dvector vector_sc_mult(dvector *v, double sclr);



double vector_dot(dvector *u, dvector *v);

void vprint(dvector *v);


#endif
