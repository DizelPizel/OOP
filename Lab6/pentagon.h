#ifndef PENTAGON_H
#define PENTAGON_H

#include"figure.h"
#include"allocator.h"

class Pentagon : public Figure {
  double x[ 5 ];
  double y[ 5 ];
  static Allocator * allocator;
public:
  static void setAllocator( Allocator * a );
  Pentagon();
  virtual ~Pentagon();
  Pentagon( const Pentagon & t );
  friend std::istream & operator >> ( std::istream & in, Pentagon & t );
  friend std::ostream & operator << ( std::ostream & os, const Pentagon & t );
  Pentagon & operator = ( const Pentagon & t );
  bool operator == ( const Pentagon & t ) const;
  virtual size_t VertexesNumber() const;
  virtual double Area() const;
  virtual void Print( std::ostream & os ) const;
  // Переопределение оператора new
  void * operator new ( size_t );
  // Переопределение оператора delete
  void operator delete( void * );
};

std::istream & operator >> ( std::istream & in, Pentagon & t );
std::ostream & operator << ( std::ostream & os, const Pentagon & t );

#endif /* PENTAGON_H */
