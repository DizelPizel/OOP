#include<iostream>
#include<cstdlib>
#include<vector>
#include"figure.h"
#include"rhombus.h"
#include"trapezoid.h"
#include"pentagon.h"


// Используется по умолчанию пространство имен "std"
using namespace std;


int main() {

  vector<Figure*> v;

  int n;
  cout << "Number of figures n=>";
  cin >> n;
  if ( n <= 0 ) {
    cout << "n must be natural" << endl;
    exit( 1 );
  }

  // Код, в котором может возникнуть исключение
  try {
    // Ввод фигур
    for ( int i = 0; i < n; i++ ) {
      int choice;
      cout << "Enter: 1) rhombus; 2) trapezoid; 3) pentagon. Your choice =>";
      cin >> choice;
      switch ( choice ) {
        case 1:
	  cout << "Enter coordinates of rhombus: " << endl;
  	  v.push_back( new Rhombus );
  	  break;
        case 2:
  	  cout << "Enter coordinates of trapezoid: " << endl;
  	  v.push_back( new Trapezoid );
  	  break;
        case 3:
  	  cout << "Enter coordinates of pentagon: " << endl;
  	  v.push_back( new Pentagon );
  	  break;
        default:
	  cout << "Bad choice" << endl;
	  break;
      }
    }

    // Распечатка данных фигур
    for ( size_t i = 0; i < v.size(); i++ ) {
      v[ i ]->Print( std::cout );
    }

    // Удаление фигур
    for ( size_t i = 0; i < v.size(); i++ )
      delete v[ i ];

  // Отлов исключения
  } catch ( FigException e ) {
    cout << "Caught an exception: " << e.message << endl;
  }

  return 0;
}
