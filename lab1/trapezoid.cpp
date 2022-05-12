#include<iomanip>
#include"trapezoid.h"

Trapezoid::Trapezoid() : Figure() {
  for ( int i = 0; i < 4; i++ ) {
    cin >> x[ i ];
    cin >> y[ i ];
  }
  if ( cin.fail() ) {
    throw FigException( "Bad coordinate values in Trapezoid constructor" );
  }
  // Проверка математической корректности трапеции
  // Стороны трапеции
  double len0 = getLength( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ] );
  double len1 = getLength( x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ] );
  double len2 = getLength( x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ] );
  double len3 = getLength( x[ 3 ], y[ 3 ], x[ 0 ], y[ 0 ] );

  // Если есть сторона нулевой длины
  if ( isDoubleZero( len0 ) ||
       isDoubleZero( len1 ) ||
       isDoubleZero( len2 ) ||
       isDoubleZero( len3 ) ) {
    throw FigException( "Error in Trapezoid constructor: trapezoid with zero side length" );
  }

  // Если обе пары противоположных сторон не являются параллельными
  if ( ! isVectorsParallel( x[ 0 ]-x[ 1 ], y[ 0 ]-y[ 1 ], x[ 3 ]-x[ 2 ], y[ 3 ]-y[ 2 ] ) &&
       ! isVectorsParallel( x[ 1 ]-x[ 2 ], y[ 1 ]-y[ 2 ], x[ 3 ]-x[ 0 ], y[ 3 ]-y[ 0 ] ) ) {
    throw FigException( "Error in Trapezoid constructor: trapeziod without parallel sides" );
  }
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
