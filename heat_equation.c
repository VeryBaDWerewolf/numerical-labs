#include "heat_equation.h"
#include "utils/headers/linear-sys-solve.h"
#include "utils/headers/matrix.h"
#include "utils/headers/vector.h"

dmatrix backward_euler(double dx, double dt, double (*U)(double, double), double (*f)(double, double)){

  double mu = ((-A_CONST)*dt)/(dx*dx);
  size_t nx =  (X_END-X_START)/dx + 1;
  size_t nt =  (T_END-T_START)/dt + 1;

  dmatrix grid;
  matrix_init(&grid, nt, nx);

  for(size_t i = 0; i < nx; i++)
    grid.data[0][i] = U(i*dx, 0);
  for(size_t i = 0; i < nt; i++)
    grid.data[i][0] = U(0, i*dt);
  for(size_t i = 0; i < nt; i++)
    grid.data[i][nx-1] = U(1, i*dt);

  dmatrix B;
  matrix_init(&B, nx, nx);

  B.data[0][0] = 1;
  B.data[nx-1][nx-1] = 1;
  for(size_t i = 1; i<(nx-1); i++){
    B.data[i][i-1] = mu;
    B.data[i][i] = (1-2*mu);
    B.data[i][i+1] = mu;
  }
 
  dvector v;
  vector_init(&v, nx);

  for(size_t i = 1; i < nt; i++){
    v.data[0] = grid.data[i][0];
    v.data[nx-1] = grid.data[i][nx-1];

    for(size_t j = 1; j < nx-1; j++)
      v.data[j] = (dt * f(j*dx, i*dt)) + grid.data[i-1][j];
   
    
    dvector q = tridiag_solve(&B, &v);
    for(size_t k = 0; k < nx; k++)
      grid.data[i][k] = q.data[k];
    vector_free(&q);
  }
  vector_free(&v);
  matrix_free(&B);
  

  
  return grid;
  
}
