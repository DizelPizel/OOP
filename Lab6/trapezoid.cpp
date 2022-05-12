#include<iomanip>
#include"trapezoid.h"
#include"allocator.h"


void Trapezoid::setAllocator( Allocator * a ) {
  allocator = a;
}

size_t Trapezoid::VertexesNumber() const {
  return 4;
}

double Trapezoid::Area() const {
  return fabs( getOrArea( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ] ) +
	       getOrArea( x[ 0 ], y[ 0 ], x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ] ) );
}

void Trapezoid::Print( std::ostream & os ) const {
  os << "Trapezoid: ";
  os << showpos << fixed;
  for ( int i = 0; i < 4; i++ ) {
    os << "(" << setprecision( 1 ) << x[ i ] <<
            ", " << setprecision( 1 ) << y[ i ] <<
	    ")";
    if ( i < 3 )
      os << " ";
  }
  os << "\n";
  os << noshowpos;
} 

Trapezoid::~Trapezoid() { }

Trapezoid::Trapezoid() : Figure() {
  x[ 0 ] = 0.0;
  x[ 1 ] = 0.0;
  x[ 2 ] = 1.0;
  x[ 3 ] = 1.0;
  y[ 0 ] = 0.0;
  y[ 1 ] = 1.0;
  y[ 2 ] = 1.0;
  y[ 3 ] = 0.0;
}

std::istream & operator >> ( std::istream & in, Trapezoid & t ) {
  double _x[ 4 ];
  double _y[ 4 ];
  for ( int i = 0; i < 4; i++ ) {
    in >> _x[ i ];
    in >> _y[ i ];
  }
  if ( in.fail() ) {
    return in;
  }
  // Проверка математической корректности трапеции
  // Стороны трапеции
  double len0 = getLength( _x[ 0 ], _y[ 0 ], _x[ 1 ], _y[ 1 ] );
  double len1 = getLength( _x[ 1 ], _y[ 1 ], _x[ 2 ], _y[ 2 ] );
  double len2 = getLength( _x[ 2 ], _y[ 2 ], _x[ 3 ], _y[ 3 ] );
  double len3 = getLength( _x[ 3 ], _y[ 3 ], _x[ 0 ], _y[ 0 ] );

  // Если есть сторона нулевой длины
  if ( isDoubleZero( len0 ) ||
       isDoubleZero( len1 ) ||
       isDoubleZero( len2 ) ||
       isDoubleZero( len3 ) ) {
    throw FigException( "Error in Trapezoid >> operator: trapezoid with zero side length" );
  }

  // Если обе пары противоположных сторон не являются параллельными
  if ( ! isVectorsParallel( _x[ 0 ]-_x[ 1 ], _y[ 0 ]-_y[ 1 ], _x[ 3 ]-_x[ 2 ], _y[ 3 ]-_y[ 2 ] ) &&
       ! isVectorsParallel( _x[ 1 ]-_x[ 2 ], _y[ 1 ]-_y[ 2 ], _x[ 3 ]-_x[ 0 ], _y[ 3 ]-_y[ 0 ] ) ) {
    throw FigException( "Error in Trapezoid >> operator: trapeziod without parallel sides" );
  }

  // Все проверки выполнены. Копируем новые координаты
  for ( int i = 0; i < 4; i++ ) {
    t.x[ i ] = _x[ i ];
    t.y[ i ] = _y[ i ];
  }

  return in;
}

std::ostream & operator << ( std::ostream & out, const Trapezoid & t ) {
  out << "Trapezoid: ";
  out << showpos << fixed;
  for ( int i = 0; i < 4; i++ ) {
    out << "(" << setprecision( 1 ) << t.x[ i ] <<
            ", " << setprecision( 1 ) << t.y[ i ] <<
	    ")";
    if ( i < 3 )
      out << " ";
  }
  out << "\n";
  out << noshowpos;
  return out;
}

Trapezoid & Trapezoid::operator = ( const Trapezoid & t ) {
  for ( int i = 0; i < 4; i++ ) {
    x[ i ] = t.x[ i ];
    y[ i ] = t.y[ i ];
  }
  return * this;
}

// Оператор равенства
bool Trapezoid::operator == ( const Trapezoid & t ) const {
  for ( int i = 0; i < 4; i++ ) {
    if ( ! isDoublesEqual( x[ i ], t.x[ i ] ) || ! isDoublesEqual( y[ i ], t.y[ i ] ) )
      return false;
  }
  return true;
}

// Конструктор копирования
Trapezoid::Trapezoid( const Trapezoid & t ) {
  for ( int i = 0; i < 4; i++ ) {
    x[ i ] = t.x[ i ];
    y[ i ] = t.y[ i ];
  }
}

// Переопределение оператора new
void * Trapezoid::operator new ( size_t ) {
  return allocator->allocate();
}


// Переопределение оператора delete
void Trapezoid::operator delete( void * p ) {
  allocator->deallocate( p );
}

Allocator * Trapezoid::allocator;
