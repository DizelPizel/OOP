#ifndef RHOMBUS_H
#define RHOMBUS_H

#include"figure.h"


class Rhombus : public Figure {
  double x[ 4 ];
  double y[ 4 ];
public:
  Rhombus();
  virtual ~Rhombus();
  virtual size_t VertexesNumber() const;
  virtual double Area() const;
  virtual void Print( std::ostream & os ) const;
};


#endif /* RHOMBUS_H */
