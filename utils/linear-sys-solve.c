#include "headers/linear-sys-solve.h"
#include "headers/matrix.h"
#include "headers/vector.h"

dvector tridiag_solve(dmatrix *A, dvector *b){
  size_t dim = b->length;
  

  dvector alphas;
  dvector betas;
  dvector gammas;

  dvector x;

  vector_init(&alphas, dim-1);
  vector_init(&betas,  dim);
  vector_init(&gammas, dim);

  vector_init(&x, dim);

  gammas.data[0] = A->data[0][0];
  alphas.data[0] = (- A->data[0][1])/(gammas.data[0]);
  betas.data[0] = b->data[0] / gammas.data[0];

  for(size_t i = 1; i<(dim-1); i++){
    gammas.data[i] = A->data[i][i] + alphas.data[i-1] * A->data[i][i-1];
    alphas.data[i] = -(A->data[i][i+1])/(gammas.data[i]);
     betas.data[i] = (b->data[i] - betas.data[i-1] *  A->data[i][i-1])/gammas.data[i];
   }
  
  gammas.data[dim-1] = A->data[dim-1][dim-1] + \
                       alphas.data[dim-2] * A->data[dim-1][dim-2];
  betas.data[dim-1]  = (b->data[dim-1] - betas.data[dim-2] *  A->data[dim-1][dim-2]) / \
                       (gammas.data[dim-1]);

  x.data[dim - 1] = betas.data[dim-1];
  
  
  for(size_t i = (dim-2); i != -1; i--)
    x.data[i] = alphas.data[i]*x.data[i+1] + betas.data[i];
  

  vector_free(&alphas);
  vector_free(&betas);
  vector_free(&gammas);

  return x;
}
