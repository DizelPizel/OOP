#include<iomanip>
#include"pentagon.h"

Pentagon::Pentagon() : Figure() {
  x[ 0 ] = 0.0;
  x[ 1 ] = 0.0;
  x[ 2 ] = 1.0;
  x[ 3 ] = 2.0;
  x[ 4 ] = 2.0;
  y[ 0 ] = 0.0;
  y[ 1 ] = 1.0;
  y[ 2 ] = 0.5;
  y[ 3 ] = 1.0;
  y[ 4 ] = 0.0;
}

size_t Pentagon::VertexesNumber() const {
  return 5;
}

double Pentagon::Area() const {
  // Выражение площади математически корректного пятиугольника через 
  // ориентированные площади трех треугольников
  return fabs( getOrArea( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ] ) +
               getOrArea( x[ 0 ], y[ 0 ], x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ] ) +
               getOrArea( x[ 0 ], y[ 0 ], x[ 3 ], y[ 3 ], x[ 4 ], y[ 4 ] ) );
}

void Pentagon::Print( std::ostream & os ) const {
  os << "Pentagon: ";
  os << showpos << fixed;
  for ( int i = 0; i < 5; i++ ) {
    os << "(" << setprecision( 1 ) << x[ i ] <<
            ", " << setprecision( 1 ) << y[ i ] <<
	    ")";
    if ( i < 4 )
      os << " ";
  }
  os << "\n";
  os << noshowpos;
} 

Pentagon::~Pentagon() { }

bool Pentagon::operator == ( const Pentagon & t ) const {
  for ( int i = 0; i < 5; i++ ) {
    if ( ! isDoublesEqual( x[ i ], t.x[ i ] ) || ! isDoublesEqual( y[ i ], t.y[ i ] ) )
      return false;
  }
  return true;
}

std::ostream & operator << ( std::ostream & out, const Pentagon & t ) {
  out << "Pentagon: ";
  out << showpos << fixed;
  for ( int i = 0; i < 5; i++ ) {
    out << "(" << setprecision( 1 ) << t.x[ i ] <<
            ", " << setprecision( 1 ) << t.y[ i ] <<
            ")";
    if ( i < 4 )
      out << " ";
  }
  out << "\n";
  out << noshowpos;
  return out;
}

std::istream & operator >> ( std::istream & in, Pentagon & t ) {
  double _x[ 5 ];
  double _y[ 5 ];
  for ( int i = 0; i < 5; i++ ) {
    in >> _x[ i ];
    in >> _y[ i ];
  }
  if ( in.fail() ) {
    return in;
  }

  // Проверка математической корректности пятиугольника
  // Проверка равенства нулю сторон пятиугольника
  double len0 = getLength( _x[ 0 ], _y[ 0 ], _x[ 1 ], _y[ 1 ] );
  double len1 = getLength( _x[ 1 ], _y[ 1 ], _x[ 2 ], _y[ 2 ] );
  double len2 = getLength( _x[ 2 ], _y[ 2 ], _x[ 3 ], _y[ 3 ] );
  double len3 = getLength( _x[ 3 ], _y[ 3 ], _x[ 4 ], _y[ 4 ] );
  double len4 = getLength( _x[ 4 ], _y[ 4 ], _x[ 0 ], _y[ 0 ] );
  if ( isDoubleZero( len0 ) ||
       isDoubleZero( len1 ) ||
       isDoubleZero( len2 ) ||
       isDoubleZero( len3 ) ||
       isDoubleZero( len4 ) ) {
    throw FigException( "Error in Pentagon constructor: pentagon with zero side length" );
  }
  // Проверка непараллельности смежных отрезков
  if ( isVectorsParallel( _x[0]-_x[1], _y[0]-_y[1], _x[2]-_x[1], _y[2]-_y[1] ) ||
       isVectorsParallel( _x[1]-_x[2], _y[1]-_y[2], _x[3]-_x[2], _y[3]-_y[2] ) ||
       isVectorsParallel( _x[2]-_x[3], _y[2]-_y[3], _x[4]-_x[3], _y[4]-_y[3] ) ||
       isVectorsParallel( _x[3]-_x[4], _y[3]-_y[4], _x[0]-_x[4], _y[0]-_y[4] ) ||
       isVectorsParallel( _x[4]-_x[0], _y[4]-_y[0], _x[1]-_x[0], _y[1]-_y[0] ) ) {
    throw FigException( "Error in Pentagon constructor: pentagon with parallel adjacent sides" );
  }
  // Проверка переечения несмежных отрезков
  if ( isIntersect( _x[ 0 ], _y[ 0 ], _x[ 1 ], _y[ 1 ], _x[ 2 ], _y[ 2 ], _x[ 3 ], _y[ 3 ] ) ||
       isIntersect( _x[ 0 ], _y[ 0 ], _x[ 1 ], _y[ 1 ], _x[ 3 ], _y[ 3 ], _x[ 4 ], _y[ 4 ] ) ||
       isIntersect( _x[ 1 ], _y[ 1 ], _x[ 2 ], _y[ 2 ], _x[ 3 ], _y[ 3 ], _x[ 4 ], _y[ 4 ] ) ||
       isIntersect( _x[ 1 ], _y[ 1 ], _x[ 2 ], _y[ 2 ], _x[ 0 ], _y[ 0 ], _x[ 4 ], _y[ 4 ] ) ||
       isIntersect( _x[ 2 ], _y[ 2 ], _x[ 3 ], _y[ 3 ], _x[ 0 ], _y[ 0 ], _x[ 4 ], _y[ 4 ] ) ) {
    throw FigException( "Error in Pentagon constructor: pentagon with pair nonadjacent sides interect" );
  }

  // Все проверки выполнены. Копируем новые координаты
  for ( int i = 0; i < 5; i++ ) {
    t.x[ i ] = _x[ i ];
    t.y[ i ] = _y[ i ];
  }

  return in;
}

Pentagon::Pentagon( const Pentagon & t ) : Figure() {
  for ( int i = 0; i < 5; i++ ) {
    x[ i ] = t.x[ i ];
    y[ i ] = t.y[ i ];
  }
}

