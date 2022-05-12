#include<iostream>
#include<cstdlib>
#include<sstream>
#include"figure.h"
#include"trapezoid.h"
#include"rhombus.h"
#include"pentagon.h"
#include"tLinkedList.h"


// Используется по умолчанию пространство имен "std"
using namespace std;

template<typename T>
void testList( char * str ) {
  int n;
  cout << "Number of figures of type '" << str << "' n=>";
  cin >> n;
  if ( n <= 0 ) {
    cout << "n must be natural" << endl;
    exit( 1 );
  }
  try {
    TLinkedList<T> list;

    for ( int i = 0; i < n; i++ ) {
      cout << "Enter " << str << " =>"; 
      T newT;
      cin >> newT;
      if ( cin.fail() ) {
	cout << "Bad input" << endl;
	exit( 1 );
      }
      list.InsertLast( newT );
    }

    for ( int i = 0; i < n; i++ ) {
      cout << "List: " << list << endl;
      cout << "Length =>" << list.Length() << endl;

      cout << "Remove element with index =>";
      size_t idx;
      cin >> idx;
      if ( cin.fail() ) {
	cout << "Bad input" << endl;
	exit( 1 );
      }
      if ( idx + 1 > list.Length() ) {
	cout << "Too big index" << endl;
	continue;
      }
      list.Remove( idx );
    }

    cout << "List: " << list << endl;
    cout << "Length =>" << list.Length() << endl;

  } catch ( FigException e ) {
    cout << "Caught an exception: " << e.message << endl;
  }
}

int main() {

  // Тестирование списков с элементами всех трех типов
  testList<Trapezoid> ( ( char * ) "Trapezoid" );
  testList<Rhombus> ( ( char * ) "Rhombus" );
  testList<Pentagon> ( ( char * ) "Pentagon" );

  return 0;
}
