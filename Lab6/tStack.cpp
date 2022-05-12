#include<cstring>
#include<iostream>
#include"tStack.h"
#include"figure.h"

template<typename T>
TStack<T>::TStack( size_t blockLen ) {
  if ( blockLen == 0 ) {
    throw FigException( "TStack constructor with blockLen == 0" );
  }
  this->blockLen = blockLen;
  array = NULL;
  len = 0;
  capacity = 0;
}

template<typename T>
TStack<T>::~TStack() {
  if ( array != NULL )
    delete [] array;
}

template<typename T>
size_t TStack<T>::Length() const {
  return len;
}

template<typename T>
T & TStack<T>::top() {
  if ( len == 0 ) {
    throw FigException( "TStack::top for empty stack" );
  }
  return array[ len-1 ];
}

template<typename T>
void TStack<T>::push( T & t ) {
  if ( len == capacity ) {
    T * newArray = new T[ capacity + blockLen ];
    if ( newArray == NULL ) {
      throw FigException( "TStack::push - not enough memory" );
    }
    memcpy( newArray, array, sizeof( T ) * capacity );
    delete [] array;
    array = newArray;
    capacity += blockLen;
  }
  array[ len++ ] = t;
}

template<typename T>
void TStack<T>::pop() {
  if ( len == 0 ) {
    throw FigException( "TStack::pop for empty stack" );
  }
  len--;
}

template<typename T>
void TStack<T>::print() {
  cout << "Stack with " << len << " elements: ";
  for ( size_t i = 0; i < len; i++ )
    cout << array[ i ] << " ";
  cout << endl;
}

template class TStack<void *>;
