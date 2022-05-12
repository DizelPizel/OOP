#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include"figure.h"

class Trapezoid : public Figure {
  double x[ 4 ];
  double y[ 4 ];
public:
  Trapezoid();
  Trapezoid( const Trapezoid & t );
  friend std::istream & operator >> ( std::istream & in, Trapezoid & t );
  friend std::ostream & operator << ( std::ostream & os, const Trapezoid & t );
  Trapezoid & operator = ( const Trapezoid & t );
  bool operator == ( const Trapezoid & t ) const;
  virtual ~Trapezoid();
  virtual size_t VertexesNumber() const;
  virtual double Area() const;
  virtual void Print( std::ostream & os ) const;
};
  
std::istream & operator >> ( std::istream & in, Trapezoid & t );
std::ostream & operator << ( std::ostream & os, const Trapezoid & t );

#endif /* TRAPEZOID_H */
