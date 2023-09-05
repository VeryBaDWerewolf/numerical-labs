#pragma once

#include <vector>

template<typename T> class Mesh{
  double x_start = 0, x_end = 1;
  double y_start = 0, y_end = 1;

  double h1, h2; //h1 for oX and h2 for oY
  std::vector<T> data_x;
  std::vector<T> data_y;



 public:
  Mesh(double x_start, double x_end, double y_start, double y_end, double h1, double h2);
  Mesh(double h1, double h2);
  Mesh(double h);

  T operator[](int x);
  
};
