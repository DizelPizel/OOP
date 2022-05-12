#include<iomanip>
#include"pentagon.h"

Pentagon::Pentagon() : Figure() {
  for ( int i = 0; i < 5; i++ ) {
    cin >> x[ i ];
    cin >> y[ i ];
  }
  if ( cin.fail() ) {
    throw FigException( "Bad coordinate values in Pentagon constructor" );
  }
  // Проверка математической корректности пятиугольника
  // Проверка равенства нулю сторон пятиугольника
  double len0 = getLength( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ] );
  double len1 = getLength( x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ] );
  double len2 = getLength( x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ] );
  double len3 = getLength( x[ 3 ], y[ 3 ], x[ 4 ], y[ 4 ] );
  double len4 = getLength( x[ 4 ], y[ 4 ], x[ 0 ], y[ 0 ] );
  if ( isDoubleZero( len0 ) ||
       isDoubleZero( len1 ) ||
       isDoubleZero( len2 ) ||
       isDoubleZero( len3 ) ||
       isDoubleZero( len4 ) ) {
    throw FigException( "Error in Pentagon constructor: pentagon with zero side length" );
  }
  // Проверка непараллельности смежных отрезков
  if ( isVectorsParallel( x[0]-x[1], y[0]-y[1], x[2]-x[1], y[2]-y[1] ) ||
       isVectorsParallel( x[1]-x[2], y[1]-y[2], x[3]-x[2], y[3]-y[2] ) ||
       isVectorsParallel( x[2]-x[3], y[2]-y[3], x[4]-x[3], y[4]-y[3] ) ||
       isVectorsParallel( x[3]-x[4], y[3]-y[4], x[0]-x[4], y[0]-y[4] ) ||
       isVectorsParallel( x[4]-x[0], y[4]-y[0], x[1]-x[0], y[1]-y[0] ) ) {
    throw FigException( "Error in Pentagon constructor: pentagon with parallel adjacent sides" );
  }
  // Проверка переечения несмежных отрезков
  if ( isIntersect( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ] ) ||
       isIntersect( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ], x[ 3 ], y[ 3 ], x[ 4 ], y[ 4 ] ) ||
       isIntersect( x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ], x[ 4 ], y[ 4 ] ) ||
       isIntersect( x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ], x[ 0 ], y[ 0 ], x[ 4 ], y[ 4 ] ) ||
       isIntersect( x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ], x[ 0 ], y[ 0 ], x[ 4 ], y[ 4 ] ) ) {
    throw FigException( "Error in Pentagon constructor: pentagon with pair nonadjacent sides interect" );
  }
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
