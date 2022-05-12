#include<iomanip>
#include"rhombus.h"

Rhombus::Rhombus() : Figure() {
  for ( int i = 0; i < 4; i++ ) {
    cin >> x[ i ];
    cin >> y[ i ];
  }
  if ( cin.fail() ) {
    throw FigException( "Bad coordinate values in Rhombus constructor" );
  }
  // Проверка математической корректности ромба
  // Проверка равенства сторон ромба
  double len0 = getLength( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ] );
  double len1 = getLength( x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ] );
  double len2 = getLength( x[ 2 ], y[ 2 ], x[ 3 ], y[ 3 ] );
  double len3 = getLength( x[ 3 ], y[ 3 ], x[ 0 ], y[ 0 ] );
  if ( ! isDoublesEqual( len0, len1 ) ||
       ! isDoublesEqual( len1, len2 ) ||
       ! isDoublesEqual( len2, len3 ) ) {
    throw FigException( "Error in Rhombus constructor: rhomb with different side lengths" );
  }
  // Проверка равенства нулю сторон ромба
  if ( isDoubleZero( len0 ) ) {
    throw FigException( "Error in Rhombus constructor: rhomb with zero side lengths" );
  }
  // Проверка несовпадаения противоположных вершин
  if ( ( isDoublesEqual( x[ 0 ], x[ 2 ] ) && isDoublesEqual( y[ 0 ], y[ 2 ] ) ) ||
       ( isDoublesEqual( x[ 1 ], x[ 3 ] ) && isDoublesEqual( y[ 1 ], y[ 3 ] ) ) ) {
    throw FigException( "Error in Rhombus constructor: rhomb with coincided vertexes" );
  }
}

size_t Rhombus::VertexesNumber() const {
  return 4;
}

double Rhombus::Area() const {
  return fabs( getOrArea( x[ 0 ], y[ 0 ], x[ 1 ], y[ 1 ], x[ 2 ], y[ 2 ] ) ) * 2.0;
}

void Rhombus::Print( std::ostream & os ) const {
  os << "Rhombus: ";
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

Rhombus::~Rhombus() { }
