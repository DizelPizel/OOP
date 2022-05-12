#include<iostream>
#include<cstdlib>
#include<sstream>
#include"figure.h"
#include"trapezoid.h"
#include"tLinkedList.h"


// »спользуетс€ по умолчанию пространство имен "std"
using namespace std;


int main() {

  int n;
  cout << "Number of figures n=>";
  cin >> n;
  if ( n <= 0 ) {
    cout << "n must be natural" << endl;
    exit( 1 );
  }

  try {
    TLinkedList list;

    for ( int i = 0; i < n; i++ ) {
      cout << "Enter trapezoid =>"; 
      Trapezoid newTrapezoid;
      cin >> newTrapezoid;
      if ( cin.fail() ) {
	cout << "Bad input" << endl;
	exit( 1 );
      }
      list.InsertLast( newTrapezoid );
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

  return 0;
}
