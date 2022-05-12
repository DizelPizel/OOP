#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include"figure.h"
#include"allocator.h"

class Trapezoid : public Figure {
  double x[ 4 ];
  double y[ 4 ];
  static Allocator * allocator;
public:
  static void setAllocator( Allocator * a );
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
  // Переопределение оператора new
  void * operator new ( size_t );
  // Переопределение оператора delete
  void operator delete( void * );
};
  
std::istream & operator >> ( std::istream & in, Trapezoid & t );
std::ostream & operator << ( std::ostream & os, const Trapezoid & t );

#endif /* TRAPEZOID_H */
