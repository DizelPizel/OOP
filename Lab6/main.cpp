#include<iostream>
#include<cstdlib>
#include<sstream>
#include<ctime>
#include"figure.h"
#include"trapezoid.h"
#include"rhombus.h"
#include"pentagon.h"
#include"tLinkedList.h"
//#include"tStack.h"
#include"allocator.h"


// Используется по умолчанию пространство имен "std"
using namespace std;

size_t getMax( size_t a, size_t b ) {
  return a > b ? a : b;
}

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

  // Вычисляем максимальный размер объекта фигуры
  size_t s1 = sizeof( Trapezoid );
  size_t s2 = sizeof( Pentagon );
  size_t s3 = sizeof( Rhombus );
  size_t s = getMax( getMax( s1, s2 ), s3 );

  // Создаем аллокатор для внутреннего выделения памяти блоками по 10 кусочков
  // (каждый кусочек может хранить одну фигуру любого типа)
  Allocator * a = new Allocator( 10, s );
  // Назначаем этот аллокатор всем фигурам
  Trapezoid::setAllocator( a );
  Pentagon::setAllocator( a );
  Rhombus::setAllocator( a );

  // Тестирование списков с элементами всех трех типов
  testList<Trapezoid> ( ( char * ) "Trapezoid" );
  testList<Pentagon> ( ( char * ) "Pentagon" );
  testList<Rhombus> ( ( char * ) "Rhombus" );

  // Удаляем аллокатор
  delete a;

  return 0;
}
