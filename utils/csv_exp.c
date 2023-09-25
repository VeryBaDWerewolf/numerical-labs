#include "headers/csv_exp.h"
#include <stdio.h>

void dm_csv(dmatrix *a){
  FILE *fp;
  size_t m_, n_;

  assert(fp != NULL);
  fp = fopen("data.csv","w");
  
  m_ = a->m;
  n_ = a->n;

  for(size_t i = 0; i < m_; i++){
    for(size_t j = 0; j < (n_- 1); j++)
      fprintf(fp, "%.10f,", a->data[i][j]);
    
    fprintf(fp, "%.10f", a->data[i][n_-1]);
    fprintf(fp, "\n");
    
    }
  fclose(fp);
}
