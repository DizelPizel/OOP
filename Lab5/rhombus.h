#ifndef RHOMBUS_H
#define RHOMBUS_H

#include"figure.h"


class Rhombus : public Figure {
  double x[ 4 ];
  double y[ 4 ];
public:
  Rhombus();
  Rhombus( const Rhombus & t );
  friend std::istream & operator >> ( std::istream & in, Rhombus & t );
  friend std::ostream & operator << ( std::ostream & os, const Rhombus & t );
  Rhombus & operator = ( const Rhombus & t );
  bool operator == ( const Rhombus & t ) const;

  virtual ~Rhombus();
  virtual size_t VertexesNumber() const;
  virtual double Area() const;
  virtual void Print( std::ostream & os ) const;
};

std::istream & operator >> ( std::istream & in, Rhombus & t );
std::ostream & operator << ( std::ostream & os, const Rhombus & t );

#endif /* RHOMBUS_H */
