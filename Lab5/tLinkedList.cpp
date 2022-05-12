#include"tLinkedList.h"
#include"figure.h"
#include"trapezoid.h"
#include"rhombus.h"
#include"pentagon.h"

template<typename T> 
TNode<T>::TNode( const shared_ptr<T> t ) {
  this->t = make_shared<T>();
  this->t = t;
  next = NULL;
}

template<typename T>
TNode<T>::TNode( const T & t ) {
  this->t = make_shared<T>();
  this->t = shared_ptr<T> ( new T( t ) );
  next = NULL;
}

template<typename T> 
TNode<T> * TNode<T>::getNext() {
  return next;
}

template<typename T> 
void TNode<T>::setNext( TNode<T> * newNext ) {
  next = newNext;
}

template<typename T>
shared_ptr<T> & TNode<T>::val() {
  return t;
}

template<typename T> 
TNode<T>::~TNode() { }

template<typename T>
TLinkedList<T>::TLinkedList() {
  first = NULL;
  len = 0;
}

template<typename T>
TLinkedList<T>::~TLinkedList() {
  Clear();
}

template<typename T>
size_t TLinkedList<T>::Length() const {
  return len;
}

template<typename T>
bool TLinkedList<T>::Empty() const {
  return len == 0;
}
  
template<typename T>
void TLinkedList<T>::Clear() {
  TNode<T> * tn = first;
  while ( tn != NULL ) {
    TNode<T> * next = tn->getNext();
    delete tn;
    tn = next;
  }
  len = 0;
  first = NULL;
}

template<typename T>
const shared_ptr<T> TLinkedList<T>::First() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::First: cannot return first element of empty list" );
  }
  return first->val();
}

template<typename T>
const shared_ptr<T> TLinkedList<T>::Last() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::First: cannot return last element of empty list" );
  }
  return GetItem( len - 1 );
}

template<typename T>
const shared_ptr<T> TLinkedList<T>::GetItem( size_t idx ) {
  if ( idx >= len ) {
    throw FigException( "TLinkedList::GetItem: cannot return nonexistent element of list" );
  }
  TNode<T> * tn = first;
  while ( idx-- > 0 ) {
    TNode<T> * next = tn->getNext();
    tn = next;
  }
  return tn->val();
}


template<typename T>
void TLinkedList<T>::InsertFirst( const shared_ptr<T> t ) {
  TNode<T> * newNode = new TNode<T>( t );
  newNode->setNext( first );
  first = newNode;
  len++;
}

template<typename T>
void TLinkedList<T>::InsertFirst( const T & t ) {
  TNode<T> * newNode = new TNode<T>( t );
  newNode->setNext( first );
  first = newNode;
  len++;
}

template<typename T>
void TLinkedList<T>::InsertLast( const shared_ptr<T> t ) {
  TNode<T> * newNode = new TNode<T>( t );
  if ( len == 0 ) {
    first = newNode;
    len++;
    return;
  }
  TNode<T> * tn = first;
  while ( tn->getNext() != NULL ) {
    TNode<T> * next = tn->getNext();
    tn = next;
  }
  tn->setNext( newNode );
  len++;
}

template<typename T>
void TLinkedList<T>::InsertLast( const T & t ) {
  TNode<T> * newNode = new TNode<T>( t );
  if ( len == 0 ) {
    first = newNode;
    len++;
    return;
  }
  TNode<T> * tn = first;
  while ( tn->getNext() != NULL ) {
    TNode<T> * next = tn->getNext();
    tn = next;
  }
  tn->setNext( newNode );
  len++;
}

template<typename T>
void TLinkedList<T>::RemoveFirst() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::RemoveFirst: cannot return first element of empty list" );
  }
  TNode<T> * newFirst = first->getNext();
  delete first;
  first = newFirst;
  len--;
}

template<typename T>
void TLinkedList<T>::RemoveLast() {
  if ( len == 0 ) {
    throw FigException( "TLinkedList::RemoveFirst: cannot return last element of empty list" );
  } else if ( len == 1 ) {
    delete first;
    first = NULL;
    len = 0;
    return;
  }
  TNode<T> * tn = first;
  while ( tn->getNext()->getNext() != NULL ) {
    TNode<T> * next = tn->getNext();
    tn = next;
  }
  delete tn->getNext();
  tn->setNext( NULL );
  len--;
}

template<typename T>
void TLinkedList<T>::Insert( const shared_ptr<T> t, size_t position ) {
  if ( position > len ) {
    throw FigException( "TLinkedList::Insert: cannot add new element to too short list" );
  }
  if ( position == 0 ) {
    InsertFirst( t );
    return;
  } else if ( position == len ) {
    InsertLast( t );
    return;
  }
  TNode<T> * tn = first;
  while ( position -- > 1 ) {
    TNode<T> * next = tn->getNext();
    tn = next;
  }
  TNode<T> * next = tn->getNext();
  TNode<T> * newNode = new TNode<T>( t );
  newNode->setNext( next );
  tn->setNext( newNode );
  len++;
}

template<typename T>
void TLinkedList<T>::Insert( const T & t, size_t position ) {
  if ( position > len ) {
    throw FigException( "TLinkedList::Insert: cannot add new element to too short list" );
  }
  if ( position == 0 ) {
    InsertFirst( t );
    return;
  } else if ( position == len ) {
    InsertLast( t );
    return;
  }
  TNode<T> * tn = first;
  while ( position -- > 1 ) {
    TNode<T> * next = tn->getNext();
    tn = next;
  }
  TNode<T> * next = tn->getNext();
  TNode<T> * newNode = new TNode<T>( t );
  newNode->setNext( next );
  tn->setNext( newNode );
  len++;
}
  
template<typename T>
void TLinkedList<T>::Remove( size_t position ) {
  if ( position + 1 > len ) {
    throw FigException( "TLinkedList::Remove: cannot remove nonexistent element" );
  }
  if ( position == 0 ) {
    RemoveFirst();
    return;
  } else if ( position == len-1 ) {
    RemoveLast();
    return;
  }
  TNode<T> * tn = first;
  while ( position -- > 1 ) {
    TNode<T> * next = tn->getNext();
    tn = next;
  }
  TNode<T> * next = tn->getNext();
  tn->setNext( tn->getNext()->getNext() );
  delete next;
  len--;
}

template<typename T>
TLinkedList<T>::TLinkedList( const TLinkedList<T> & other ) {
  TLinkedList<T> * o = const_cast<TLinkedList<T>*> ( & other );
  first = NULL;
  len = 0;
  if ( other.Length() == 0 ) 
    return;
  size_t oLen = other.Length();
  for ( size_t i = 0; i < oLen; i++ ) {
    InsertLast( o->GetItem( i ) );
  }
}
  
template<typename T>
std::ostream & operator << ( std::ostream & os, const TLinkedList<T> & list ) {
  TNode<T> * tn = list.first;
  size_t len = list.Length();
  if ( len == 0 )
    return os;
  os << tn->val()->Area();
  tn = tn->getNext();
  while ( tn != NULL ) {
    os << " -> " << tn->val()->Area();
    tn = tn->getNext();
  }
  return os;
}

// Функция перехода к idx-тому узлу котрейнера
template<typename T>
TNode<T> * TLinkedList<T>::Iterator::getNode( TNode<T> * first, size_t len, size_t idx ) {
  if ( idx >= len ) {
    throw FigException( "Bad index in Iterator constructor" );
  }
  TNode<T> * cur = first;
  while ( idx-- > 0 ) {
    cur = cur->getNext();
  }
  return cur;
}

// Закрытый конструктор итератора
template<typename T>
TLinkedList<T>::Iterator::Iterator( TNode<T> * first, size_t len, size_t idx ) {
  curIdx = idx;
  curLen = len;
  curNode = getNode( first, len, idx );
}

// Операция разыменования возвращает ссылку на хранимый в контейнере объект
template<typename T>
shared_ptr<T> & TLinkedList<T>::Iterator::operator * () const { 
  return curNode->val(); 
}

// Операция получения указателя на хранимый в контейнере объект
template<typename T>
shared_ptr<T> TLinkedList<T>::Iterator::operator -> () { 
  return curNode->val();
}
    
// Префиксная операция инкрементации итератора ( ++it )
template<typename T>
typename TLinkedList<T>::Iterator & 
TLinkedList<T>::Iterator::operator ++ () {
  if ( curIdx >= curLen ) {
    return * this;
  }
  curIdx++;
  curNode = curNode->getNext();
  return * this; 
}

// Постфиксная операция инкрементации итератора ( it++ ), возвращает копию
// исходного итератора, передвигая исходный итератор на одну позицию вперед
template<typename T>
typename TLinkedList<T>::Iterator  
TLinkedList<T>::Iterator::operator ++ ( int ) {
  TLinkedList<T>::Iterator tmp = * this;
  ++ ( * this );
  return tmp;
}
    
// Операции сравнения итераторов
template<typename T>
bool operator == ( const typename TLinkedList<T>::Iterator & a, 
                   const typename TLinkedList<T>::Iterator & b ) {
  return a.curIdx == b.curIdx;
}

template<typename T>
bool operator != ( const typename TLinkedList<T>::Iterator & a, 
                   const typename TLinkedList<T>::Iterator & b ) {
  return a.curIdx != b.curIdx;
}

template class TLinkedList<Trapezoid>;
template std::ostream & operator << <Trapezoid> ( std::ostream & os, const TLinkedList<Trapezoid> & list );
template class TLinkedList<Pentagon>;
template std::ostream & operator << <Pentagon> ( std::ostream & os, const TLinkedList<Pentagon> & list );
template class TLinkedList<Rhombus>;
template std::ostream & operator << <Rhombus> ( std::ostream & os, const TLinkedList<Rhombus> & list );
