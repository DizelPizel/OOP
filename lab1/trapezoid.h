#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include"figure.h"

class Trapezoid : public Figure {
  double x[ 4 ];
  double y[ 4 ];
public:
  Trapezoid();
  virtual ~Trapezoid();
  virtual size_t VertexesNumber() const;
  virtual double Area() const;
  virtual void Print( std::ostream & os ) const;
};

#endif /* TRAPEZOID_H */
