#ifndef RHOMBUS_H
#define RHOMBUS_H

#include"figure.h"
#include"allocator.h"

class Rhombus : public Figure {
  double x[ 4 ];
  double y[ 4 ];
  static Allocator * allocator;
public:
  static void setAllocator( Allocator * a );
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
  // Переопределение оператора new
  void * operator new ( size_t );
  // Переопределение оператора delete
  void operator delete( void * );
};

std::istream & operator >> ( std::istream & in, Rhombus & t );
std::ostream & operator << ( std::ostream & os, const Rhombus & t );

#endif /* RHOMBUS_H */
