#include<iomanip>
#include"rhombus.h"

Rhombus::Rhombus() : Figure() {
  x[ 0 ] = 0.0;
  x[ 1 ] = 0.0;
  x[ 2 ] = 1.0;
  x[ 3 ] = 1.0;
  y[ 0 ] = 0.0;
  y[ 1 ] = 1.0;
  y[ 2 ] = 1.0;
  y[ 3 ] = 0.0;
}

/*
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
*/

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

std::istream & operator >> ( std::istream & in, Rhombus & t ) {
  double _x[ 4 ];
  double _y[ 4 ];
  for ( int i = 0; i < 4; i++ ) {
    in >> _x[ i ];
    in >> _y[ i ];
  }
  if ( in.fail() ) {
    return in;
  }

  // Проверка математической корректности ромба
  // Проверка равенства сторон ромба
  double len0 = getLength( _x[ 0 ], _y[ 0 ], _x[ 1 ], _y[ 1 ] );
  double len1 = getLength( _x[ 1 ], _y[ 1 ], _x[ 2 ], _y[ 2 ] );
  double len2 = getLength( _x[ 2 ], _y[ 2 ], _x[ 3 ], _y[ 3 ] );
  double len3 = getLength( _x[ 3 ], _y[ 3 ], _x[ 0 ], _y[ 0 ] );
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
  if ( ( isDoublesEqual( _x[ 0 ], _x[ 2 ] ) && isDoublesEqual( _y[ 0 ], _y[ 2 ] ) ) ||
       ( isDoublesEqual( _x[ 1 ], _x[ 3 ] ) && isDoublesEqual( _y[ 1 ], _y[ 3 ] ) ) ) {
    throw FigException( "Error in Rhombus constructor: rhomb with coincided vertexes" );
  }

  // Все проверки выполнены. Копируем новые координаты
  for ( int i = 0; i < 4; i++ ) {
    t.x[ i ] = _x[ i ];
    t.y[ i ] = _y[ i ];
  }

  return in;
}

std::ostream & operator << ( std::ostream & out, const Rhombus & t ) {
  out << "Rhombus: ";
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

Rhombus & Rhombus::operator = ( const Rhombus & t ) {
  for ( int i = 0; i < 4; i++ ) {
    x[ i ] = t.x[ i ];
    y[ i ] = t.y[ i ];
  }
  return * this;
}

// Оператор равенства
bool Rhombus::operator == ( const Rhombus & t ) const {
  for ( int i = 0; i < 4; i++ ) {
    if ( ! isDoublesEqual( x[ i ], t.x[ i ] ) || ! isDoublesEqual( y[ i ], t.y[ i ] ) )
      return false;
  }
  return true;
}


// Конструктор копирования
Rhombus::Rhombus( const Rhombus & t ) {
  for ( int i = 0; i < 4; i++ ) {
    x[ i ] = t.x[ i ];
    y[ i ] = t.y[ i ];
  }
}

