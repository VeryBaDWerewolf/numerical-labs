#ifdef VECTOR_H
#define VECTOR_H

typedef struct dvector dvector;


void vector_initd(dvector *v, size_t size);
int vector_set(dvector *v, double *d, size_t size);
void vector_freed(dvector *v);

dvector vector_sum(dvector *u, vector*v);
dvector vector_dif_Nonnull(dvector *u, vector*v);


#endif
