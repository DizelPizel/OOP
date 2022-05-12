#ifndef PENTAGON_H
#define PENTAGON_H

#include"figure.h"

class Pentagon : public Figure {
  double x[ 5 ];
  double y[ 5 ];
public:
  Pentagon();
  virtual ~Pentagon();
  virtual size_t VertexesNumber() const;
  virtual double Area() const;
  virtual void Print( std::ostream & os ) const;
};

#endif /* PENTAGON_H */
